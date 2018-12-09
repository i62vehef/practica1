#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string>
using namespace std;

class Alumno{


private:

string nombre_;
string apellidos_;
int telefono_;
string domicilio_;
string DNI_;
int curso_;
string email_;


public:

ALumno(string nombre="NO_ASINGADO",string apellidos="NO_ASIGANDO",int telefono="NO_ASIGNADO",string domicilio="NO_ASIGNADO",string DNI="NO_ASIGNADO",
int curso="NO_ASIGNADO",string email="NO_ASIGNADO");
inline string getNombre(){return nombre_;}
inline string apellidos(){return apellidos_;}
inline int getTelefono(){return telefono_;}
inline string getDomicilio(){return domicilio_;}
inline string getDNI(){return DNI_;}
inline int getCurso(){return curso_;}
inline string getEmail(){return email_;}
void setNombre(string nombre);          
void setApellidos(string apellidos);
void setTelefono(int telefono);
void setDomicilio(string domicilio);
void setDNI(string DNI);
void setCurso(int curso);
void setEmail(string email);
};

#endif