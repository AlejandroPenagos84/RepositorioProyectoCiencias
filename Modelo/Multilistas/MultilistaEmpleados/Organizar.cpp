#include "MultilistaEmpleados.h"

/**
 * @brief Organiza un empleado por sexo en la multilista.
 *
 * Este método organiza un empleado en la categoría correspondiente al sexo
 * en la multilista, ya sea en la categoría de masculino ('M') o femenino ('F').
 *
 * @param indiceArrayEmpleado Índice del empleado en el arreglo.
 */
void MultilistaEmpleados::OrganizarSexo(int indiceArrayEmpleado) {
    int indiceSexo = (empleados[indiceArrayEmpleado].sexo == 'M') ? 0 : 1;

    if (CSexo[indiceSexo].indice == -1)
        CSexo[indiceSexo].indice = indiceArrayEmpleado;
    else {
        int indice = CSexo[indiceSexo].indice;

        while (empleados[indice].sigSexo != -1)
            indice = empleados[indice].sigSexo;

        empleados[indice].sigSexo = indiceArrayEmpleado;
    }

    if(indiceSexo==0)
        numHombres++;
    else if(indiceSexo==1)
        numMujeres++;
}

/**
 * @brief Reorganiza la multilista después de agregar un empleado.
 *
 * Este método reorganiza la multilista después de agregar un nuevo empleado,
 * asegurándose de que los datos estén organizados en las cabeceras y los árboles
 * correspondientes.
 *
 * @param arbol Árbol asociado al atributo.
 * @param cabecera Cabecera asociada al atributo.
 * @param atributo Puntero al atributo que se organizará.
 * @param indiceAtributo Índice del atributo.
 * @param siguienteAtributo Puntero al siguiente índice del atributo.
 * @param indiceArray Índice del empleado en el arreglo.
 */
void MultilistaEmpleados::Reorganizar(RBTree<std::string, int> *&arbol,
                                      Cabecera<std::string> *&cabecera,
                                      std::string Empleado::*atributo,
                                      int &indiceAtributo,
                                      int Empleado::*siguienteAtributo,
                                      int indiceArray) {
    if (arbol->findNodo(empleados[indiceArray].*atributo) != nullptr) {
        int indiceCabecera =
                cabecera[arbol->findNodo(empleados[indiceArray].*atributo)->otroDato]
                        .indice;
        while (empleados[indiceCabecera].*siguienteAtributo != -1)
            indiceCabecera = empleados[indiceCabecera].*siguienteAtributo;

        empleados[indiceCabecera].*siguienteAtributo = indiceArray;
    } else {
        cabecera[indiceAtributo].atributo = empleados[indiceArray].*atributo;
        cabecera[indiceAtributo].indice = indiceArray;
        arbol->Insert(arbol, arbol->createNodo(empleados[indiceArray].*atributo,
                                               indiceAtributo));
        indiceAtributo++;
    }
}

/**
 * @brief Organiza un empleado en la categoría especificada en la multilista.
 *
 * Este método organiza un empleado en la categoría correspondiente en la multilista,
 * utilizando la cabecera proporcionada.
 *
 * @param cabecera Cabecera de la categoría.
 * @param indiceArray Índice del empleado en el arreglo.
 * @param siguienteIndice Puntero al siguiente índice del empleado.
 * @param indiceCabecera Índice de la cabecera de la categoría.
 */
void MultilistaEmpleados::OrganizarCategoria(
        Cabecera<std::string> *&cabecera,
        int indiceArray,
        int Empleado::*siguienteIndice,
        int indiceCabecera) {

    if (cabecera[indiceCabecera].indice == -1) {
        cabecera[indiceCabecera].indice = indiceArray;
    } else {
        int indiceC = cabecera[indiceCabecera].indice;
        while (empleados[indiceC].*siguienteIndice != -1)
            indiceC = empleados[indiceC].*siguienteIndice;

        empleados[indiceC].*siguienteIndice = indiceArray;
    }
}