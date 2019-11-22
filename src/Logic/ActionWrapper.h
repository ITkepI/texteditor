//
// Created by Linux Oid on 16/11/2019.
//

#ifndef TEXTEDITOR_ACTIONWRAPPER_H
#define TEXTEDITOR_ACTIONWRAPPER_H

/*
 * Класс-оболочка для действий(добавление текста, перемещение курсора и тд)
 */
class ActionWrapper {
public:
    virtual void run() = 0;

    virtual ~ActionWrapper() = default;
};


#endif //TEXTEDITOR_ACTIONWRAPPER_H
