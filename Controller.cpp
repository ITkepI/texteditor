//
// Created by Linux Oid on 16/11/2019.
//

#include "Controller.h"

void Controller::HandleInput(int c) {
    handler_.Handle(c, cursor_);
}

Controller::Controller(const FileMutator &file_mutator) : file_mutator_(file_mutator), cursor_(file_mutator) {}

Cursor Controller::cursor() {
    return cursor_;
}

FileMutator Controller::file_mutator() {
    return file_mutator_;
}

void Handler::Handle(int c, Cursor &cursor) {
    auto it = mapper_.find(c);
    if (it == mapper_.end())
        return;
    it->second->handle(cursor);
}
