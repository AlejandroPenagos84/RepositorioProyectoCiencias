#include "MultilistaSucursales.h"

MultilistaSucursales::MultilistaSucursales(int max) {
    // Inicializar el arreglo de sucursales
    sucursales = new Sucursal[max];

    posLibre = 0;
    size = 0;
}

void MultilistaSucursales::AgregarSucursal(Sucursal sucursal) {
    /**
     * @brief Agrega una nueva sucursal a la multilista.
     *
     * @param sucursal La sucursal a agregar.
     */

    // Agregar la sucursal al arreglo
    sucursales[posLibre] = sucursal;

    // Actualizar el índice libre y el tamaño
    posLibre++;
    size++;
}

void MultilistaSucursales::EliminarSucursal(int indiceArray) {
    /**
     * @brief Elimina una sucursal de la multilista.
     *
     * @param indiceArray Índice en el arreglo de sucursales a eliminar.
     */

    sucursales[indiceArray].estado = false;
    size--;
}

void MultilistaSucursales::ModificarSucursal(int num, std::string nuevoDato, int indiceArray) {
    /**
     * @brief Modifica una propiedad específica de una sucursal en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de sucursales a modificar.
     */

    switch (num) {
        case 1:
            sucursales[indiceArray].nombre = std::move(nuevoDato);
            break;
        case 2:
            sucursales[indiceArray].direccion = std::move(nuevoDato);
            break;
        case 3:
            sucursales[indiceArray].barrio = std::move(nuevoDato);
            break;
        case 4:
            sucursales[indiceArray].nombreGerente = std::move(nuevoDato);
            break;
        default:
            break;
    }
}

Sucursal MultilistaSucursales::getSucursal(int indiceArray) {
    /**
     * @brief Obtiene una sucursal del arreglo.
     *
     * @param indiceArray Índice en el arreglo de sucursales.
     * @return La sucursal en la posición especificada.
     */

    return sucursales[indiceArray];
}

int MultilistaSucursales::getSize() {
    /**
     * @brief Obtiene el tamaño actual del arreglo de sucursales.
     *
     * @return El tamaño actual del arreglo de sucursales.
     */
    return size;
}

std::string* MultilistaSucursales::getElementos() {
    /**
     * @brief Obtiene los elementos del arreglo de sucursales como un arreglo de cadenas.
     *
     * @return Un arreglo de cadenas con los elementos del arreglo de sucursales.
     */

    std::string* arreglo = new std::string[size];

    for (int i = 0; i < size; i++)
        arreglo[i] = sucursales[i].nombre;

    return arreglo;
}
