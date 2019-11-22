//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_PRINTER_H
#define TEXTEDITOR_PRINTER_H

#include "../Logic/FileViewer.h"
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

    void Print(FileViewer const &, size_t, size_t);

    void Print(FileViewer const &, size_t);

    void Print(FileViewer const &);

    int Print(WINDOW *win, FileViewer::const_iterator beg, FileViewer::const_iterator end, Cursor const &cursor,
              size_t windows_size);

private:
    WINDOW *window_;
};


#endif //TEXTEDITOR_PRINTER_H
