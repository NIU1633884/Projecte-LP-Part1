#include <string>
#include "Common.h"
#include "PuntDeInteresBase.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{

private:
	std::string m_cocina;
	std::string m_wheelchair;

public:
	PuntDeInteresRestaurantSolucio();
	PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cocina, std::string wheelchair) : PuntDeInteresBase(coord, name), m_cocina(cocina), m_wheelchair(wheelchair) {}

	 unsigned int getColor();
};