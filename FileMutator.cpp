//
// Created by Linux Oid on 16/11/2019.
//

#include "FileMutator.h"

size_t FileMutator::line_size(size_t line_number) const {
    return file_buffer_.buffer[line_number].size();
}

size_t FileMutator::lines_quantity() const {
    return file_buffer_.buffer.size();
}

Line FileMutator::line(size_t line_number) const {
    return file_buffer_.buffer.at(line_number);
}
