#pragma once

#include "Icon.h"

class Erase : public Icon {
public:
    // Constructor
    Erase() {
        m_shape = ERASE; // Set the shape of the icon to ERASE
    }
};
