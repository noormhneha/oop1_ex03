#pragma once

#include "Icon.h"

class Gift : public Icon {
public:
    // Constructor
    Gift() {
        m_shape = GIFT; // Set the shape of the icon to GIFT
    }
};
