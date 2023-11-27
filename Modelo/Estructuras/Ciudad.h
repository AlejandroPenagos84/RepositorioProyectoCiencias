//
// Created by Alejandro Penagos on 17/11/2023.
//

#ifndef PROYECTO_CIENCIAS_CIUDAD_H
#define PROYECTO_CIENCIAS_CIUDAD_H
#include "iostream"
#include "../Multilistas/MultilistaSucursales/MultilistaSucursales.h"

struct Ciudad
{
    int pk;
    int fk;
    std::string nombre;
    bool estado;
    MultilistaSucursales* sucursales;

    Ciudad()
    {
        sucursales = new MultilistaSucursales(20);
    }
};
#endif //PROYECTO_CIENCIAS_CIUDAD_H
