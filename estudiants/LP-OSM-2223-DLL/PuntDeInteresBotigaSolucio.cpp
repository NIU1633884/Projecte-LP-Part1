#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio()
{
	this->m_shop = "undefinit";
	this->m_opening_hours = "undefinit";
	this->m_wheelchair = "undefinit";

}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
	if (this->m_shop == "supermarket")
		return 0xA5BE00;
	else if (this->m_shop == "tobacco")
		return 0xFFAD69;
	else if (this->m_shop == "bakery") {
		if (this->m_opening_hours.find("06:00-22:00") && this->m_wheelchair == "yes")
			return 0x4CB944;
		return 0xE85D75;
	}
	return 0xEFD6AC;
}
