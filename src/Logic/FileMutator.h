//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_FILEMUTATOR_H
#define TEXTEDITOR_FILEMUTATOR_H

#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <iterator>

using Line = std::string;

/*
 * Просто файлобуффер(можно было бы наверное не выносить в отдельный файл
 */
class FileBuffer final {
public:
    using size_type = size_t;
    using buffer_type = std::vector<Line>;

    class const_iterator {
    public:
        using difference_type = ptrdiff_t;
        using value_type = const buffer_type::value_type;
        using pointer = value_type *;
        using reference = value_type &;
        using iterator_category = std::forward_iterator_tag;

        explicit const_iterator(FileBuffer const &b, int l = 0) : buffer_(b), line_number_(l) {}

        const_iterator(const_iterator const &) = default;

        const_iterator &operator++();

        const_iterator operator++(int);

        reference operator*() const;

    private:
        int line_number_;
        FileBuffer const &buffer_;

        friend bool operator==(const_iterator const &, const_iterator const &);

        friend bool operator!=(const_iterator const &, const_iterator const &);

        friend difference_type operator-(const_iterator const &, const_iterator const &);
    };


    explicit FileBuffer(std::istream &istream) {
        Line s{};
        while (std::getline(istream, s)) {
            buffer_.push_back(s);
        }
    }

    Line &operator[](int);

    Line const &operator[](int) const;

    [[nodiscard]] size_type size() const;

private:
    buffer_type buffer_;
};

/*
 * Класс - интерфейс для работы с файлом
 */
class FileMutator final {
public:
    using const_iterator = FileBuffer::const_iterator;

    explicit FileMutator(std::istream &istream) : file_buffer_(istream) {}

    FileMutator(FileMutator const &) = default;

    [[nodiscard]] size_t line_size(size_t) const;

    [[nodiscard]] const Line &line(size_t line_number) const;

    [[nodiscard]] size_t lines_quantity() const;

    [[nodiscard]] const_iterator begin() const;

    [[nodiscard]] const_iterator end() const;

private:
    FileBuffer file_buffer_;
};


#endif //TEXTEDITOR_FILEMUTATOR_H
