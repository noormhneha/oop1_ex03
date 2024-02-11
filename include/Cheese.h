#pragma once

#include "Icon.h"

class Cheese : public Icon {
public:
    // Constructor
    Cheese() {
        m_shape = CHEESE; // Set the shape of the icon to CHEESE
    }
};
