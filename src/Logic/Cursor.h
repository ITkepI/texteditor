//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_CURSOR_H
#define TEXTEDITOR_CURSOR_H

#include "FileViewer.h"

// Структура, которая описывает курсор.
// Просто хранит номер строки в файле, номер символа в строке и ссылку на файл
struct Cursor {

    Cursor() = default;

    Cursor(size_t char_number_in_line, size_t line_number);

    /*
     * -1 - end of the line
     */
    size_t char_number_in_line{};
    size_t line_number{};
};

using CursorRange = std::pair<Cursor, Cursor>;

Cursor GetTrueCursor(Cursor const &cursor, FileViewer const &file_viewer);

#endif //TEXTEDITOR_CURSOR_H
