//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_CURSORACTION_H
#define TEXTEDITOR_CURSORACTION_H

#include "Cursor.h"

class CursorAction {
public:
    virtual void handle(Cursor &) = 0;

    virtual ~CursorAction() = default;
};

class GoUp final : public CursorAction {
public:
    void handle(Cursor &c) override;
};

class GoDown final : public CursorAction {
public:
    void handle(Cursor &c) override;
};

class GoLeft final : public CursorAction {
public:
    void handle(Cursor &c) override;
};

class GoRight final : public CursorAction {
public:
    void handle(Cursor &c) override;
};

#endif //TEXTEDITOR_CURSORACTION_H
