#pragma once

#include "Icon.h"

class Wall : public Icon {
public:
    // Constructor
    Wall() {
        m_shape = WALL; // Set the shape of the icon to WALL
    }
};
