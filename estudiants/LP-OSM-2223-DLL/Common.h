#pragma once

#include "pch.h"

#include <functional>
#include <string>
#include <vector>

typedef std::pair<std::string, std::string> PAIR_ATTR_VALUE;       //node
typedef std::pair<std::string, std::vector<PAIR_ATTR_VALUE>> CHILD_NODE; //fill del de dalt -> same + string info


typedef struct {
    double lat;
    double lon;
} Coordinate;    //coordinades dos numeros [latitud , longitud]

extern "C" typedef struct {    //extern "C": Esta es una directiva que se usa cuando se quiere asegurar que el nombre de las funciones o variables declaradas no se modifiquen (no se "manglen") durante la compilación cuando se usa un compilador de C++. Esto es útil cuando se quiere hacer un enlace (linking) entre código C y C++.
    int i;
    double lat;
    double lon;
    unsigned int color; //Un número entero sin signo que podría representar un color.
    const char* title;//ES UN PUNTERO a una cadena de caracteres constante que podría representar un título.

} PoiBridge;            //Punto de Interés (POI) con información como coordenadas, color y título.

extern "C" typedef struct {
    double* lats; //Un puntero a un array de números decimales que podrían representar latitudes.
    double* lons; //Un puntero a un array de números decimales que podrían representar longitudes.
    int size;     //Un entero que podría representar el tamaño de los arrays de latitudes y longitudes.

} WayBridge;           //una ruta o camino compuesto por varios puntos.

typedef struct {
    std::string id_element;
    std::vector<PAIR_ATTR_VALUE> atributs;
    std::vector<CHILD_NODE> fills;

} XmlElement; //una representación en C++ de un elemento XML, incluyendo su identificador, atributos y nodos hijos. Esta estructura facilitaría trabajar con documentos XML, permitiendo manipular, acceder y modificar los elementos y sus propiedades de una manera estructurada y programática



