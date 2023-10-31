#pragma once
#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{

private:
	std::string m_shop;
	std::string m_opening_hours;
	std::string m_wheelchair;

public:
	PuntDeInteresBotigaSolucio();
	PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string horario, std::string tienda, std::string wheelchair): PuntDeInteresBase(coord, name), m_shop(tienda), m_opening_hours(horario), m_wheelchair(wheelchair){}

	unsigned int getColor();
};