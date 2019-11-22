//
// Created by Linux Oid on 22/11/2019.
//

#ifndef TEXTEDITOR_FILEBUFFER_H
#define TEXTEDITOR_FILEBUFFER_H

#include <iostream>
#include <vector>
#include <string>

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

        pointer operator->() const;

        int line_number_;
        FileBuffer const &buffer_;

        friend bool operator==(const_iterator const &, const_iterator const &);

        friend bool operator!=(const_iterator const &, const_iterator const &);

        friend difference_type operator-(const_iterator const &, const_iterator const &);

        friend const_iterator operator+(int, const_iterator const &);

        friend const_iterator operator+(const_iterator const &, int);
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

#endif //TEXTEDITOR_FILEBUFFER_H
