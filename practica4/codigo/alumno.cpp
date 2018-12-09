#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include "alumno.h"
using namespace std;



Alumno::Alumno(string nombre,string apellidos,int telefono,string domicilio,string DNI,int curso,string email)
{

            nombre_ = nombre;
            apellidos_ = apellidos;
            telefono_ = telefono;
            domicilio_ = domicilio;
            DNI_ = DNI;
            curso_ = curso;
            email_ = email;

}

void Alumno::setNombre(string &nombre)
{
    if(nombre=="")
    {
        
    }else
        {
            nombre_ = nombre;
        }
}

void Alumno::setApellidos(string &apellidos)
{
    if(apellidos=="")
    {
        
    }else
    {
        apellidos_ = apellidos;

    }
}

void Alumno::setTelefono(int telefono)
{
    if(telefono=="")
    {

    }else
    {
        telefono_ = telefono;
    }
}

void Alumno::setDomicilio(string domicilio)
{

        if(domicilio=="")
        {

        }else
            {
             domicilo_ = domicilio;
            }

}

void Alumno::setDNI(string DNI)
{
    if(DNI=="")
    {

    }else
        {
            DNI_ = DNI;
        }
}

void Alumno::setCurso(int curso)
{

    if(curso=="")
    {

    }else
        {
            curso_ = curso;
        }
}

void Alumno::setEmail(string email)
{

        if(email=="")
        {

        }else 
            {
                email_ = email;
            }
}

