//
// Created by Linux Oid on 16/11/2019.
//

#include "Controller.h"

void Controller::HandleInput(int c) {
    handler_.Handle(c, cursor_);
}

Controller::Controller(const FileMutator &file_mutator) : file_mutator_(file_mutator), cursor_(file_mutator_) {}

const Cursor &Controller::cursor() const {
    return cursor_;
}

const FileMutator &Controller::file_mutator() const {
    return file_mutator_;
}

void Handler::Handle(int c, Cursor &cursor) {
    auto it = cursor_action_mapper_.find(c);
    if (it == cursor_action_mapper_.end())
        return;
    it->second->handle(cursor);
}
