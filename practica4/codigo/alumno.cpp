#include "alumno.hpp"

void Alumno::escribir()
{
	std::cout<<BIYELLOW<<"\nDatos del alumno"<<RESET<<std::endl;
	std::cout<<getApellido()<<", "<<getNombre()<<std::endl;
	std::cout<<"DNI: "<<getDNI()<<std::endl;
	if(getEquipo()!=0) 
	{
		std::cout<<"Grupo: "<<getEquipo();
		if(esLider()) std::cout<<" (lider)";
	}
	else std::cout<<"Grupo: No Asignado";
	std::cout<<"\nCurso: "<<getCurso()<<std::endl;
	std::cout<<"Fecha de nacimiento: ";
	getFechaNacimiento().escribirFecha();

	std::cout<<BICYAN<<"\nDatos de contacto"<<RESET<<std::endl;
	std::cout<<"Correo: "<<getEmail()<<std::endl;
	std::cout<<"Telefono: "<<getTelefono()<<std::endl;
	std::cout<<"Domicilio: "<<getDomicilio()<<std::endl;

}

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, Alumno const &alumno)
{

	stream<<alumno.getApellido()<<","<<alumno.getNombre()<<" "<<alumno.getDNI()<<" "<<alumno.getFechaNacimiento()<<" "<<alumno.getTelefono()<<" "<<alumno.getDomicilio()<<" "<<alumno.getCurso()<<" "<<alumno.getEmail()<<" "<<alumno.getEquipo();

	if(alumno.esLider()) stream<<" lider\n";
	else stream<<" normal\n";

	return stream;
}

istream &operator>>(istream &stream, Alumno &alumno)
{

	std::string str1;

	std::getline(stream, str1, ',');
	alumno.setApellido(str1);

	std::getline(stream, str1, ' ');
	alumno.setNombre(str1);

	std::getline(stream, str1, ' ');
	alumno.setDNI(str1);
	
	std::getline(stream,str1,'-');
    int dia=atoi(str1.c_str());

	std::getline(stream,str1,'-');
    int mes=atoi(str1.c_str());

	std::getline(stream,str1,' ');
    int anyo=atoi(str1.c_str());

	Fecha *aux= new Fecha(dia, mes, anyo);
	if(aux->esCorrecta())
		alumno.setFechaNacimiento(*aux);

	std::getline(stream, str1, ' ');
	alumno.setTelefono(atoi(str1.c_str()));

	std::getline(stream, str1, ' ');
	alumno.setDomicilio(str1);

	std::getline(stream, str1, ' ');
	alumno.setCurso(atoi(str1.c_str()));

	std::getline(stream, str1, ' ');
	alumno.setEmail(str1);

	std::getline(stream, str1, ' ');
	if(atoi(str1.c_str())>0 && atoi(str1.c_str())<=150)
		alumno.setEquipo(atoi(str1.c_str()));

	std::getline(stream, str1, '\n');
	if(str1.compare("lider")==0) alumno.setLider();
	
	return stream;
}