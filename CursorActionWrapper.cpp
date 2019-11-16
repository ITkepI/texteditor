//
// Created by Linux Oid on 16/11/2019.
//

#include "CursorActionWrapper.h"

void CursorActionWrapper::run() {
    cursor_action_->handle(cursor_);
}
