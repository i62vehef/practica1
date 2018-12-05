#include "funcionesAuxiliares.hpp"
#include "macros.hpp"


int main(int argc, char ** argv)
{
	int opcion;

	do
	{
		opcion=menu();
		switch(opcion)
		{
			case 0:
			break;
			case 1://Cargar datos de un fichero
				
				std::cin.ignore();
			break;
			case 2://Guardar datos en un fichero
				
				std::cin.ignore();
			break;
			case 3://Introducir alumno

				std::cin.ignore();
			break;
			case 4://Modificar datos de un alumno

				std::cin.ignore();
			break;
			case 5://Borrar alumno

				std::cin.ignore();
			break;
			case 6://Mostrar datos de un alumno

				std::cin.ignore();
			break;
			case 7://Mostrar grupo

				std::cin.ignore();
			break;
			case 8://Mostrar lista de alumnos

				std::cin.ignore();
			break;
			case 9://Registrar nuevo profesor

				std::cin.ignore();
			break;															
			default:
				std::cout<<BIRED<<"ERROR en la opcion del menu"<<RESET<<std::endl;
				std::cin.ignore();
		}
	}while(opcion!=0);
	return 0;
}