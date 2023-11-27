#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include "Formulario.h"
#include <limits>

class Vista
{
private:
    Formulario formulario;

public:
    Vista();
    int MostrarMenu();
    void IngresarDatos();
    void MenuGlobal();
    void MenuConsultas();
    int MostrarElementos(std::string* arreglo, int tam);
    int MenuMostrarRangosNumHijos();
    void MenuPrimeraConsulta(int* arreglo);
    int PedirElemento();


    static void Imprimir(std::string m);

private:

};

#endif
