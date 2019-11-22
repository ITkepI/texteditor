//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_PRINTER_H
#define TEXTEDITOR_PRINTER_H

#include "../Logic/FileMutator.h"
#include "../Logic/Cursor.h"
#include "Colors.h"
#include <ncurses.h>

/*
 * Класс для отрисовки состояний файла.
 * Предполагаются изменения.
 */
class Printer {
public:
    explicit Printer(WINDOW *window);

    void Print(FileMutator const &, size_t, size_t, Cursor const &);

    void Print(FileMutator const &, size_t, size_t);

    void Print(FileMutator const &, size_t);

    void Print(FileMutator const &);

private:
    WINDOW *window_;
};


#endif //TEXTEDITOR_PRINTER_H