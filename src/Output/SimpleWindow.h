//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_SIMPLEWINDOW_H
#define TEXTEDITOR_SIMPLEWINDOW_H

#include "Printer.h"
#include "../Logic/Cursor.h"
#include "Window.h"
#include <ncurses.h>

/*
 * Класс для работы с выводом на окно.
 * Если кто-нибудь другой займется выводом можно спокойно менять эту хуйню.
 */
class SimpleWindow final : Window {
public:
    explicit SimpleWindow(WINDOW *);

    SimpleWindow();

    void Print(FileViewer const &, Cursor) override;

    [[nodiscard]] WINDOW *window();

    [[nodiscard]] int MaxX();

    [[nodiscard]] int MaxY();

private:
    size_t window_start_ = 0;
    Printer printer_;
    WINDOW *window_;
};


#endif //TEXTEDITOR_SIMPLEWINDOW_H
