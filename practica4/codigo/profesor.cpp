#include "profesor.hpp"

void Profesor::leerProfesor()
{
	std::string nombre, contrasena;
	int id;
	int rol;

	std::cout<<" Nombre --> ";
	std::cin>>nombre;
	std::cout<<" Contrasena --> ";
	std::cin>>contrasena;
	std::cout<<" ID --> ";
	std::cin>>id;
	std::cout<<" Rol [1-ayudante/2-coordinador]\n ";
	std::cin>>rol;

	if(rol!=1 && rol!=2)
	{
		std::cout<<BIRED<<"ERROR Rol invalido"<<RESET<<std::endl;
		std::cout<<"Introduzca un rol valido"<<std::endl;

		std::cout<<" Rol [1-ayudante/2-coordinador]";
		std::cin>>rol;
	}

	setNombre(nombre);
	setContrasena(contrasena);
	setId(id);
	setRol((bool)(rol-1));
}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Profesor const &profesor)
{

	stream<<profesor.getNombre()<<','<<profesor.getContrasena()<<','<<profesor.getId()<<','<<profesor.getRol()<<std::endl;

	return stream;
}

istream &operator>>(istream &stream, Profesor &profesor)
{

	std::string str1;

	std::getline(stream, str1, ' ');
	profesor.setNombre(str1);

	std::getline(stream, str1, ' ');
	profesor.setContrasena(str1);

	std::getline(stream, str1, ' ');
	profesor.setId(atoi(str1.c_str()));

	std::getline(stream, str1, '\n');
	if(atoi(str1.c_str())<0 || atoi(str1.c_str())>1)
		profesor.setRol(0);
	else
		profesor.setRol(atoi(str1.c_str()));

	return stream;
}