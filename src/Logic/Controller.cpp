//
// Created by Linux Oid on 16/11/2019.
//

#include "Controller.h"

void Controller::HandleInput(int c) {
    handler_.Handle(c, cursor_, file_buffer_);
}

Controller::Controller(const FileBuffer &file_mutator) : file_buffer_(file_mutator) {}

const Cursor &Controller::cursor() const {
    return cursor_;
}

FileViewer Controller::file_viewer() const {
    return FileViewer(file_buffer_);
}

void Handler::Handle(int c, Cursor &cursor, const FileBuffer &fb) {
    auto it = cursor_action_mapper_.find(c);
    if (it == cursor_action_mapper_.end())
        return;
    it->second->handle(cursor, fb);
}
