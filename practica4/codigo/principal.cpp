#include "funcionesAuxiliares.hpp"
#include "listaAlumnos.hpp"
#include "profesor.hpp"
#include "macros.hpp"


int main(int argc, char ** argv)
{
	std::system("clear");
	int opcion;

	bool logged=false;
	bool coordinador=false;

	Profesor tutor=logIn();

	if(tutor.getId()==-1)
	{
		std::cout<<BIRED<<"ERROR Inicio de sesion invalido"<<RESET<<std::endl;
		std::cin.ignore();
		return -1;
	}

	if(!logged)
	{
		std::cout<<BIRED<<"Debe iniciar sesion antes de acceder a cualquier funcion del sistema"<<RESET<<std::endl;
		std::cin.ignore();
		return -1;
	}

	switch((int)coordinador)
	{
		case 0://ayudante
			do
			{
				opcion=menu(coordinador);
				switch(opcion)
				{
					case 0:
					break;
					case 1://Cargar datos de un fichero
						cargarCopia(tutor);
						std::cin.ignore();
					break;
					case 2://Guardar datos en un fichero
						crearCopia(tutor);
						std::cin.ignore();
					break;
					case 3://Introducir alumno
						introducirAlumno(tutor);
						std::cin.ignore();
					break;
					case 4://Modificar datos de un alumno
						modificarDatosAlumno(tutor);
						std::cin.ignore();
					break;
					case 5://Borrar alumno
						borrarDatosAlumno(tutor);
						std::cin.ignore();
					break;
					case 6://Mostrar numero de alumnos registrados
						mostrarNumeroAlumnos(tutor);
						std::cin.ignore();
					break;
					case 7://Mostrar datos de un alumno
						mostrarDatosdeAlumno(tutor);
						std::cin.ignore();
					break;
					case 8://Mostrar grupo
						mostrarGrupo(tutor);
						std::cin.ignore();
					break;
					case 9://Mostrar lista de alumnos
						mostrarListaAlumnos(tutor);
						std::cin.ignore();
					break;														
					default:
						std::cout<<BIRED<<"ERROR en la opcion del menu"<<RESET<<std::endl;
						std::cin.ignore();
				}
			}while(opcion!=0);
		break;
		
		case 1://coordinador
			do
			{
				opcion=menu(coordinador);
				switch(opcion)
				{
					case 0:
					break;
					case 1://Cargar datos de un fichero
						cargarCopia(tutor);
						std::cin.ignore();
					break;
					case 2://Guardar datos en un fichero
						crearCopia(tutor);
						std::cin.ignore();
					break;
					case 3://Introducir alumno
						introducirAlumno(tutor);
						std::cin.ignore();
					break;
					case 4://Modificar datos de un alumno
						modificarDatosAlumno(tutor);
						std::cin.ignore();
					break;
					case 5://Borrar alumno
						borrarDatosAlumno(tutor);
						std::cin.ignore();
					break;
					case 6://Mostrar numero de alumnos registrados
						mostrarNumeroAlumnos(tutor);
						std::cin.ignore();
					break;
					case 7://Mostrar datos de un alumno
						mostrarDatosdeAlumno(tutor);
						std::cin.ignore();
					break;
					case 8://Mostrar grupo
						mostrarGrupo(tutor);
						std::cin.ignore();
					break;
					case 9://Mostrar lista de alumnos
						mostrarListaAlumnos(tutor);
						std::cin.ignore();
					break;
					case 10://Registrar nuevo profesor

						std::cin.ignore();
					break;
					case 11://Cargar copia de seguridad
						cargarCopia(tutor);
						std::cin.ignore();
					break;
					case 12://Crear copia de seguridad
						crearCopia(tutor);
						std::cin.ignore();
					break;															
					default:
						std::cout<<BIRED<<"ERROR en la opcion del menu"<<RESET<<std::endl;
						std::cin.ignore();
				}
			}while(opcion!=0);
		break;
	}
	return 0;
}