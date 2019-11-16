//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_CURSOR_H
#define TEXTEDITOR_CURSOR_H

#include "FileMutator.h"

struct Cursor {
    explicit Cursor(const FileMutator &fileMutator);

    Cursor(size_t char_number_in_line, size_t line_number, const FileMutator &file_mutator);

    /*
     * -1 - end of the line
     */
    size_t char_number_in_line{};
    size_t line_number{};
    FileMutator file_mutator;
};

using CursorRange = std::pair<Cursor, Cursor>;

Cursor GetTrueCursor(Cursor const &cursor);

#endif //TEXTEDITOR_CURSOR_H
