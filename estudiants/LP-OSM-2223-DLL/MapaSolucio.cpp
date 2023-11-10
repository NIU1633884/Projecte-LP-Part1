#include <vector>
#include <iostream>

#include "Util.h"
#include "pch.h"
#include "MapaSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"



void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pdis)
{
	/*
	Coordinate p;
	p.lat = 41.4918606; p.lon = 2.1465411;
	pdis.push_back(new PuntDeInteresBotigaSolucio(p, "La Millor Pastisseria","", "bakery",""));

	Coordinate r;
	r.lat = 41.4902204; r.lon = 2.1406477;
	pdis.push_back(new PuntDeInteresRestaurantSolucio(r,"El Millor Restaurant", "regional", "yes"));
	*/
	
	
	//Iterem tots els punts d'interes
	for (int i = 0; i < m_puntsDeInteres.size(); i++) {
		//afegim els punts d'interes
		pdis.push_back(m_puntsDeInteres[i]);
	}
	
	
	//no entenc on hi ha que retornar els colors pero ho fem amb .getColor();
}


void MapaSolucio::getCamins(std::vector<CamiBase*>& cami) {
	//Iterem tots els camins
	
	for (int i = 0; i < m_camins.size(); i++) {
		//afegim els camins
		cami.push_back(m_camins[i]);
	}




	//CamiSolucio *a = new CamiSolucio();
	//a->getCamiCoords();
	//cami.push_back(a);
	//cami[0]->getCamiCoords();
	
}

std::pair<std::string, std::string> getRefValue(const std::vector<PAIR_ATTR_VALUE>& atributsTag) {
	std::pair<std::string, std::string> result = { "", "" };

	for (const PAIR_ATTR_VALUE& atributTag : atributsTag) {
		if (atributTag.first == "ref") {
			result.second = atributTag.second;
			break;
		}
	}

	return result;
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {

	//Iterem els elements
	bool esPunt = false;
	double lat_aux;
	double lon_aux;
	std::string name;
	std::string cuisine;
	std::string amenity;
	std::string wheelchair;
	std::string shop;
	std::string opening_hours;

	std::string highway;
	std::string oneway;
	std::string surface;

	Coordinate coords;
	PuntDeInteresBase* aux;
	PuntDeInteresBotigaSolucio* auxB;
	PuntDeInteresRestaurantSolucio* auxR;

	CamiSolucio* auxC;

	std::string ref;
	Coordinate c;
	c.lat = 0;
	c.lon = 0;

	int es = 0; //0 = default 1 = restaurant 2 = botiga

	for (int i = 0; i < xmlElements.size(); i++) {

		//Util::escriuEnMonitor(std::to_string(i));
		lat_aux = 0;
		lon_aux = 0;
		esPunt = false;
		//Si es un node amb nom

		


		if (xmlElements[i].id_element == "node") {

			for (int j = 0; j < xmlElements[i].fills.size(); j++) {
				if (xmlElements[i].fills[j].first == "tag")
				{
					//Emmagatzenem tag
					std::pair<std::string, std::string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);
					//Guardem amenity, name, cuisine y wheelchair
					if (valorTag.first == "name") {
						esPunt = true;
					}
				}
			}

			if (esPunt == true) {

				//Iterem atributs per trobar coord
				for (int j = 0; j < xmlElements[i].atributs.size(); j++) {
					if (xmlElements[i].atributs[j].first == "lat") {
						lat_aux = std::stod(xmlElements[i].atributs[j].second);
					}
					if (xmlElements[i].atributs[j].first == "lon") {
						lon_aux = std::stod(xmlElements[i].atributs[j].second);
					}
				}
				//Iterem fills per trobar tag y name
				for (int j = 0; j < xmlElements[i].fills.size(); j++) {
					if (xmlElements[i].fills[j].first == "tag")
					{
						//Emmagatzenem tag
						std::pair<std::string, std::string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);
						//Guardem amenity, name, cuisine y wheelchair
						if (valorTag.first == "amenity") {
							amenity = valorTag.second;
						}
						if (valorTag.first == "name") {
							name = valorTag.second;
						}
						if (valorTag.first == "cuisine") {
							cuisine = valorTag.second;
						}
						if (valorTag.first == "wheelchair") {
							wheelchair = valorTag.second;
						}
						if (valorTag.first == "opening_hours") {
							opening_hours = valorTag.second;
						}
						if (valorTag.first == "shop") {
							shop = valorTag.second;
						}
					}
				}
				coords.lat = lat_aux;
				coords.lon = lon_aux;
				//Depenent el que sigui farem un push diferent
				if (amenity == "restaurant") {
					auxR = new PuntDeInteresRestaurantSolucio(coords, name, cuisine, wheelchair);
					m_puntsDeInteres.push_back(auxR);
				}
				else {
					if (amenity == "botiga") {
						auxB = new PuntDeInteresBotigaSolucio(coords, name, shop, opening_hours, wheelchair);
						m_puntsDeInteres.push_back(auxB);
					}
					else {
						aux = new PuntDeInteresBase(coords, name);
						m_puntsDeInteres.push_back(aux);
					}
				}

				//m_puntsDeInteres.push_back(aux);
			}
		}

		//Si es un cami
		
		if (xmlElements[i].id_element == "way") {
			auxC = new CamiSolucio();
			for (int j = 0; j < xmlElements[i].fills.size(); j++) {
				//SI es un node el posem al cami
				if (xmlElements[i].fills[j].first == "nd")
				{
					//Emmagatzenem tag
					std::pair<std::string, std::string> refValuePair = getRefValue(xmlElements[i].fills[j].second);
					ref = refValuePair.second;
					//Busquem el node per trobar les seves coordenades
					//Iterem tots el elements un altre cop
					/*for (int k = 0; k < xmlElements[k].atributs.size(); k++) {
						if (xmlElements[k].id_element == "node") {
							for (int l = 0; l < xmlElements[k].atributs.size(); l++) {
								if (xmlElements[k].atributs[l].first == "id") {
									if (xmlElements[k].atributs[l].second == ref) {
										//Iterem atributs per trobar coord
										for (int m = 0; m < xmlElements[k].atributs.size(); m++) {
											if (xmlElements[k].atributs[m].first == "lat") {
												c.lat = std::stod(xmlElements[k].atributs[m].second);
											}
											if (xmlElements[k].atributs[m].first == "lon") {
												c.lon = std::stod(xmlElements[k].atributs[j].second);
											}
										}
									}
								}
							}
						}
					}*/
					for (int k = 0; k < xmlElements.size(); k++) {
						if (xmlElements[k].id_element == "node") {
							for (int l = 0; l < xmlElements[k].atributs.size(); l++) {
								if (xmlElements[k].atributs[l].first == "id") {
									if (xmlElements[k].atributs[l].second == ref) {
										//Iterem atributs per trobar coord
										for (int m = 0; m < xmlElements[k].atributs.size(); m++) {
											if (xmlElements[k].atributs[m].first == "lat") {
												c.lat = std::stod(xmlElements[k].atributs[m].second);
											}
											if (xmlElements[k].atributs[m].first == "lon") {
												c.lon = std::stod(xmlElements[k].atributs[m].second);
											}
										}
									}
								}
							}
						}
					}
					//afegim el node al cami
					//if (auxC->getN() <= 5) {
						auxC->addNode(c);
					//}
					//Util::escriuEnMonitor(std::to_string(c.lat));
					
					
					
				}
				if (xmlElements[i].fills[j].first == "tag")
				{
					std::pair<std::string, std::string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);

					if (valorTag.first == "highway") {
						highway = valorTag.second;
					}
					if (valorTag.first == "name") {
						name = valorTag.second;
					}
					if (valorTag.first == "oneway") {
						oneway = valorTag.second;
					}
					if (valorTag.first == "surface") {
						surface = valorTag.second;
					}
				}
			}

			//Posem els valors a cami
			auxC->setHighway(highway);
			auxC->setName(name);
			auxC->setOneway(oneway);
			auxC->setSurface(surface);
			//afegim cami a cami
			m_camins.push_back(auxC);
		}
	}
	//c = m_camins[0]->getCamiCoords()[0];

	//Util::escriuEnMonitor(std::to_string(c.lat));
	//c = m_puntsDeInteres[0]->getCoord();
	//Util::escriuEnMonitor(std::to_string(c.lat));
}