//
// Created by Linux Oid on 16/11/2019.
//

#include "Printer.h"

Printer::Printer(WINDOW *window) : window_(window) {}

void Printer::Print(const FileMutator &file_mutator) {
    Print(file_mutator, 0);
}

void Printer::Print(FileMutator const &file_mutator, size_t begin) {
    for (size_t i = begin; i < file_mutator.lines_quantity(); ++i) {
        wprintw(window_, "%s\n", file_mutator.line(i).c_str());
    }
}

void Printer::Print(FileMutator const &file_mutator, size_t begin, size_t size) {
    size_t count = 0;
    for (size_t i = begin; count < size && i < file_mutator.lines_quantity(); ++i, ++count) {
        wprintw(window_, "%s\n", file_mutator.line(i).c_str());
    }
}
