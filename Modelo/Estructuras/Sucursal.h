#ifndef SUCURSAL_H
#define SUCURSAL_H
#include "../Multilistas/MultilistaEmpleados/MultilistaEmpleados.h"
#include "Empleado.h"
#include "iostream"

struct Sucursal {
    int pk;
    int fk;

    std::string nombre;
    std::string direccion;
    std::string barrio;
    std::string nombreGerente;
    bool estado;
    MultilistaEmpleados* empleados;

    Sucursal()
    {
        empleados = new MultilistaEmpleados(40);
    }

};

#endif
