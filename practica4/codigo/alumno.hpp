#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Alumno
{
private:

	string nombre_; //Nombre del alumno
	string apellidos_; //Apellidos del alumno
	int telefono_; //telefono de contacto del alumno
	string domicilio_; //domicilio de residencia del alumno durante el curso
	string DNI_; //DNI del alumno
	int curso_; //curso actual del alumno
	string email_; //email de contacto del alumno
	int equipo_; //Equipo de trabajo del alumno

public:

	//Constructor de la Clase Alumno
	inline Alumno(string nombre,string apellidos,int telefono,string domicilio,string DNI,
	int curso,string email, int equipo=0)
	{
        nombre_ = nombre;
        apellidos_ = apellidos;
        telefono_ = telefono;
        domicilio_ = domicilio;
        DNI_ = DNI;
        curso_ = curso;
        email_ = email;
        equipo_ = equipo;

        #ifndef NDEBUG
        	assert(strcmp(nombre_.c_str(),nombre.c_str())==0 && strcmp(apellidos_.c_str(),apellidos.c_str())==0 && telefono_==telefono && strcmp(domicilio_.c_str(),domicilio.c_str())==0 && strcmp(DNI_.c_str(),DNI.c_str())==0 && curso_==curso && strcmp(email_.c_str(),email.c_str())==0 && equipo_==equipo);
        #endif
	}

	//Observadores
	inline string getNombre() const{return nombre_;}
	inline string getApellidos() const{return apellidos_;}
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
	inline void setApellidos(string const &nApellidos)
	{
		apellidos_=nApellidos;
		#ifndef NDEBUG
			assert(strcmp(getApellidos().c_str(),nApellidos.c_str())==0);
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

};

   //Funciones externas de la clase Material: sobrecarga de los operadores de flujo

ostream &operator<<(ostream &stream, Material const &material);

istream &operator>>(istream &stream, Material &material);

#endif