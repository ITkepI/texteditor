//
// Created by Linux Oid on 16/11/2019.
//

#include "Colors.h"

void init() {
    static bool initialized = false;
    if (!initialized)
        return;

    init_color(COLOR_GREY, 229, 229, 229);
}