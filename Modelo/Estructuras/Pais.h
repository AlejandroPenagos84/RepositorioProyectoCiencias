#ifndef PROYECTO_CIENCIAS_PAIS_H
#define PROYECTO_CIENCIAS_PAIS_H
#include "../Multilistas/MultilistaCiudades/MultilistaCiudad.h"
#include <iostream>

struct Pais
{
    int pk;
    std::string nombre;
    bool estado;

    MultilistaCiudad* ciudades;

    Pais() {
        ciudades = new MultilistaCiudad(20);
    }
};
#endif //PROYECTO_CIENCIAS_PAIS_H
