//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_WINDOW_H
#define TEXTEDITOR_WINDOW_H

#include "Printer.h"
#include "Cursor.h"
#include <ncurses.h>

/*
 * Класс для работы с выводом на окно.
 * Если кто-нибудь другой займется выводом можно спокойно менять эту хуйню.
 */
class Window {
public:
    explicit Window(WINDOW *);

    Window();

    void Print(FileMutator const &);

    void Print(FileMutator const &, Cursor const &);

    void MoveStartDown(size_t a);

    void MoveStartUp(size_t a);

    [[nodiscard]] size_t start();

    [[nodiscard]] WINDOW *window();

    [[nodiscard]] int MaxX();

    [[nodiscard]] int MaxY();

private:
    size_t window_start_ = 0;
    Printer printer_;
    WINDOW *window_;
};


#endif //TEXTEDITOR_WINDOW_H
