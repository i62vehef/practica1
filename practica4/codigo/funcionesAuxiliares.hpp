#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP

#include "macros.hpp"
#include <iostream>
#include <fstream>
#include "listaAlumnos.hpp"
#include "alumno.hpp"
#include <cstdio>
#include <cstdlib>
#include "profesor.hpp"

//void introducirAlumno();

void cargarClasedeFichero(Profesor &p);

void quicksort(int primero, int ultimo, ListaAlumnos &lista);

int particion(int primero, int ultimo, ListaAlumnos &lista);

int menu();

#endif
