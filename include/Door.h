#pragma once

#include "Icon.h"

class Door : public Icon {
public:
    // Constructor
    Door() {
        m_shape = DOOR; // Set the shape of the icon to DOOR
    }
};
