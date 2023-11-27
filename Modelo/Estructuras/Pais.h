#ifndef PROYECTO_CIENCIAS_PAIS_H
#define PROYECTO_CIENCIAS_PAIS_H

#include "../Multilistas/MultilistaCiudades/MultilistaCiudad.h"
#include <iostream>

/**
 * @brief Estructura que representa un país con sus atributos.
 */
struct Pais
{
    int pk; ///< Clave primaria del país.
    std::string nombre; ///< Nombre del país.
    bool estado; ///< Estado del país (activo o inactivo).

    MultilistaCiudad* ciudades; ///< Puntero a una multilista de ciudades asociadas al país.

    /**
     * @brief Constructor por defecto de la estructura Pais.
     *
     * Inicializa el puntero a la multilista de ciudades.
     */
    Pais() {
        ciudades = new MultilistaCiudad(20);
    }
};

#endif //PROYECTO_CIENCIAS_PAIS_H