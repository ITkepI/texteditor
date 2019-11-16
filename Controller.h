//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_CONTROLLER_H
#define TEXTEDITOR_CONTROLLER_H

#include <map>
#include "FileMutator.h"
#include "Cursor.h"
#include "ActionWrapper.h"
#include "CursorActionWrapper.h"

class Handler final {
public:
    void Handle(int c, Cursor &cursor);

private:
    std::map<wchar_t, std::shared_ptr<CursorAction>> mapper_{
            {L'k', std::shared_ptr<CursorAction>(
                    new GoUp())},
            {L'j', std::shared_ptr<CursorAction>(
                    new GoDown())},
            {L'l', std::shared_ptr<CursorAction>(
                    new GoRight())},
            {L'h', std::shared_ptr<CursorAction>(
                    new GoLeft())}};
};

class Controller final {
public:
    explicit Controller(const FileMutator &file_mutator);

    void HandleInput(int c);

    Cursor cursor();

    FileMutator file_mutator();

private:
    FileMutator file_mutator_;
    Handler handler_;
    Cursor cursor_;
};


#endif //TEXTEDITOR_CONTROLLER_H
