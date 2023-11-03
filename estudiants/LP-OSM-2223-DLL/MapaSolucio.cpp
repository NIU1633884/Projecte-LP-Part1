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
	/*
	cami.push_back(new CamiSolucio());
	//cami[0]->getCamiCoords();
	*/
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements) {

	//Iterem els elements

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


	int es = 0; //0 = default 1 = restaurant 2 = botiga

	for (int i = 0; i < xmlElements.size(); i++) {
		lat_aux = 0;
		lon_aux = 0;
		//Si es un node

		if (xmlElements[i].id_element == "node") {
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
				m_puntsDeInteres.push_back(auxB);
			}
			else
				if (amenity == "botiga") {
					auxB = new PuntDeInteresBotigaSolucio(coords, name, shop, opening_hours, wheelchair);
					m_puntsDeInteres.push_back(auxR);
				}
				else {
					aux = new PuntDeInteresBase(coords, name);
					m_puntsDeInteres.push_back(aux);
				}


			m_puntsDeInteres.push_back(aux);

		}

		//Si es un cami

		if (xmlElements[i].id_element == "way") {
			auxC = new CamiSolucio();
			for (int j = 0; j < xmlElements[i].fills.size(); j++) {
				//SI es un node el posem al cami
				if (xmlElements[i].fills[j].first == "nd")
				{
					//Emmagatzenem tag
					std::pair<std::string, std::string> valorTag = Util::kvDeTag(xmlElements[i].fills[j].second);
					
					if (valorTag.first == "ref") {
						ref = valorTag.second;
					}
					//Busquem el node per trobar les seves coordenades
					//Iterem tots el elements un altre cop
					for (int k = 0; k < xmlElements[k].atributs.size(); k++) {
						if (xmlElements[k].id_element == "node") {
							for (int l = 0; l < xmlElements[k].atributs.size(); l++) {
								if (xmlElements[k].atributs[l].first == "id") {
									if (xmlElements[k].atributs[l].first == ref) {
										if (xmlElements[k].atributs[l].first == "lat") {
											c.lat = std::stod(xmlElements[k].atributs[l].second);
										}
										if (xmlElements[k].atributs[l].first == "lon") {
											c.lon = std::stod(xmlElements[k].atributs[l].second);
										}
									}
								}								
							}
						}
					}
					//afegim el node al cami
					auxC->addNode(c);
				}

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

			//Posem els valors a cami
			auxC->setHighway(highway);
			auxC->setName(name);
			auxC->setOneway(oneway);
			auxC->setSurface(surface);
			//afegim cami a cami
			m_camins.push_back(auxC);
		}
	}
}