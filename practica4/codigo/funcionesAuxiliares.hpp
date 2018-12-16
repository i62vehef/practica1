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
#include "Fecha.hpp"
#include <ctime>
#include <sstream>

void introducirAlumno(Profesor &p);

void modificarDatosAlumno(Profesor &p);

void borrarDatosAlumno(Profesor &p);

void mostrarNumeroAlumnos(Profesor &p);

void mostrarDatosdeAlumno(Profesor &p);

void mostrarGrupo(Profesor &p);

void mostrarListaAlumnos(Profesor &p);

void cargarCopia(Profesor &p);

void crearCopia(Profesor &p);

Profesor logIn();

void quicksort(int primero, int ultimo, ListaAlumnos &lista);

int particion(int primero, int ultimo, ListaAlumnos &lista);

int menu(bool &membresia);

#endif
