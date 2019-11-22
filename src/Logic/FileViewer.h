//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_FILEVIEWER_H
#define TEXTEDITOR_FILEVIEWER_H

#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include "FileBuffer.h"

/*
 * Класс - интерфейс для работы с файлом
 */
class FileViewer final {
public:
    using const_iterator = FileBuffer::const_iterator;

    explicit FileViewer(FileBuffer const &fb) : file_buffer_(fb) {}

    FileViewer(FileViewer const &) = default;


    [[nodiscard]] size_t line_size(size_t) const;

    [[nodiscard]] const Line &line(size_t line_number) const;

    [[nodiscard]] size_t lines_quantity() const;

    [[nodiscard]] const_iterator begin() const;

    [[nodiscard]] const_iterator end() const;

private:
    FileBuffer const &file_buffer_;
};


#endif //TEXTEDITOR_FILEVIEWER_H
