#include <iostream>
#include "Common.h"
#include "Util.h"

int main()
{
    std::cout << "Implementeu en aquesta solucio la solucio per les Tasques 1 i 2" << std::endl;
    std::cout << "===============================================================" << std::endl;

	XmlElement viejoRoble = {
		//id_element = 
			"node",

		// atributs = 
		{
			std::make_pair("id", "357101444"),
			std::make_pair("visible", "true"),
			std::make_pair("version", "3"),
			std::make_pair("changeset", "77532251"),
			std::make_pair("timestamp", "2019-11-25T15:26:03Z"),
			std::make_pair("user", "MultiDavid2001b"),
			std::make_pair("uid", "4946691"),
			std::make_pair("lat", "41.4902204"),
			std::make_pair("lon", "2.1406477")
		},

		// fills = 
		{
			std::make_pair<std::string,std::vector<std::pair<std::string, std::string>>>
				("tag", {
					std::make_pair<std::string, std::string>("k", "amenity"),
					std::make_pair<std::string, std::string>("v", "restaurant")
			}),
			std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", {
						std::make_pair<std::string, std::string>("k","cuisine"),
						std::make_pair<std::string, std::string>("v", "regional")
			}),
			std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", {
						std::make_pair<std::string, std::string>("k", "name"),
						std::make_pair<std::string, std::string>("v", "El Roble")
					}),
			std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", {
						std::make_pair("k","wheelchair"),
						std::make_pair("v", "yes")
					})
		}
	};


	std::string tempsValor = "";
	bool permetMobilitatReduida = false;
	// Comprovem per id_element, que es tracta d’un node
	if (viejoRoble.id_element == "node") {
		// En cas que sigui un node, recorrem els seus atributs
		for (int i = 0; i < viejoRoble.atributs.size(); i++) {
			// Iterem fins trobar el atribut que ens interessa
			if (viejoRoble.atributs[i].first == "timestamp") {
				tempsValor = viejoRoble.atributs[i].second;
			}
		}
		// Recorrem els fills d’aquest node
		for (int i = 0; i < viejoRoble.fills.size(); i++) {
			// Iterem i avaluem tots els fills que son tags
			if (viejoRoble.fills[i].first == "tag") {
				// Emmagatzemem el valor d’aquest tag
				std::pair<std::string, std::string> valorTag =
					Util::kvDeTag(viejoRoble.fills[i].second);
				// Comprovem que es el tag que busquem
				if (valorTag.first == "name") {
					std::cout<<"Nom: "<<valorTag.second;
				}
			}
		}
	}


	/*
		Tasca 1:
		Imprimir per pantalla l’identificador, latitud (lat), l’longitud (lon), 
		així com el nom (name), del element XML viejoRoble construit en aquest apartat 2.2.
		
		Teniu en compte que, almenys, haureu de transformar latitud i longitud a tipus double.
		
		Recordeu que en la solució de la pràctica haureu de recollir tots els punts d’interés, 
		que per definició, són nodes que no són nodes de camí que tenen un atribut name.
	*/

	// TODO Tasca1 
	//Tasca 1:
	if (viejoRoble.id_element == "node") {
		// En cas que sigui un node, recorrem els seus atributs
		for (int i = 0; i < viejoRoble.atributs.size(); i++) {
			// Iterem fins trobar el atribut que ens interessa
			if (viejoRoble.atributs[i].first == "id") {
				std::cout<<"Identificacio: "<<viejoRoble.atributs[i].second<<endl;
			}
			if (viejoRoble.atributs[i].first == "lat") {
				std::cout<<"Latitud: "<<viejoRoble.atributs[i].second<<endl;
			}
			if (viejoRoble.atributs[i].first == "lon") {
				std::cout<<"Longitud: "<<viejoRoble.atributs[i].second<<endl;
			}
		}
		// Recorrem els fills d’aquest node
		for (int i = 0; i < viejoRoble.fills.size(); i++) {
			// Iterem i avaluem tots els fills que son tags
			if (viejoRoble.fills[i].first == "tag") {
				// Emmagatzemem el valor d’aquest tag
				std::pair<std::string, std::string> valorTag =
					Util::kvDeTag(viejoRoble.fills[i].second);
				// Comprovem que es el tag que busquem
				if (valorTag.first == "wheelchair") {
					permetMobilitatReduida =
						(valorTag.second == "yes") ? true : false;
				}
			}
		}

    	std::vector<CHILD_NODE> fills_aux=viejoRoble.fills;
	

	XmlElement camiJoaquim = {
		// id_element = 
		"way",

		// atributs = 
		{
			std::make_pair("id", "31889094"),
			std::make_pair("visible", "true"),
			std::make_pair("version", "6"),
			std::make_pair("changeset", "1002251634"),
			std::make_pair("timestamp", "2021-04-03T21:17:17Z"),
			std::make_pair("user", "Interswd"),
			std::make_pair("uid", "3414856")
		},

		// fills = 
		{
				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("nd",	{
								std::make_pair("ref", "357125056")
							}),

				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("nd", 
							{
								std::make_pair("ref", "8591278795")
							}),

				std::make_pair< std::string, std::vector<std::pair<std::string, std::string>>>
					("nd", 
							{
								std::make_pair("ref", "357124693")
							}),

				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("nd",	
							{
								std::make_pair("ref", "357125054")
							}),
				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", 
							{
								std::make_pair("k", "highway"),
								std::make_pair("v", "living_street")
							}),
				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", 
							{
								std::make_pair("k", "name"),
								std::make_pair("v", "Carrer de Sant Joaquim")
							}),
				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", 
							{
								std::make_pair("k", "oneway"),
								std::make_pair("v", "yes")
							}),
				std::make_pair<std::string, std::vector<std::pair<std::string, std::string>>>
					("tag", 
							{
								std::make_pair("k", "surface"),
								std::make_pair("v", "paving_stones")
							})
		}
	};



	/*
		Tasca 2: 
		Imprimir per pantalla els identificadors dels nodes 
		que formen el XmlElement camiJoaquim, així com el valor del atribut highway. 
		
		Recordeu que en la solució de la pràctica només haureu de tenir en compte 
		tots els camins que tenen el tag highway (independentment del valor que pugui tenir), 
		així com saber quins nodes de tipus camí, formen cada camí.
	*/

	// TODO Tasca2 

	return 0;

}

