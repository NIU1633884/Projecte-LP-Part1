#pragma once
#include "pch.h"
#include "CamiBase.h"

class CamiSolucio : public CamiBase {
public:
	std::vector<Coordinate> getCamiCoords();   //retorna varies cordenades, les del cami que formen els nodes
};