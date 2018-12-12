#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

#include <vector>
#include "alumno.hpp"

class ListaAlumnos
{


private:

	//Vector con los alumnos
	//Cada elemento es un objeto de la clase Alumno
	//Representa la lista de alumnos de una clase
	vector<Alumno> alumnos_;


public:

	//Constructor de la clase
	inline ListaAlumnos()
	{
		#ifndef NDEBUG
			assert(!tamClase());
		#endif
	}

	//Observadores
	//Devuelve el objeto Alumno que se encuentra en la posicion i de la lista
	inline Alumno getAlumno(int &i)
	{
		#ifndef NDEBUG //precondiciones
			assert(tamClase()>0 and i<tamClase());
		#endif
		return alumnos_[i];
	}
	//Devuelve el numero de alumnos registrados
	inline int tamClase(){return alumnos_.size();}

	//Modificadores
	//setAlumno: asigna un nuevo valor a un alumno especifico
	//param i: posicion en el vector cuyo alumno queremos cambiar
	//param nAlumno: objeto de la clase Alumno con los valores deseados para el alumno
	//Hace las veces de la función para modificar alumno
	inline void setAlumno(int &i, Alumno const &nAlumno)
	{		
		#ifndef NDEBUG //precondiciones
			assert(tamClase()>0 and i<tamClase());
		#endif
		alumnos_[i]=nAlumno;
	}

	//Métodos de la clase
	//insertar: inserta un nuevo alumno en la lista
	inline void insertar(Alumno nAlumno)
	{
		#ifndef NDEBUG //precondiciones
			assert(tamClase()<150);
		#endif
		alumnos_.push_back(nAlumno);
	}

	void eliminar(Alumno c);
	void MostrarAlumno();
	void ListarAlumnos();





};
#endif
