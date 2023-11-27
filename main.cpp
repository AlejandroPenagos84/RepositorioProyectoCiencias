#include <iostream>
#include "Controlador/Controlador.h"
#include <locale>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char **argv)
{
    std::locale::global(std::locale(""));
	Controlador controlador;
    controlador.MostrarMenu();

	return 0;
}
