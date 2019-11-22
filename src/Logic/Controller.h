//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_CONTROLLER_H
#define TEXTEDITOR_CONTROLLER_H

#include <map>
#include "FileMutator.h"
#include "Cursor.h"
#include "../../ActionWrapper.h"
#include "CursorActionWrapper.h"

// Класс для обработки символов.
// Принимает символ и курсор. (В будущем это поменяется)
class Handler final {
public:
    void Handle(int c, Cursor &cursor);

private:
    std::map<wchar_t, std::shared_ptr<CursorAction>> cursor_action_mapper_{
            {L'k', std::shared_ptr<CursorAction>(
                    new GoUp())},
            {L'j', std::shared_ptr<CursorAction>(
                    new GoDown())},
            {L'l', std::shared_ptr<CursorAction>(
                    new GoRight())},
            {L'h', std::shared_ptr<CursorAction>(
                    new GoLeft())}};
};

// Класс, который контролирует работу над файлом и курсором.
// В будушем тоже меняться будет.
class Controller final {
public:
    explicit Controller(const FileMutator &file_mutator);

    void HandleInput(int c);

    [[nodiscard]] const Cursor &cursor() const;

    [[nodiscard]] const FileMutator &file_mutator() const;

private:
    FileMutator file_mutator_;
    Handler handler_;
    Cursor cursor_;
};


#endif //TEXTEDITOR_CONTROLLER_H
