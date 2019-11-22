//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_CURSORACTIONWRAPPER_H
#define TEXTEDITOR_CURSORACTIONWRAPPER_H

#include "../../ActionWrapper.h"
#include "Cursor.h"
#include "CursorAction.h"

#include <utility>

/*
 * Просто ActionWrapper для курсорных действий.
 * Пример:
 *  Cursor cur;
 *  std::shared_ptr<ActionWrapper> aw = std::make_shared<CursorActionWrapper>(cur, std::make_shared<CursorActionWrapper>(cur, std::make_shared<GoUp>());
 *  aw->run();
 */
class CursorActionWrapper final : ActionWrapper {
public:
    CursorActionWrapper(Cursor &c, std::shared_ptr<CursorAction> const &ca) : cursor_(c), cursor_action_(ca) {}

    CursorActionWrapper(CursorActionWrapper const &) = default;

    void run() override;

private:
    Cursor &cursor_;
    std::shared_ptr<CursorAction> cursor_action_;
};


#endif //TEXTEDITOR_CURSORACTIONWRAPPER_H
