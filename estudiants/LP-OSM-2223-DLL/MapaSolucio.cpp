#include <vector>
#include <iostream>

#include "pch.h"
#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"



void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
	Coordinate p;
	p.lat = 41.4918606; p.lon = 2.1465411;
	pdis.push_back(new PuntDeInteresBotigaSolucio(p, "La Millor Pastisseria","", "bakery",""));

	Coordinate r;
	r.lat = 41.4902204; r.lon = 2.1406477;
	pdis.push_back(new PuntDeInteresRestaurantSolucio(r,"El Millor Restaurant", "regional", "yes"));
}


void MapaSolucio::getCamins(std::vector<CamiBase*>& cami) {

	cami.push_back(new CamiSolucio());
	//cami[0]->getCamiCoords();
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {

	


	
	xmlElements; //retornar en tots els punts d'interes passejats passats per referencia
}