//
// Created by Linux Oid on 16/11/2019.
//

#include "CursorAction.h"

void GoUp::handle(Cursor &c) {
    if (c.line_number > 0)
        --c.line_number;
}

void GoDown::handle(Cursor &c) {
    if (c.line_number < c.file_mutator.lines_quantity() - 1)
        ++c.line_number;
}

void GoLeft::handle(Cursor &c) {
    if (c.char_number_in_line > 0)
        --c.char_number_in_line;
}

void GoRight::handle(Cursor &c) {
    if (c.char_number_in_line + 1 < c.file_mutator.line_size(c.line_number))
        ++c.char_number_in_line;
}
