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
    std::ifstream ifstream(args[1]);
    Controller controller((FileMutator(ifstream)));

    halfdelay(1);
    int c;
    while ((c = wgetch(window.window())) != 'q') {
        controller.HandleInput(c);
        window.Print(controller.file_mutator());
        Cursor cursor = GetTrueCursor(controller.cursor());
        cursor.line_number -= window.start();
        if (cursor.line_number >= window.MaxY()) {
            window.MoveStartDown(cursor.line_number - window.MaxY() + 1);
            cursor.line_number = window.MaxY() - 1;
        }
        wmove(window.window(), cursor.line_number, cursor.char_number_in_line);
    }
    endwin();
    return 0;
}