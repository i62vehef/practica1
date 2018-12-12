#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <cstring>
#include <cassert>
#include "listaAlumnos.hpp"
using namespace std;


class Profesor
{

private:

	string nombre_;//Nombre del profesor
	int Id_;//Identificador del profesor
	ListaAlumnos *agenda; //Lista de alumnos
	bool rol_;//Rol del profesor

public:

	//Constructor de la clase Profesor
	inline Profesor(string nombre,int Id)
	{
		nombre_=nombre;
		Id_=Id;

		#ifndef NDEBUG
			assert(strcmp(nombre_.c_str(),nombre.c_str())==0 and Id_==Id);
		#endif
	}

	//Observadores
	inline string getNombre()const{return nombre_;}
	inline int getId()const{return Id_;}
	inline bool getRol()const{return rol_;}

	//Modificadores
	inline void setNombre(string const &nNombre)
	{
		nombre_=nNombre;
		#ifndef NDEBUG
			assert(strcmp(getNombre().c_str(),nNombre.c_str())==0);
		#endif
	}
	inline void setId(int const &nId)
	{
		Id_=nId;
		#ifndef NDEBUG
			assert(Id_==nId);
		#endif
	}
	inline void setRol(bool const &nRol)
	{
		rol_=nRol;
		#ifndef NDEBUG
			assert(rol_==nRol);
		#endif
	}

	//Métodos de la clase
	void GuardaFichero();
	void CargarFichero();
	void GuardarCopia();
	void CrearCopia();

};

#endif