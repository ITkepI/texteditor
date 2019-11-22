//
// Created by Linux Oid on 16/11/2019.
//

#include "Cursor.h"

Cursor::Cursor(const FileMutator &fileMutator) : file_mutator(fileMutator) {}

Cursor::Cursor(size_t char_number_in_line, size_t line_number, const FileMutator &file_mutator) : char_number_in_line(
        char_number_in_line), line_number(line_number), file_mutator(file_mutator) {}

Cursor GetTrueCursor(Cursor const &cursor) {
    auto line_size = cursor.file_mutator.line_size(cursor.line_number);
    return Cursor(cursor.char_number_in_line == -1 ||
                  (cursor.char_number_in_line > line_size && line_size > 0)
                  ? line_size - 1 : cursor.char_number_in_line,
                  cursor.line_number,
                  cursor.file_mutator);
}
