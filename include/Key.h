#pragma once

#include "Icon.h"

class Key : public Icon {
public:
    // Constructor
    Key() {
        m_shape = KEY; // Set the shape of the icon to KEY
    }
};
