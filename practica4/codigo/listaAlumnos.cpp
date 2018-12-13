#include "listaAlumnos.hpp"

std::vector<Alumno> ListaAlumnos::buscarAlumno(int const &criterio, string &valor)
{
	//vector auxiliar para guardar los alumnos encontrados
	//valdría con una variable Alumno si solo existe un alumno
	std::vector<Alumno> aux(0);

	//variable para elegir el alumno en caso de coincidencia multiple
	int opcion=0;

	//switch para buscar segun un criterio u otro
	switch(criterio)
	{
		case 1://DNI

			for(int i=0;i<tamClase();i++)//Busqueda del alumno
			{
				if(strcmp(getAlumno(i).getDNI().c_str(),valor.c_str())==0)
					aux.push_back(getAlumno(i));
			}

			if(aux.size()>1)//Solo deberia haber un unico alumno con el mismo DNI
			{
				std::cout<<BIRED<<"ERROR se han encontrado mas de un alumno con el mismo DNI"<<RESET<<std::endl;
				return NULL;
			}
			else
				return aux;
		break;
		case 2://Apellidos

			//Se busca el alumno
			for(int i=0;i<tamClase();i++)
			{
				if(strcmp(getAlumno(i).getDNI().c_str(),valor.c_str())==0)
					aux.push_back(getAlumno(i));
			}

			//Comprobacion del numero de alumnos encontrados
			if(aux.size()>1)
			{
				std::cout<<BIRED<<"Se han encontrado mas de un alumno con Apellidos coincidentes"<<RESET<<std::endl;

				//Seleccion del alumno deseado
				std::cout<<"Los alumnos son los siguientes:"<<std::endl;
				std::cout<<"(Selecciona mediante el indice indicado el alumno que buscaba)"<<std::endl;

				for(int i=0;i<aux.size();i++)
					std::cout<<" ["<<i+1<<"] " << aux[i].getApellidos() << "," << aux[i].getNombre() << "\n\tDNI: " <<aux[i].getDNI() << std::endl;
				
				std::cin>>opcion;
				
				//mientras no se introduzca un alumno valido se sigue pidiendo uno
				while(opcion<1 || opcion>aux.size())
				{
					std::cout<<BIRED<<"ERROR eleccion invalida"<<RESET<<std::endl;
					std::cout<<"Los alumnos son los siguientes:"<<std::endl;
					std::cout<<"(Selecciona mediante el indice indicado el alumno que buscaba)"<<std::endl;

					for(int i=0;i<aux.size();i++)
						std::cout<<" ["<<i+1<<"] " << aux[i].getApellidos() << "," << aux[i].getNombre() << "\n\tDNI: " <<aux[i].getDNI() << std::endl << std::endl;
					
					std::cin>>opcion;
				}

				//se borran del vector de alumnos encontrados todos los no deseados
				for(int i=0;i<aux.size();i++)
					if(i!=opcion)
						aux.erase(aux.begin()+i);

			}
		break;
		case 3://Grupo
		//Existen grupos de 1, 2 o incluso 3 personas, nunca mas de 3

			for(int i=0;i<tamClase();i++)
			{
				if(getAlumno(i).getEquipo()==atoi(valor.c_str()))
					aux.push_back(getAlumno(i));
			}			

			if(aux.size()>3)
				std::cout<<BIRED<<"ERROR hay mas de 3 alumnos en el mismo equipo"<<RESET<<std::endl;
				break;

			return aux;
		break;
		default:
			std::cout<<BIRED<<"ERROR el criterio introducido no es valido\n";
		break;
	}
}