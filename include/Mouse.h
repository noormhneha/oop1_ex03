#pragma once

#include "Icon.h"

class Mouse : public Icon {
public:
    // Constructor
    Mouse() {
        m_shape = MOUSE; // Set the shape of the icon to MOUSE
    }
};
