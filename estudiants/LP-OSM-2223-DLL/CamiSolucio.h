#pragma once
#include "pch.h"
#include "CamiBase.h"

class CamiSolucio : public CamiBase {
public:
	std::vector<Coordinate> getCamiCoords();   //retorna varies cordenades, les del cami que formen els nodes
	void addNode(Coordinate n) { nodes.push_back(n); }
	void setOneway(std::string o) { oneway = o; }
	void setName(std::string n) { name = n; }
	void setSurface(std::string s) { surface = s; }
	void setHighway(std::string h) { highway = h; }
	int getN() { return nodes.size();}

private:
	std::vector<Coordinate> nodes;
	std::string highway;
	std::string name;
	std::string oneway;
	std::string surface;
};