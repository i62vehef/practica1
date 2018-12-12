#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP

#include "macros.hpp"
#include <iostream>
#include <fstream>
#include "listaAlumnos.hpp"

void introducirAlumno();

void cargarClasedeFichero(ListaAlumnos &lista);

void quicksort(int primero, int ultimo, ListaAlumnos &vector);

int partition(int primero, int ultimo, ListaAlumnos &vector);

int menu();

#endif
