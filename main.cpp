#include <iostream>
#include <vector>
#include <fstream>
#include "Printer.h"
#include "Controller.h"
#include "FileMutator.h"
#include "Window.h"

std::ostream &operator<<(std::ostream &os, Cursor const &c) {
    os << "X: " << c.char_number_in_line << " Y: " << c.line_number << std::endl;
    return os;
}

int main(int argc, char *args[]) {
    Window window(initscr());

    if (!has_colors()) {
        endwin();
        std::cerr << "Error — no color support on this terminal";
        exit(1);
    }

    start_color();
    halfdelay(1);
    noecho();
    init();
    curs_set(0);
    init_pair(1, COLOR_WHITE, COLOR_GREY);

    std::ifstream ifstream(args[1]);
    Controller controller((FileMutator(ifstream)));

    int c;
    while ((c = wgetch(window.window())) != 'q') {
        Cursor cursor = GetTrueCursor(controller.cursor());
        window.Print(controller.file_mutator(), cursor);
        if (cursor.line_number + 1 - window.start() >= window.MaxY()) {
            window.MoveStartDown(1);
//            cursor.line_number = window.MaxY() - 1;
        } else if (cursor.line_number < window.start()) {
            window.MoveStartUp(window.start() - cursor.line_number);
        }
        controller.HandleInput(c);
    }
    endwin();
    return 0;
}