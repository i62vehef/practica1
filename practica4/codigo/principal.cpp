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
			case 1:
				
			break;
			case 2:
				
			break;
			default:
				std::cout<<BIRED<<"ERROR en la opcion del menu"<<RESET<<std::endl;
				std::cin.ignore();
		}
	}while(opcion!=0);
	return 0;
}