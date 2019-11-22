//
// Created by Linux Oid on 22/11/2019.
//

#ifndef TEXTEDITOR_WINDOW_H
#define TEXTEDITOR_WINDOW_H

#include "../Logic/FileViewer.h"

class Window {
    virtual void Print(FileViewer const &, Cursor) = 0;
};


#endif //TEXTEDITOR_WINDOW_H
