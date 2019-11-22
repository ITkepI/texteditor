//
// Created by Linux Oid on 16/11/2019.
//

#include "Window.h"

Window::Window(WINDOW *w) : printer_(w), window_(w) {}

Window::Window() : Window(initscr()) {}

void Window::Print(FileMutator const &file_mutator) {
    wmove(window_, 0, 0);
    printer_.Print(file_mutator, window_start_, MaxY() - 1);
}

void Window::Print(FileMutator const &file_mutator, Cursor const &cursor) {
    wmove(window_, 0, 0);
    printer_.Print(window_, file_mutator.begin() + window_start_, file_mutator.end(), MaxY() - 1);
    wrefresh(window_);
//    printer_.Print(file_mutator, window_start_, MaxY() - 1, cursor);
}

WINDOW *Window::window() {
    return window_;
}

size_t Window::start() {
    return window_start_;
}

int Window::MaxX() {
    return getmaxx(window_);
}

int Window::MaxY() {
    return getmaxy(window_);
}

void Window::MoveStartDown(size_t a) {
    window_start_ += a;
}

void Window::MoveStartUp(size_t a) {
    window_start_ -= a;
}

