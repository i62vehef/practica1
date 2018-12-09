#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <string>
using namespace std;


class Profesor{


private:

string nombre_;
int Id_:
*ptr agenda_;
bool rol_;

public:

Profesor(string nombre_,int Id);
inline string getNombre(){return nombre_;}
inline int setId(){return Id_;}
bool getRol(bool rol);
void setNombre(string nombre);
void setId(int Id);
void setRol(bool rol);
void GuardaFichero();
void CargarFichero();
void GuardarCopia();
void CrearCopia();

};
#endif