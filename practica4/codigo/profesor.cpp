#include <iostrema>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "profesor.h"



Profesor::Profesor(string nombre,int Id)
{

        nombre_ = nombre;

       if(Id=="")
       {
           
       }else 
        {
            
            Id_ = Id;
        }


}

void Profesor::setNombre(string &nombre)
{

    if(nombre=="" || nombre!=nombre_)
    {

    }else
    {
        nombre_ = nombre;
    }
    
}

void Profesor::setId(int Id)
{
        if(Id=="" || Id!=Id_)
        {

        }else 
            {
                Id_ = Id;
            }
}

bool getRol(bool rol)
{
    if(rol=="")
    {
        return false;
    }else
        {
            rol_ = rol;
            return true;
        }
}
void setRol(bool rol)
{



}