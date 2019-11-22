//
// Created by Linux Oid on 16/11/2019.
//

#include "FileMutator.h"

size_t FileMutator::line_size(size_t line_number) const {
    return file_buffer_[line_number].size();
}

size_t FileMutator::lines_quantity() const {
    return file_buffer_.size();
}

const Line &FileMutator::line(size_t line_number) const {
    return file_buffer_[line_number];
}

FileMutator::const_iterator FileMutator::begin() const {
    return FileMutator::const_iterator(file_buffer_);
}

Line &FileBuffer::operator[](int a) {
    return buffer_.at(a);
}

Line const &FileBuffer::operator[](int a) const {
    return buffer_.at(a);
}

FileBuffer::size_type FileBuffer::size() const {
    return buffer_.size();
}

FileBuffer::const_iterator &FileBuffer::const_iterator::operator++() {
    ++line_number_;
    return *this;
}

FileBuffer::const_iterator FileBuffer::const_iterator::operator++(int) {
    const_iterator ret = *this;
    ++*this;
    return ret;
}

FileBuffer::const_iterator::reference FileBuffer::const_iterator::operator*() const {
    return buffer_[line_number_];
}

bool operator==(const FileBuffer::const_iterator &cit1, const FileBuffer::const_iterator &cit2) {
    return cit1.line_number_ == cit2.line_number_ && &cit1.buffer_ == &cit2.buffer_;
}

bool operator!=(const FileBuffer::const_iterator &cit1, const FileBuffer::const_iterator &cit2) {
    return !(cit1 == cit2);
}

FileBuffer::const_iterator::difference_type
operator-(const FileBuffer::const_iterator &it1, const FileBuffer::const_iterator &it2) {
    if (&it1.buffer_ != &it2.buffer_)
        throw std::logic_error("Iterators don't points to the same file");
    auto size1 = it1.line_number_ == -1 ? it1.buffer_.size() : it1.line_number_;
    auto size2 = it2.line_number_ == -1 ? it2.buffer_.size() : it2.line_number_;
    return size1 - size2;
}

FileBuffer::const_iterator::value_type *FileBuffer::const_iterator::operator->() const {
    return &(this->operator*());
}

FileMutator::const_iterator FileMutator::end() const {
    return FileMutator::const_iterator(file_buffer_, -1);
};