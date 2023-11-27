#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include "Formulario.h"
#include <limits>
#include "../Controlador/Controlador.h"

class Controlador;
class Vista
{
private:
    Formulario formulario;
    Controlador* controlador;

public:
    Vista(Controlador* ctrl);
    int MostrarMenu();
    void IngresarDatos();
    void MenuGlobal();
    int MenuConsultas();
    int MostrarElementos(std::string* arreglo, int tam);
    int MenuMostrarRangosNumHijos();
    void MenuPrimeraConsulta(int* arreglo);
    int PedirElemento();
    void ElegirConsulta();

    static void Imprimir(std::string m);

private:

};

#endif
