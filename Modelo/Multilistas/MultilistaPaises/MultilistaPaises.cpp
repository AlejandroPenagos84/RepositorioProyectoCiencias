#include "MultilistaPaises.h"

#include <utility>

MultilistaPaises::MultilistaPaises(int max) {
    /**
     * @brief Constructor de la clase.
     *
     * @param max Tamaño máximo del arreglo de países.
     */

    paises = new Pais[max];
    posLibre = 0;
    size = 0;
}

void MultilistaPaises::AgregarPais(Pais pais) {
    /**
     * @brief Agrega un país a la multilista.
     *
     * @param nombre Nombre del país.
     */

    // Crear una nueva multilista de ciudades para el país

    paises[posLibre] = std::move(pais);


    // Incrementar posición libre y tamaño
    posLibre++;
    size++;
}

void MultilistaPaises::EliminarPais(int indiceArray) {
    /**
     * @brief Elimina un país de la multilista.
     *
     * @param indiceArray Índice en el arreglo de países a eliminar.
     */

    paises[indiceArray].estado = false;
    size--;
}

void MultilistaPaises::ModificarPais(int num, std::string nuevoDato, int indiceArray) {
    /**
     * @brief Modifica un país en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de países a modificar.
     */

    if (num == 1) {
        paises[indiceArray].nombre = nuevoDato;
    }
}

Pais MultilistaPaises::getPais(int indiceArray) {
    /**
     * @brief Obtiene un país del arreglo.
     *
     * @param indiceArray Índice en el arreglo de países.
     * @return El país en la posición especificada.
     */

    return paises[indiceArray];
}

int MultilistaPaises::getSize() {return size;}

std::string* MultilistaPaises::getElementos()
{
    std::string* arreglo = new std::string[size];

    for(int i =0; i<size;i++)
        arreglo[i] = paises[i].nombre;

    return arreglo;
}