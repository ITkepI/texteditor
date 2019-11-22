//
// Created by Linux Oid on 16/11/2019.
//

// Классы для действий над курсором.

#ifndef TEXTEDITOR_CURSORACTION_H
#define TEXTEDITOR_CURSORACTION_H

#include "Cursor.h"

// Базовый класс для всех действий над курсором с заданным интерфейсом.
class CursorAction {
public:
    virtual void handle(Cursor &, FileBuffer const &) = 0;

    virtual ~CursorAction() = default;
};

// Класс для перемещения курсора на верхнюю строчку.
// Пример:
//  Cursor c;
//  CursorAction *cursor_action = new GoUp();
//  cursor_action->handle(c);
//
// Остальные классы аналогично.
class GoUp final : public CursorAction {
public:
    void handle(Cursor &c, FileBuffer const &) override;
};

class GoDown final : public CursorAction {
public:
    void handle(Cursor &c, FileBuffer const &) override;
};

class GoLeft final : public CursorAction {
public:
    void handle(Cursor &c, FileBuffer const &) override;
};

class GoRight final : public CursorAction {
public:
    void handle(Cursor &c, FileBuffer const &) override;
};

#endif //TEXTEDITOR_CURSORACTION_H
