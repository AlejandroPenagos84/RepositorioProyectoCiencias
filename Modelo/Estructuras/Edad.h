#ifndef EDAD_H
#define EDAD_H

#include <iostream>
#include <sstream>
#include <ctime>

/**
 * @brief Estructura que representa una fecha con día, mes y año.
 */
struct Fecha {
    int dia; ///< Día de la fecha.
    int mes; ///< Mes de la fecha.
    int anio; ///< Año de la fecha.
};

/**
 * @brief Convierte una cadena de texto en formato "dd/mm/yyyy" a una estructura Fecha.
 *
 * @param fechaStr Cadena de texto que representa la fecha en formato "dd/mm/yyyy".
 * @return Estructura Fecha con el día, mes y año.
 */
inline Fecha obtenerFechaDesdeString(const std::string& fechaStr) {
    Fecha fecha{};
    std::stringstream ss(fechaStr);
    char delimiter;

    ss >> fecha.dia >> delimiter >> fecha.mes >> delimiter >> fecha.anio;

    return fecha;
}

/**
 * @brief Calcula la edad en años a partir de la fecha de nacimiento.
 *
 * @param fechaNacimiento Estructura Fecha que representa la fecha de nacimiento.
 * @return Edad en años.
 */
inline int calcularEdad(const Fecha& fechaNacimiento) {
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

    int edad = tiempoLocal->tm_year + 1900 - fechaNacimiento.anio;

    if (tiempoLocal->tm_mon + 1 < fechaNacimiento.mes ||
        (tiempoLocal->tm_mon + 1 == fechaNacimiento.mes && tiempoLocal->tm_mday < fechaNacimiento.dia)) {
        --edad;
    }
    return edad;
}

#endif