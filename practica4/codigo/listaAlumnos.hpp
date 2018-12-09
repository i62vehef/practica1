#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <list>


class listaAlunmnos{


private:

list<Alumno> alumnos[150]_;



public:

listaAlumnos();
void AnadirAlumno(Alumno c);
void ModificarAlumno(Alumno c);
void EliminarAlumno(Alumno c);
void MostrarAlumno();
void ListarAlumnos();





};
#endif

