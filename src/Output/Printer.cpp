//
// Created by Linux Oid on 16/11/2019.
//

#include "Printer.h"

Printer::Printer(WINDOW *window) : window_(window) {
    init();
}

void Printer::Print(const FileViewer &file_mutator) {
    Print(file_mutator, 0);
}

void Printer::Print(FileViewer const &file_mutator, size_t begin) {
    Print(file_mutator, begin, file_mutator.lines_quantity() - begin);
}

void Printer::Print(FileViewer const &file_mutator, size_t begin, size_t size) {
    wclear(window_);
    size_t count = 0;
    for (size_t i = begin; count < size && i < file_mutator.lines_quantity(); ++i, ++count) {
        wprintw(window_, "%s\n", file_mutator.line(i).c_str());
    }
}

int Printer::Print(WINDOW *win, FileViewer::const_iterator beg, FileViewer::const_iterator end, Cursor const &cursor,
                   size_t windows_size) {
    int count_line = 0;
    while (getcury(win) + 1 < windows_size && beg != end) {
        if (count_line == cursor.line_number) {
            wprintw(win, "%d\t", getcury(win) + 1);
            for (FileViewer::const_iterator::value_type::size_type i = 0; i < beg->size(); ++i)
                waddch(win, (*beg)[i] | (i == cursor.char_number_in_line ||
                                         (cursor.char_number_in_line == -1 && i + 1 == beg->size()) ? COLOR_PAIR(1)
                                                                                                    : 0));
            if (beg->empty())
                waddch(win, ' ' | COLOR_PAIR(1));
            waddch(win, '\n');
        } else
            wprintw(win, "%d\t%s\n", getcury(win) + 1, beg->c_str());
        ++beg;
        ++count_line;
    }

    return getcury(win);
}
