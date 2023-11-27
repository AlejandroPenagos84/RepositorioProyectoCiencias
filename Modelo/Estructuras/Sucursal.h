#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "../Multilistas/MultilistaEmpleados/MultilistaEmpleados.h"
#include "Empleado.h"
#include <iostream>

/**
 * @brief Estructura que representa una sucursal con sus atributos.
 */
struct Sucursal {
    int pk; ///< Clave primaria de la sucursal.
    int fk; ///< Clave foránea (si es necesaria).

    std::string nombre; ///< Nombre de la sucursal.
    std::string direccion; ///< Dirección de la sucursal.
    std::string barrio; ///< Barrio en el que se encuentra la sucursal.
    std::string nombreGerente; ///< Nombre del gerente de la sucursal.
    bool estado; ///< Estado de la sucursal (activo o inactivo).

    MultilistaEmpleados *empleados; ///< Puntero a una multilista de empleados asociada a la sucursal.

    /**
     * @brief Constructor por defecto de la estructura Sucursal.
     *
     * Inicializa el puntero a la multilista de empleados.
     */
    Sucursal() {
        empleados = new MultilistaEmpleados(40);
    }
};

#endif // SUCURSAL_H