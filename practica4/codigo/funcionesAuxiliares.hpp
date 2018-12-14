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

//void cargarClasedeFichero(Profesor &p);

void introducirAlumno(Profesor &p);

void modificarDatosAlumno(Profesor &p);

void mostrarNumeroAlumnos(Profesor &p);

void mostrarDatosdeAlumno(Profesor &p);

void quicksort(int primero, int ultimo, ListaAlumnos &lista);

int particion(int primero, int ultimo, ListaAlumnos &lista);

int menu();

#endif
