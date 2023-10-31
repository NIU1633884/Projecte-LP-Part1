#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio()
{
	this->m_cocina = "undefinit";
	this->m_wheelchair = "undefinit";
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	if (this->m_cocina == "“pizza”" && this->m_wheelchair == "yes")
		return 0x03FCBA;
	else if (this->m_cocina == "“chinese”")
		return 0xA6D9F7;
	else if (this->m_wheelchair == "yes") {
		return 0x251351;
	}
	return 0xEFD6AC;
	
}
