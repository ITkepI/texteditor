//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_FILEMUTATOR_H
#define TEXTEDITOR_FILEMUTATOR_H

#include <vector>
#include <utility>
#include <fstream>
#include <string>

using Line = std::string;

struct FileBuffer final {
    explicit FileBuffer(std::istream &istream) {
        Line s{};
        while (std::getline(istream, s)) {
            buffer.push_back(s);
        }
    }

    std::vector<Line> buffer;
};

class FileMutator final {
public:
    explicit FileMutator(std::istream &istream) : file_buffer_(istream) {}

    FileMutator(FileMutator const &) = default;

    [[nodiscard]] size_t line_size(size_t) const;

    [[nodiscard]] Line line(size_t) const;

    [[nodiscard]] size_t lines_quantity() const;

private:
    FileBuffer file_buffer_;
};


#endif //TEXTEDITOR_FILEMUTATOR_H
