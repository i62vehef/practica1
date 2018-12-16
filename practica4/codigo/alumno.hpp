#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include "macros.hpp"
#include "Fecha.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

class Alumno
{
private:

	std::string nombre_; //Nombre del alumno
	std::string apellido_; //Apellido del alumno
	int telefono_; //telefono de contacto del alumno
	std::string domicilio_; //domicilio de residencia del alumno durante el curso
	std::string DNI_; //DNI del alumno
	Fecha nacimiento_;//Fecha de nacimiento del alumno
	int curso_; //curso actual del alumno
	std::string email_; //email de contacto del alumno
	int equipo_; //Equipo de trabajo del alumno
	bool lider_;

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
		lider_=false;
	}

	//Constructor parametrizado
	inline Alumno(std::string nombre,std::string apellido,int telefono,std::string domicilio,std::string DNI, Fecha fechaNacimiento, int curso,std::string email,int equipo=0)
	{
        nombre_ = nombre;
        apellido_ = apellido;
        telefono_ = telefono;
        domicilio_ = domicilio;
        DNI_ = DNI;
        nacimiento_=fechaNacimiento;
        curso_ = curso;
        email_ = email;
        equipo_ = equipo;
        lider_=false;
	}

	//Constructor de copia
	inline Alumno(Alumno const &alumno)
	{
		nombre_=alumno.getNombre();
		apellido_=alumno.getApellido();
		telefono_=alumno.getTelefono();
		domicilio_=alumno.getDomicilio();
		DNI_=alumno.getDNI();
		nacimiento_=alumno.getFechaNacimiento();
		curso_=alumno.getCurso();
		email_=alumno.getEmail();
		equipo_=alumno.getEquipo();
		lider_=alumno.esLider();
	}

	//Observadores
	inline std::string getNombre() const{return nombre_;}
	inline std::string getApellido() const{return apellido_;}
	inline int getTelefono()const{return telefono_;}
	inline std::string getDomicilio()const{return domicilio_;}
	inline std::string getDNI()const{return DNI_;}
	inline Fecha getFechaNacimiento()const{return nacimiento_;}
	inline int getCurso()const{return curso_;}
	inline std::string getEmail()const{return email_;}
	inline int getEquipo()const{return equipo_;}
	inline bool esLider()const{return lider_;}

	//Modificadores
	inline void setNombre(std::string const &nNombre)
	{
		nombre_=nNombre;
		#ifndef NDEBUG
			assert(strcmp(getNombre().c_str(),nNombre.c_str())==0);
		#endif
	}
	inline void setApellido(std::string const &nApellido)
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
	inline void setDomicilio(std::string const &nDomicilio)
	{
		domicilio_=nDomicilio;
		#ifndef NDEBUG
			assert(strcmp(getDomicilio().c_str(),nDomicilio.c_str())==0);
		#endif
	}
	inline void setDNI(std::string const &nDNI)
	{
		DNI_=nDNI;
		#ifndef NDEBUG
			assert(strcmp(getDNI().c_str(),nDNI.c_str())==0);
		#endif
	}
	inline void setFechaNacimiento(Fecha const &nFecha)
	{
		nacimiento_=nFecha;
		#ifndef NDEBUG
			assert(getFechaNacimiento()==nFecha);
		#endif
	}
	inline void setCurso(int const &nCurso)
	{
		curso_=nCurso;
		#ifndef NDEBUG
			assert(getCurso()==nCurso);
		#endif		
	}
	inline void setEmail(std::string const &nEmail)
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
	inline void setLider()
	{
		#ifndef NDEBUG
			assert(getEquipo()>0 and getEquipo()<151);
		#endif

		lider_=true;
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

	inline bool operator==(Alumno const &alumno)
	{
		if(strcmp(getApellido().c_str(),alumno.getApellido().c_str())!=0)
			return false;
		if(strcmp(getNombre().c_str(),alumno.getNombre().c_str())!=0)
			return false;
		if(strcmp(getDNI().c_str(),alumno.getDNI().c_str())!=0)
			return false;
		if(getTelefono()!=alumno.getTelefono())
			return false;
		if(strcmp(getDomicilio().c_str(),alumno.getDomicilio().c_str())!=0)
			return false;
		if(getCurso()!=alumno.getCurso())
			return false;
		if(strcmp(getEmail().c_str(),alumno.getEmail().c_str())!=0)
			return false;

		return true;
	}
};

   //Funciones externas de la clase Alumno: sobrecarga de los operadores de flujo

//El formato en que se pasan los datos es
//apellido,nombre DNI fechaNacimiento telefono domicilio curso email ¿eslider?
ostream &operator<<(ostream &stream, Alumno const &alumno);

//el formato para leer es el mismo
istream &operator>>(istream &stream, Alumno &alumno);

#endif