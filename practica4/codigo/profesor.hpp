#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <cstring>
#include <cassert>
#include "listaAlumnos.hpp"

class Profesor
{

private:

	std::string nombre_;//Nombre del profesor
	int Id_;//Identificador del profesor
	ListaAlumnos agenda_; //Lista de alumnos

	std::string contrasena_;//Contrasena del profesor para iniciar sesion
	
	//Rol del profesor
	//rol=0/false->ayudante
	//rol=1/true->coordinador
	bool rol_;



	std::string getContrasena()const{return contrasena_;};

	void setContrasena(std::string const &ncontrasena){contrasena_=ncontrasena;}

public:

	//Constructor de la clase Profesor
	inline Profesor()
	{
		nombre_="";
		Id_=-1;
		rol_=false;
	}
	inline Profesor(std::string nombre,int Id)
	{
		nombre_=nombre;
		Id_=Id;
		rol_=false;

		#ifndef NDEBUG
			assert(strcmp(nombre_.c_str(),nombre.c_str())==0 and Id_==Id);
		#endif
	}

	//Observadores
	inline std::string getNombre()const{return nombre_;}
	inline int getId()const{return Id_;}
	inline bool getRol()const{return rol_;}
	inline ListaAlumnos getAgenda()const{return agenda_;}
	inline bool comprobarCredenciales(std::string usuario, std::string contrasena)
	{
		if(getNombre().compare(usuario)!=0) return false;

		if(getContrasena().compare(contrasena)!=0) return false;

		return true;
	}

	//Modificadores
	inline void setNombre(std::string const &nNombre)
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
	inline void setAgenda(ListaAlumnos &nAgenda)
	{
		agenda_=nAgenda;
	}

	//Métodos de la clase
	inline void nuevoAlumno(Alumno &nAlumno){agenda_.insertar(nAlumno);}
	inline void modificarAlumno(int &i, Alumno &alumno){agenda_.modificar(i, alumno);}
	inline void eliminarAlumno(int &i){agenda_.eliminar(i);}

	inline Profesor operator=(Profesor const &profesor)
	{
		ListaAlumnos nuevaAgenda;
		nuevaAgenda=profesor.getAgenda();
		setNombre(profesor.getNombre());
		setId(profesor.getId());
		setAgenda(nuevaAgenda);
		setContrasena(profesor.getContrasena());
		setRol(profesor.getRol());

		return *this;
	}


	void leerProfesor();
};

#endif