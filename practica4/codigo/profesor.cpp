#include "profesor.hpp"

void Profesor::leerProfesor()
{
	std::string nombre, contrasena;
	int id;
	int rol;

	std::cout<<" Nombre -->";
	std::cin>>nombre;
	std::cout<<" Contrasena -->";
	std::cin>>contrasena;
	std::cout<<" ID -->";
	std::cin>>id;
	std::cout<<" Rol [1-coordinador/2-ayudante]";
	std::cin>>rol;

	if(rol!=1 && rol!=2)
	{
		std::cout<<BIRED<<"ERROR Rol invalido"<<RESET<<std::endl;
		std::cout<<"Introduzca un rol valido"<<std::endl;

		std::cout<<" Rol [1-coordinador/2-ayudante]";
		std::cin>>rol;
	}

	setNombre(nombre);
	setContrasena(contrasena);
	setId(id);
	setRol((bool)(rol-1));
}