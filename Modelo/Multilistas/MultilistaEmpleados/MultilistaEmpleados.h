#ifndef MULTILISTAEMPLEADOS_H
#define MULTILISTAEMPLEADOS_H

#include "../../Estructuras/Empleado.h"
#include "../../Librerias/Arbol.h"
#include "../../Librerias/Cabecera.h"
#include<vector>

class MultilistaEmpleados {
private:
    Empleado *empleados;  // Arreglo de empleados

    // Arreglos de Cabeceras para diferentes atributos
    Cabecera<char> *CSexo;
    Cabecera<std::string> *CActividadLaboral;
    Cabecera<std::string> *CCiudadNacimiento;
    Cabecera<std::string> *CBarrio;
    Cabecera<std::string> *CSucursal;
    Cabecera<std::string> *CNumeroHijos;
    Cabecera<std::string> *CEdad;

    // PosicionLibre para rastrear la siguiente posición disponible en el arreglo de empleados
    int posLibre;

    // Indices de las cabeceras donde se manejan datos tipo string
    int indiceActividadLaboral;
    int indiceCiudadNacimiento;
    int indiceBarrio;
    int indiceSucursal;

    // Size para mantener el número actual de empleados
    int size;

    // Arboles para los datos tipo string, estos arboles sirven para optimizar búsquedas
    // en caso de que alguna de las listas de cabeceras se vuelva larga
    RBTree<std::string, int> *arbolActividad;
    RBTree<std::string, int> *arbolCiudadNacimiento;
    RBTree<std::string, int> *arbolBarrio;
    RBTree<std::string, int> *arbolSucursales;

    // Numero de Hombres Y Mujeres
    int numHombres;
    int numMujeres;
public:
    int getNumHombres();

    int getNumMujeres();

public:
    /**
     * @brief Constructor de la clase MultilistaEmpleados.
     *
     * @param max Número máximo de empleados que puede manejar la multilista.
     */
    explicit MultilistaEmpleados(int max);

    /**
     * @brief Método para agregar un nuevo empleado a la multilista.
     *
     */
    void AgregarEmpleado(Empleado empleado);


    /**
     * @brief Método para modificar atributos específicos de un empleado.
     *
     * @param num Número que indica el tipo de atributo a modificar.
     * @param nuevoDato Nuevo valor del atributo.
     * @param indice Índice del empleado en el arreglo.
     */
    void ModificarAtributo(int num, std::string &nuevoDato, int indice);

    /**
     * @brief Método para modificar la categoría de un atributo específico de un empleado.
     *
     * @param num Número que indica el tipo de atributo a modificar.
     * @param valor Nuevo valor para el atributo.
     * @param indice Índice del empleado en el arreglo.
     */
    void ModificarCategoria(int num, int valor, int indice);

    /**
     * @brief Método para modificar atributos de tipo string de un empleado.
     *
     * @param num Número que indica el tipo de atributo a modificar.
     * @param indice Índice del empleado en el arreglo.
     * @param nuevoDato Nuevo valor del atributo.
     */
    void ModificarS(int num, int indice, std::string nuevoDato);

    /**
     * @brief Método para modificar atributos de tipo char de un empleado.
     *
     * @param num Número que indica el tipo de atributo a modificar.
     * @param indice Índice del empleado en el arreglo.
     * @param nuevoDato Nuevo valor del atributo.
     */
    void ModificarC(int num, int indice, char nuevoDato);

    /**
     * @brief Método para obtener el tamaño actual del arreglo de empleados.
     *
     * @return Tamaño del arreglo de empleados.
     */
    int getNumEmpleados();

    /**
     * @brief Método para imprimir empleados según su género.
     *
     * @param sexo Género de los empleados a imprimir.
     */
    void ImprimirSexo(char sexo);

    /**
     * @brief Método para imprimir empleados según su actividad laboral.
     *
     * @param actividad Actividad laboral de los empleados a imprimir.
     */
    void ImprimirActividad(std::string actividad);

    /**
     * @brief Método para imprimir empleados según el número de hijos en un rango específico.
     *
     * @param min Número mínimo de hijos.
     * @param max Número máximo de hijos.
     */
    void ImprimirEmpleadosPorNumHijos(int min, int max);

    /**
     * @brief Método para eliminar un empleado del arreglo.
     *
     * @param indiceArray Índice del empleado en el arreglo.
     */
    void Eliminar(int indiceArray);

    /**
     * @brief Getter para obtener un empleado del arreglo.
     *
     * @param indiceArray Índice del empleado en el arreglo.
     * @return Objeto Empleado correspondiente al índice.
     */
    Empleado getEmpleado(int indiceArray);

    Cabecera<std::string> *getArreglosRangoHijos();

    Cabecera<std::string> *getCActividadLaboral() const;

    Cabecera<std::string> *getCCiudadNacimiento() const;

private:
    // Métodos privados para organizar y cambiar atributos en la multilista

    /**
     * @brief Método para organizar un empleado según su género.
     *
     * @param indiceArrayEmpleado Índice del empleado en el arreglo.
     */
    void OrganizarSexo(int indiceArrayEmpleado);

    /**
     * @brief Método para reorganizar un empleado en la lista de cabeceras.
     *
     * @param arbol Arbol del atributo.
     * @param cabecera Cabecera del atributo.
     * @param atributo Puntero al atributo.
     * @param indiceAtributo Índice del atributo.
     * @param siguienteAtributo Puntero al siguiente índice.
     * @param indiceArray Índice del empleado en el arreglo.
     */
    void Reorganizar(RBTree<std::string, int> *&arbol,
                     Cabecera<std::string> *&cabecera,
                     std::string Empleado::*atributo,
                     int &indiceAtributo,
                     int Empleado::*siguienteAtributo,
                     int indiceArray);

    /**
     * @brief Método para organizar un empleado según una categoría específica.
     *
     * @param cabecera Cabecera del atributo.
     * @param indiceArray Índice del empleado en el arreglo.
     * @param siguienteIndice Puntero al siguiente índice del atributo.
     * @param indiceCabecera Índice de la cabecera.
     */
    void OrganizarCategoria(Cabecera<std::string> *&cabecera,
                            int indiceArray,
                            int Empleado::*siguienteIndice,
                            int indiceCabecera);

    /**
     * @brief Método para cambiar un atributo específico de un empleado.
     *
     * @param arbol Arbol del atributo.
     * @param atributo Puntero al atributo.
     * @param nuevoValor Nuevo valor del atributo.
     * @param siguienteIndice Puntero al siguiente índice del atributo.
     * @param cabecera Cabecera del atributo.
     * @param indiceArrayEmpleado Índice del empleado en el arreglo.
     * @param indiceCabecera Índice de la cabecera.
     * @param nuevoAtributoIndice Índice que hace referencia a los índices de las cabeceras.
     */
    void CambiarAtributo(RBTree<std::string, int> *&arbol,
                         std::string Empleado::*atributo,
                         std::string nuevoValor,
                         int Empleado::*siguienteIndice,
                         Cabecera<std::string> *&cabecera,
                         int indiceArrayEmpleado,
                         int indiceCabecera,
                         int &nuevoAtributoIndice);

    /**
     * @brief Método para cambiar la categoría de un atributo específico de un empleado.
     *
     * @param cabecera Cabecera del atributo.
     * @param atributo Puntero al atributo.
     * @param valor Nuevo valor para el atributo.
     * @param siguienteIndice Puntero al siguiente índice del atributo.
     * @param indiceArray Índice del empleado en el arreglo.
     * @param indiceCabeceraAntigua Índice de la cabecera antigua.
     * @param getCabecera Función para obtener la nueva cabecera.
     */
    void CambiarCategoria(Cabecera<std::string> *&cabecera,
                          int Empleado::*atributo,
                          int valor,
                          int Empleado::*siguienteIndice,
                          int indiceArray,
                          int indiceCabeceraAntigua,
                          int (MultilistaEmpleados::*getCabecera)(int));

    /**
     * @brief Método para cambiar atributos de tipo string de un empleado.
     *
     * @param atributo Puntero al atributo.
     * @param indiceArray Índice del empleado en el arreglo.
     * @param nuevoDato Nuevo valor del atributo.
     */
    void CambiarS(std::string Empleado::*atributo, int indiceArray, std::string nuevoDato);

    /**
     * @brief Método para cambiar atributos de tipo char de un empleado.
     *
     * @param atributo Puntero al atributo.
     * @param indiceArray Índice del empleado en el arreglo.
     * @param nuevoDato Nuevo valor del atributo.
     */
    void CambiarC(char Empleado::*atributo, int indiceArray, char nuevoDato);

    /**
     * @brief Getter para obtener la cabecera correspondiente según el número de hijos.
     *
     * @param indiceArray Índice del empleado en el arreglo.
     * @return Índice de la cabecera.
     */
    int getCabeceraNumHijos(int indiceArray);

    /**
     * @brief Getter para obtener la cabecera correspondiente según la edad.
     *
     * @param indiceArray Índice del empleado en el arreglo.
     * @return Índice de la cabecera.
     */
    int getCabeceraEdad(int indiceArray);


};

#endif
