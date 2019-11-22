//
// Created by Linux Oid on 16/11/2019.
//

#include "CursorAction.h"

void GoUp::handle(Cursor &c, FileBuffer const &fb) {
    if (c.line_number > 0)
        --c.line_number;
}

void GoDown::handle(Cursor &c, FileBuffer const &fb) {
    if (c.line_number + 1 < fb.size())
        ++c.line_number;
}

void GoLeft::handle(Cursor &c, FileBuffer const &fb) {
    if (c.char_number_in_line > 0)
        --c.char_number_in_line;
}

void GoRight::handle(Cursor &c, FileBuffer const &fb) {
    if (c.char_number_in_line + 1 < fb[c.line_number].size())
        ++c.char_number_in_line;
}
