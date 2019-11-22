//
// Created by Linux Oid on 16/11/2019.
//

#include "FileViewer.h"

size_t FileViewer::line_size(size_t line_number) const {
    return file_buffer_[line_number].size();
}

size_t FileViewer::lines_quantity() const {
    return file_buffer_.size();
}

const Line &FileViewer::line(size_t line_number) const {
    return file_buffer_[line_number];
}

FileViewer::const_iterator FileViewer::begin() const {
    return FileViewer::const_iterator(file_buffer_);
}

FileViewer::const_iterator FileViewer::end() const {
    return FileViewer::const_iterator(file_buffer_, file_buffer_.size());
};