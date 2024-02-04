#pragma once

#include "Icon.h"

class Wall : public Icon
{
public:
	Wall() { m_shape = WALL; }
};