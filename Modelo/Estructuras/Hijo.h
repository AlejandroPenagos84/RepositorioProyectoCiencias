#ifndef HIJO_H
#define HIJO_H
#include "Edad.h"
#include <string>

struct Hijo
{
    int pk{};
    int fk;
    std::string nombre{};
    std::string fechaNacimiento{"21/05/2005"};
    bool estado{true};
    int edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));

    int sigEdad{-1};


    Hijo()
    {
        // Supongo que calcularEdad y obtenerFechaDesdeString están definidas
        edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));
    }

};
#endif
