#include "MultilistaHijo.h"
#include <iostream>
#include <utility>

MultilistaHijo::MultilistaHijo(int max) {
    /**
     * @brief Constructor de la clase.
     *
     * Inicializa el arreglo de hijos, la cabecera de edades, la posición libre, el tamaño
     * y la cabecera de edades inicial.
     *
     * @param max Tamaño máximo del arreglo de hijos.
     */

    // Inicializar arreglo de hijo
    hijos = new Hijo[max];

    // Cabecera de edades
    CEdad = new Cabecera<std::string>[4];

    // Posicion Libre
    posLibre = 0;

    //size
    size = 0;

    // Incializar Cabecera de edades
    CEdad[0] = {"0 a 5", -1};
    CEdad[1] = {"6 a 10", -1};
    CEdad[2] = {"11 a 18", -1};
    CEdad[3] = {"Mas de 18", -1};
}

void MultilistaHijo::AgregarHijo(Hijo hijo) {
    /**
     * @brief Agrega un hijo a la multilista.
     *
     * @param Hijo hijo
     */

    hijos[posLibre] = std::move(hijo);
    OrganizarCategoria(CEdad,
                       posLibre,
                       &Hijo::sigEdad,
                       getCabeceraEdad(posLibre));
    posLibre++;
    size++;
}

void MultilistaHijo::ModificarCategoria(int num, int valor, int indice) {
    /**
     * @brief Modifica la categoría de un hijo en la multilista.
     *
     * @param num Número de la categoría a modificar.
     * @param valor Nuevo valor para la categoría.
     * @param indice Índice en el arreglo de hijos a modificar.
     */

    if (num == 1) {
        CambiarCategoria(CEdad,
                         &Hijo::edad,
                         valor,
                         &Hijo::sigEdad,
                         indice,
                         getCabeceraEdad(hijos[indice].edad),
                         &MultilistaHijo::getCabeceraEdad);
    }
}

void MultilistaHijo::OrganizarCategoria(Cabecera<std::string> *&cabecera,
                                        int indiceArray,
                                        int Hijo::*siguienteIndice,
                                        int indiceCabecera) {
    /**
     * @brief Organiza un hijo en la categoría especificada.
     *
     * @param cabecera Cabecera de la categoría.
     * @param indiceArray Índice en el arreglo de hijos.
     * @param siguienteIndice Índice del siguiente hijo en la categoría.
     * @param indiceCabecera Índice de la cabecera de la categoría.
     */

    // Si la cabecera dada está vacía, agrega la posición en la cabecera
    if (cabecera[indiceCabecera].indice == -1) {
        cabecera[indiceCabecera].indice = indiceArray;
    } else {
        // De lo contrario, recorre la categoría hasta encontrar el último elemento
        int indiceC = cabecera[indiceCabecera].indice;
        while (hijos[indiceC].*siguienteIndice != -1) {
            indiceC = hijos[indiceC].*siguienteIndice;
        }

        // Agrega la posición del nuevo hijo al final de la categoría
        hijos[indiceC].*siguienteIndice = indiceArray;
    }
}

void MultilistaHijo::CambiarCategoria(Cabecera<std::string> *&cabecera,
                                      int Hijo::*atributo,
                                      int valor,
                                      int Hijo::*siguienteIndice,
                                      int indiceArray,
                                      int indiceCabeceraAntigua,
                                      int (MultilistaHijo::*getCabecera)(int)) {
    /**
     * @brief Cambia la categoría de un hijo.
     *
     * @param cabecera Cabecera de la categoría.
     * @param atributo Atributo que se cambiará.
     * @param valor Nuevo valor para el atributo.
     * @param siguienteIndice Índice del atributo que se cambiará.
     * @param indiceArray Índice en el arreglo de hijos.
     * @param indiceCabeceraAntigua Índice de la cabecera antigua.
     * @param getCabecera Función para obtener la nueva cabecera.
     */

    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabeceraAntigua].indice;

    // Recorre todo el arreglo hasta la posición dada, guardando la posición anterior
    indiceAnterior = indiceArreglo;
    indiceSiguiente = hijos[indiceArreglo].*siguienteIndice;
    while (indiceArreglo != indiceArray) {
        indiceAnterior = indiceArreglo;
        indiceArreglo = hijos[indiceArreglo].*siguienteIndice;
        indiceSiguiente = hijos[indiceArreglo].*siguienteIndice;
    }

    // Cambia el atributo
    hijos[indiceArray].*atributo = valor;

    // Si la cabecera del elemento que se eliminó estaba en la cabecera,
    // se agrega el que estaba después del eliminado
    if (indiceArreglo == cabecera[indiceCabeceraAntigua].indice) {
        cabecera[indiceCabeceraAntigua].indice = indiceSiguiente;
    } else {
        // De lo contrario, simplemente se une la posición anterior con la siguiente
        hijos[indiceAnterior].*siguienteIndice = indiceSiguiente;
    }

    // Se invoca el método de OrganizarCategoria para que inserte el nuevo valor en la
    // nueva cabecera correspondiente
    OrganizarCategoria(cabecera,
                       indiceArray,
                       siguienteIndice,
                       (this->*getCabecera)(indiceArray));
}

int MultilistaHijo::getCabeceraEdad(int indiceArray) {
    /**
     * @brief Obtiene la cabecera de la categoría de edad para un hijo en específico.
     *
     * @param indiceArray Índice en el arreglo de hijos.
     * @return La cabecera de la categoría de edad.
     */

    int edad = hijos[indiceArray].edad;
    int indiceCabecera;

    if (edad >= 0 && edad <= 5)
        indiceCabecera = 0;
    else if (edad >= 6 && edad <= 10)
        indiceCabecera = 1;
    else if (edad >= 11 && edad <= 18)
        indiceCabecera = 2;
    else
        indiceCabecera = 3;

    return indiceCabecera;
}

void MultilistaHijo::Eliminar(int indiceArray) {
    /**
     * @brief Elimina un hijo de la multilista.
     *
     * @param indiceArray Índice en el arreglo de hijos a eliminar.
     */

    hijos[indiceArray].estado = false;
}

void MultilistaHijo::ImprimirEdad(int edad1, int edad2) {
    /**
     * @brief Imprime la categoría de edad de los hijos en un rango específico.
     *
     * @param edad1 Edad mínima del rango.
     * @param edad2 Edad máxima del rango.
     */

    int indiceCabecera;

    if (edad1 >= 0 && edad2 <= 5) {
        indiceCabecera = 0;
    } else if (edad1 >= 6 && edad2 <= 10) {
        indiceCabecera = 1;
    } else if (edad1 >= 11 && edad2 <= 18) {
        indiceCabecera = 2;
    } else if (edad1 > 18 && edad2 >= edad1) {
        indiceCabecera = 3;
    } else {
        std::cout << "RANGO INVALIDO" << std::endl;
        return;
    }

    int indice = CEdad[indiceCabecera].indice;
    while (indice != -1) {
        std::cout << hijos[indice].nombre << std::endl;
        std::cout << hijos[indice].edad << std::endl;
        indice = hijos[indice].sigEdad;
    }
}

Hijo MultilistaHijo::getHijo(int indiceArray) {
    /**
     * @brief Obtiene un hijo del arreglo.
     *
     * @param indiceArray Índice en el arreglo de hijos.
     * @return El hijo en la posición especificada.
     */

    return hijos[indiceArray];
}

std::string* MultilistaHijo::getElementos()
{
    /**
     * @brief Obtiene un arreglo de nombres de los hijos.
     *
     * @return Un puntero a un arreglo de cadenas de caracteres que contiene los nombres de los hijos.
     */

    std::string* arreglo = new std::string[size];

    for(int i = 0; i < size; i++)
        arreglo[i] = hijos[i].nombre;

    return arreglo;
}

Cabecera<std::string>* MultilistaHijo::getCabecera()
{
    /**
     * @brief Obtiene la cabecera de la multilista.
     *
     * @return Un puntero a la cabecera de la multilista, que organiza los hijos por categoría.
     */

    return CEdad;
}