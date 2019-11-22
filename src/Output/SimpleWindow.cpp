//
// Created by Linux Oid on 16/11/2019.
//

#include "SimpleWindow.h"

SimpleWindow::SimpleWindow(WINDOW *w) : printer_(w), window_(w) {}

SimpleWindow::SimpleWindow() : SimpleWindow(initscr()) {}

void SimpleWindow::Print(FileViewer const &file_viewer, Cursor cursor) {
    wmove(window_, 0, 0);
    werase(window_);
    Cursor temp_cur = cursor;
    if (cursor.line_number < window_start_)
        window_start_ = cursor.line_number;
    cursor.line_number -= window_start_;
    auto temp = file_viewer.begin() + window_start_;
    int a = printer_.Print(window_, temp, file_viewer.end(), cursor, MaxY() - 1);
    if (cursor.line_number + 1 > a)
        window_start_ += cursor.line_number - a + 1;
    wprintw(window_, "%d %d %d-%d %d", window_start_, a, temp_cur.line_number, temp_cur.char_number_in_line,
            file_viewer.begin()->size());
    wrefresh(window_);
}

WINDOW *SimpleWindow::window() {
    return window_;
}

int SimpleWindow::MaxX() {
    return getmaxx(window_);
}

int SimpleWindow::MaxY() {
    return getmaxy(window_);
}

