//
// Created by Linux Oid on 16/11/2019.
//

#include "Printer.h"

Printer::Printer(WINDOW *window) : window_(window) {
    init();
}

void Printer::Print(const FileMutator &file_mutator) {
    Print(file_mutator, 0);
}

void Printer::Print(FileMutator const &file_mutator, size_t begin) {
    Print(file_mutator, begin, file_mutator.lines_quantity() - begin);
}

void Printer::Print(FileMutator const &file_mutator, size_t begin, size_t size) {
    wclear(window_);
    size_t count = 0;
    for (size_t i = begin; count < size && i < file_mutator.lines_quantity(); ++i, ++count) {
        wprintw(window_, "%s\n", file_mutator.line(i).c_str());
    }
}

void Printer::Print(FileMutator const &file_mutator, size_t begin, size_t size, Cursor const &cursor) {
    werase(window_);
    size_t count = 0;
    for (size_t i = begin;
         i < cursor.line_number && count < size && i < file_mutator.lines_quantity(); ++i, ++count) {
        wprintw(window_, "%s\n", file_mutator.line(i).c_str());
    }

    Line line_under_cursor = cursor.file_mutator.line(cursor.line_number);
    for (int j = 0; count < size && j < line_under_cursor.size(); ++j) {
        waddch(window_, static_cast<chtype>(line_under_cursor.at(j)) |
                        (j == cursor.char_number_in_line ? COLOR_PAIR(1) : 0));
    }
    ++count;
    if (line_under_cursor.empty())
        waddch(window_, ' ' | COLOR_PAIR(1));
    waddch(window_, '\n');

    for (size_t k = cursor.line_number + 1; count < size && k < file_mutator.lines_quantity(); ++k, ++count) {
        wprintw(window_, "%s\n", file_mutator.line(k).c_str());
    }
    wrefresh(window_);
}
