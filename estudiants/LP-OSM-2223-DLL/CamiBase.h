#pragma once

#include "Common.h"
#include <vector>

class CamiBase {  //Classe virtual pura
	public:
		virtual std::vector<Coordinate> getCamiCoords() = 0;
};

