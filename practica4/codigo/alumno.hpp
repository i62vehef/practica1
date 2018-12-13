#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include "macros.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

using namespace std;

class Alumno
{
private:

	string nombre_; //Nombre del alumno
	string apellido_; //Apellido del alumno
	int telefono_; //telefono de contacto del alumno
	string domicilio_; //domicilio de residencia del alumno durante el curso
	string DNI_; //DNI del alumno
	int curso_; //curso actual del alumno
	string email_; //email de contacto del alumno
	int equipo_; //Equipo de trabajo del alumno

public:

	//Constructores de la Clase Alumno
	//Constructor sin parametros
	inline Alumno()
	{
		nombre_="";
		apellido_="";
		telefono_=0;
		domicilio_="";
		DNI_="";
		curso_=0;
		email_="";
		equipo_=0;
	}

	//Constructor parametrizado
	inline Alumno(string nombre,string apellido,int telefono,string domicilio,string DNI,int curso,string email, int equipo=0)
	{
        nombre_ = nombre;
        apellido_ = apellido;
        telefono_ = telefono;
        domicilio_ = domicilio;
        DNI_ = DNI;
        curso_ = curso;
        email_ = email;
        equipo_ = equipo;

        #ifndef NDEBUG
        	assert(strcmp(nombre_.c_str(),nombre.c_str())==0 && strcmp(apellido_.c_str(),apellido.c_str())==0 && telefono_==telefono && strcmp(domicilio_.c_str(),domicilio.c_str())==0 && strcmp(DNI_.c_str(),DNI.c_str())==0 && curso_==curso && strcmp(email_.c_str(),email.c_str())==0 && equipo_==equipo);
        #endif
	}

	//Observadores
	inline string getNombre() const{return nombre_;}
	inline string getApellido() const{return apellido_;}
	inline int getTelefono()const{return telefono_;}
	inline string getDomicilio()const{return domicilio_;}
	inline string getDNI()const{return DNI_;}
	inline int getCurso()const{return curso_;}
	inline string getEmail()const{return email_;}
	inline int getEquipo()const{return equipo_;}

	//Modificadores
	inline void setNombre(string const &nNombre)
	{
		nombre_=nNombre;
		#ifndef NDEBUG
			assert(strcmp(getNombre().c_str(),nNombre.c_str())==0);
		#endif
	}
	inline void setApellido(string const &nApellido)
	{
		apellido_=nApellido;
		#ifndef NDEBUG
			assert(strcmp(getApellido().c_str(),nApellido.c_str())==0);
		#endif
	}
	inline void setTelefono(int const &nTelefono)
	{
		telefono_=nTelefono;
		#ifndef NDEBUG
			assert(getTelefono()==nTelefono);
		#endif
	}
	inline void setDomicilio(string const &nDomicilio)
	{
		domicilio_=nDomicilio;
		#ifndef NDEBUG
			assert(strcmp(getDomicilio().c_str(),nDomicilio.c_str())==0);
		#endif
	}
	inline void setDNI(string const &nDNI)
	{
		DNI_=nDNI;
		#ifndef NDEBUG
			assert(strcmp(getDNI().c_str(),nDNI.c_str())==0);
		#endif
	}
	inline void setCurso(int const &nCurso)
	{
		curso_=nCurso;
		#ifndef NDEBUG
			assert(getCurso()==nCurso);
		#endif		
	}
	inline void setEmail(string const &nEmail)
	{
		email_=nEmail;
		#ifndef NDEBUG
			assert(strcmp(getEmail().c_str(),nEmail.c_str())==0);
		#endif
	}
	inline void setEquipo(int const &nEquipo)
	{
		equipo_=nEquipo;
		#ifndef NDEBUG
			assert(getEquipo()==nEquipo);
		#endif
	}


	//Metodos de la clase Alumno
	void escribir();

	//Operadores
	inline Alumno operator=(Alumno const &alumno)
	{
		setApellido(alumno.getApellido());
		setNombre(alumno.getNombre());
		setDNI(alumno.getDNI());
		setTelefono(alumno.getTelefono());
		setDomicilio(alumno.getDomicilio());
		setCurso(alumno.getCurso());
		setEmail(alumno.getEmail());
		setEquipo(alumno.getEquipo());

		return *this;
	}
};

   //Funciones externas de la clase Alumno: sobrecarga de los operadores de flujo

ostream &operator<<(ostream &stream, Alumno const &alumno);

istream &operator>>(istream &stream, Alumno &alumno);

#endif