//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_WINDOW_H
#define TEXTEDITOR_WINDOW_H

#include "Printer.h"
#include "Cursor.h"
#include <ncurses.h>

class Window {
public:
    explicit Window(WINDOW *);

    Window();

    void Print(FileMutator const &);

    size_t start();

    void MoveStartDown(size_t a);

    WINDOW *window();

    int MaxX();

    int MaxY();

private:
    size_t window_start_{};
    Printer printer_;
    WINDOW *window_;
};


#endif //TEXTEDITOR_WINDOW_H
