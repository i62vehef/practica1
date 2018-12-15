#include "funcionesAuxiliares.hpp"

/*void cargarClasedeFichero(Profesor &p)
{
	std::system("clear");

	return;
}
*/
void introducirAlumno(Profesor &p)
{
	std::system("clear");

	if(p.getAgenda().tamClase()>=150)
	{
		std::cout<<BIRED<<"ERROR se ha llegado al limite de alumnos registrados"<<RESET<<std::endl;
		return;
	}
	std::vector<int> v;
	std::string nombre,apellido,domicilio,DNI,email;
	int telefono,curso,equipo=0;

	std::cout<<BIGREEN<<"\nIntroduzca los datos del nuevo alumno\n\n"<<RESET;

	std::cout<<"DNI: ";
	std::cin>>DNI;
	while(strlen(DNI.c_str())!=9)
	{
		std::cout<<BIRED<<"ERROR DNI invalido\n"<<RESET;
		std::cin.ignore();
		
		std::cout<<IYELLOW<<"(Si desea salir introduzca un cero)\n"<<RESET;
		std::cout<<"DNI: ";
		std::cin>>DNI;
	
		if(DNI.compare("0")==0) return;
	}

	if(p.getAgenda().tamClase()>0)
	{
		v = p.getAgenda().buscarAlumno(1,DNI);
		if(v.size()>0)
		{
			std::cout<<BIRED<<"ERROR Ya existe un alumno con el DNI indicado\n"<<RESET;
			std::cin.ignore();
			return;
		}
	}
	std::cout<<"Nombre: ";
	std::cin>>nombre;
	std::cout<<"Primer Apellido: ";
	std::cin>>apellido;
	std::cout<<"Domicilio: ";
	std::cin>>domicilio;
	std::cout<<"Telefono: ";
	std::cin>>telefono;
	std::cout<<"Curso: ";
	std::cin>>curso;
	std::cout<<"Email: ";
	std::cin>>email;
	std::cout<<"Equipo:\n(Si no desea introducirlo indique cero)\n";
	std::cin>>equipo;
	
	Alumno aux(nombre,apellido,telefono,domicilio,DNI,curso,email,equipo);

	p.nuevoAlumno(aux);
	
	std::cout << BIGREEN <<"Alumno registrado correctamente" <<RESET <<std::endl;
	
	std::cin.ignore();
}

void modificarDatosAlumno(Profesor &p)
{
	std::system("clear");

	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\nERROR no hay alumnos registrados que modificar"<<RESET<<std::endl;
		return;
	}

	int opcion;

	std::cout<<BIGREEN<<"\n Indique como quiere identificar al alumno cuyos datos desea modificar\n";
	std::cout<<BIPURPLE<<"\n [1] DNI \n"<<RESET;
	std::cout<<BBLUE<<" [2] Apellido\n"<<RESET;
	std::cout<<BIRED<<"\n [0] Volver\n"<<RESET;

	std::cin>>opcion;

	while(opcion!=0 && opcion!=1 && opcion !=2)
	{
		std::cout<<BIRED<<"ERROR introduzca una opcion valida"<<RESET<<std::endl<<std::endl;

		std::cout<<"\n Indique como quiere identificar al alumno cuyos datos desea modificar\n";
		std::cout<<" [1] DNI"<<std::endl;
		std::cout<<" [2] Apellido"<<std::endl;
		std::cout<<BIRED<<"\n [0] Volver\n"<<RESET<<std::endl;

		std::cin>>opcion;
	}
	std::system("clear");
	std::string dato;
	std::vector<int> buscado;
	int opcionapellido=0;
	switch(opcion)
	{
		case 0://volver
			return;
		break;
		case 1://DNI
			//pedir DNI
			std::cout<<BIGREEN<<"\nIntroduzca el DNI del alumno:"<<RESET;
			std::cin>>dato;

			//comprobar DNI
			while(strlen(dato.c_str())!=9)
			{
				std::cout<<BIRED<<"ERROR DNI invalido"<<RESET<<std::endl<<std::endl;
				
				std::cout<<"Introduzca el DNI del alumno"<<std::endl;
				std::cin>>dato;
			}

			//buscar alumno
			buscado=p.getAgenda().buscarAlumno(1,dato);

			//comprobar resultados de la busqueda
			if(buscado.size()!=1)//error
			{
				if(buscado.size()<=0)
					std::cout<<BIRED<<"No se ha encontrado ningun alumno con DNI "<<dato<<" registrado"<<RESET<<std::endl;
				else
					std::cout<<BIRED<<"ERROR se han encontrado varios alumnos con el mismo DNI"<<RESET<<std::endl;
				return;
			}
			//else modificar
		break;
		case 2://Apellidos
			//pedir apellido
			std::cout<<BIGREEN<<"\nIntroduzca el apellido del alumno:"<<RESET;
			std::cin>>dato;

			//buscar alumno
			buscado=p.getAgenda().buscarAlumno(2,dato);

			//comprobar resultados busqueda
			if(buscado.size()!=1)//se han encontrado mas de uno o ninguno
			{
				if(buscado.size()>1)//+1 encontrados
				{
					std::cout<<"Se han encontrado varios alumnos con el apellido buscado"<<std::endl<<std::endl;

					std::cout<<"Indique cual es el que buscaba"<<std::endl;
					for(int i=0;i<buscado.size();i++)
						std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
					std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

					std::cin>>opcionapellido;

					if(opcionapellido==0) 
						return;
					while(opcionapellido<0 || opcionapellido>buscado.size())
					{
						std::cout<<BIRED<<"ERROR opcion invalida"<<std::endl<<std::endl;

						std::cout<<"Indique cual es que buscaba"<<std::endl;
						for(int i=0;i<buscado.size();i++)
							std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
						std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

						std::cin>>opcionapellido;
					}
					if(opcionapellido==0) return;

					//ya sabemos el alumno buscado
				}
				else//0 encontrados
				{
					std::cout<<BIRED<<"No se ha encontrado ningun alumno con apellido '"<<dato<<"' registrado"<<RESET<<std::endl;
					std::cin.ignore();
					return;
				}
			}
			//else modificar
		break;
		default:
			std::cout<<BIRED<<"ERROR opcion invalida\n"<<RESET;
	}

	opcionapellido--;	
	Alumno aux;
	if(opcionapellido==0)
		aux=p.getAgenda().getAlumno(opcionapellido);
	else
		aux=p.getAgenda().getAlumno(buscado.front());
	std::string nombre="0", apellido="0", domicilio="0", correo="0";
	int telefono=0, curso=0, grupo=0;

	std::system("clear");
	std::cout<<BIGREEN<<"\nIntroduzca los valores que desea cambiar del alumno\n"<<RESET;
	std::cout<<BIYELLOW<<"(Indique un cero para los que no desee cambiar)"<<RESET<<std::endl;

	//Se supone que el DNI no deberia ser cambiado
	std::cout<<"\n Nombre: ";
	std::cin>>nombre;
	if(nombre.compare("0")!=0) aux.setNombre(nombre);
	std::cout<<"\n Apellido: ";
	std::cin>>apellido;
	if(apellido.compare("0")!=0) aux.setApellido(apellido);
	std::cout<<"\n Telefono: ";
	std::cin>>telefono;
	if(telefono!=0) aux.setTelefono(telefono);
	std::cout<<"\n Domicilio: ";
	std::cin>>domicilio;
	if(domicilio.compare("0")!=0) aux.setDomicilio(domicilio);
	std::cout<<"\n Curso: ";
	std::cin>>curso;
	if(curso!=0) aux.setCurso(curso);
	std::cout<<"\n Correo: ";
	std::cin>>correo;
	if(correo.compare("0")!=0) aux.setEmail(correo);
	std::cout<<"\n Grupo: ";
	std::cin>>grupo;
	if(grupo!=0) aux.setEquipo(grupo);

	if(opcionapellido==0)
		p.modificarAlumno(opcionapellido,aux);
	else
		p.modificarAlumno(buscado.front(),aux);

	std::cout<<BIGREEN<<"Se han modificado los datos del alumno satisfactoriamente \n";

	std::cin.ignore();
}

void mostrarNumeroAlumnos(Profesor &p)
{
	std::system("clear");

	std::cout<<"\nEn este momento, se encuentran registrados "<<BICYAN<<p.getAgenda().tamClase()<<RESET<<" alumnos "<<std::endl;
}

void mostrarDatosdeAlumno(Profesor &p)
{
	std::system("clear");
	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\nERROR no hay alumnos registrados"<<RESET<<std::endl;
		return;
	}
	int opcion=0, opcionapellido;
	std::string dato;

	std::vector<int> buscado;

	std::cout<<BIYELLOW<<"SE MOSTRARAN TODOS LOS DATOS DEL ALUMNO"<<RESET<<std::endl;

	std::cout<<BIGREEN<<"\nIndique el dato por el que se identificara al alumno a mostrar"<<RESET<<std::endl;
	std::cout<<BIPURPLE<<"\n [1] DNI"<<RESET<<std::endl;
	std::cout<<BIBLUE<<" [2] Apellido"<<RESET<<std::endl;
	std::cout<<BIRED <<"\n [0] Volver"<<RESET<<std::endl;

	std::cin>>opcion;

	while(opcion!=0 && opcion!=1 && opcion!=2)
	{
		std::cout<<BIRED<<"ERROR introduzca una opcion valida"<<RESET<<std::endl<<std::endl;

		std::cout<<"Indique el dato por el que se identificara al alumno a mostrar"<<std::endl;
		std::cout<<BIPURPLE<<" [1] DNI"<<RESET<<std::endl;
		std::cout<<BIBLUE<<" [2] Apellido"<<RESET<<std::endl;
		std::cout<<BIRED<<"\n [0] Volver\n"<<RESET<<std::endl;

		std::cin>>opcion;
		
	}
std::system("clear");
	switch(opcion)
	{
		case 0://salir
			return;
		break;
		case 1://DNI
			//pedir DNI
			std::cout<<BIGREEN<<"\nIntroduzca el DNI del alumno:"<<RESET;
			std::cin>>dato;

			//comprobar DNI
			while(strlen(dato.c_str())!=9)
			{
				std::cout<<BIRED<<"ERROR DNI invalido"<<RESET<<std::endl<<std::endl;
				
				std::cout<<BIGREEN<<"Introduzca el DNI del alumno:"<<RESET;
				std::cin>>dato;
			}

			//buscar alumno
			buscado=p.getAgenda().buscarAlumno(1,dato);

			//comprobar resultados de la busqueda
			if(buscado.size()==1)//mostrar
				p.getAgenda().mostrarAlumno(buscado.front());
			else//error
			{
				if(buscado.size()==0)
					std::cout<<BIRED<<"No se ha encontrado ningun alumno con DNI "<<dato<<" registrado"<<RESET<<std::endl;
				else
					std::cout<<BIRED<<"ERROR se han encontrado varios alumnos con el mismo DNI"<<RESET<<std::endl;
			}
	
		break;
		case 2://Apellido
			//pedir apellido
			std::cout<< BIGREEN <<"\nIntroduzca el apellido del alumno:"<< RESET;
			std::cin>>dato;

			//buscar alumno
			buscado=p.getAgenda().buscarAlumno(2,dato);

			//comprobar resultados busqueda
			if(buscado.size()==1)//mostrar
				p.getAgenda().mostrarAlumno(buscado.front());
			else//se han encontrado mas de uno o ninguno
			{
				if(buscado.size()>1)//+1 encontrados
				{
					std::cout<<BIBLUE<<"\nSe han encontrado varios alumnos con el apellido buscado"<<RESET<<std::endl<<std::endl;

					std::cout<<"Indique cual es el que buscaba"<<std::endl;
					for(int i=0;i<buscado.size();i++)
						std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
					std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

					std::cin>>opcionapellido;

					if(opcionapellido==0) break;
					while(opcionapellido<1 || opcionapellido>buscado.size())
					{
						std::cout<<BIRED<<"ERROR opcion invalida"<<std::endl<<std::endl;

						std::cout<<"Indique cual es que buscaba"<<std::endl;
						for(int i=0;i<buscado.size();i++)
							std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
						std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

						std::cin>>opcionapellido;
					}

					//ya sabemos el alumno buscado
					p.getAgenda().mostrarAlumno(buscado[opcionapellido]);

				}
				else//0 encontrados
					std::cout<<BIRED<<"No se ha encontrado ningun alumno con apellido '"<<dato<<"' registrado"<<RESET<<std::endl;
			}
		break;
		default:
			std::cout<<BIRED<<"ERROR opcion invalida"<<RESET<<std::endl;
	}
	std::cin.ignore();
}

void mostrarListaAlumnos(Profesor &p)
{
	std::system("clear");
	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"ERROR no hay ningun alumno registrado\n"<<RESET;
		return;
	}

 	std::ofstream fichero;

 	ListaAlumnos aux=p.getAgenda();

 	fichero.open("listaClase.txt");

 	//comprobacion de apertura correcta del fichero
 	if((fichero.rdstate() & std::ofstream::failbit)!=0)
	{
		std::cout<<BIRED<<"Se ha producido un error al intentar abrir el fichero"<<RESET<<std::endl;
		return;
	}

	//se coloca el cursor al principio del fichero
	//para sobreescribir todo lo que haya en caso de que ya exista el fichero
	fichero.seekp((long)0);

	int i=0;
	//insertar los alumnos en el fichero
	while(aux.tamClase()>0)
	{
		fichero<<aux.getAlumno(i);
		aux.eliminar(0);
	}

	fichero.close();

	std::cout<<BIGREEN<<"\nLa lista de alumnos registrados es la siguiente:\n"<<RESET<<std::endl;
	std::system("cat ./listaClase.txt");

}

void quicksort(int primero, int ultimo, ListaAlumnos &lista)
{
   if(primero < ultimo)
   {
      	int pivote=particion(primero, ultimo, lista);

      	quicksort(primero, pivote - 1, lista);
      	quicksort(pivote + 1, ultimo, lista);
   }
}

int particion(int primero, int ultimo, ListaAlumnos &lista)
{
   std::string pivote=lista.getAlumno(ultimo).getApellido();
   int i=primero-1;

   for(int j=primero; j<=ultimo-1; j++)
   {
   		if(strcmp(lista.getAlumno(j).getApellido().c_str(),pivote.c_str())>=0)
      	{
    		i++;
         	lista.swap(i, j);
      	}
   }
   lista.	swap(i+1, ultimo);
   return i+1;
}

int menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;


	posicion++;

	PLACE(posicion++,10);
	std::cout << BIYELLOW << "[1]" << RESET << " Cargar alumnos desde fichero";

	PLACE(posicion++,10);
	std::cout << BIYELLOW << "[2]" << RESET << " Guardar alumnos en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);	
	std::cout << BIBLUE << "[3]" << RESET << " Introducir nuevo alumno";

	PLACE(posicion++,10);	
	std::cout << BIBLUE << "[4]" << RESET << " Modificar datos de un alumno";

	PLACE(posicion++,10);	
	std::cout << BIBLUE << "[5]" << RESET << " Eliminar un alumno";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);	
	std::cout << BIGREEN << "[6]" << RESET << " Mostrar numero de alumnos registrados";

	PLACE(posicion++,10);	
	std::cout << BIGREEN << "[7]" << RESET << " Mostrar datos de un alumno";

	PLACE(posicion++,10);
	std::cout << BIGREEN << "[8]" << RESET << " Mostrar alumnos de un grupo";

	PLACE(posicion++,10);
	std::cout << BIGREEN << "[9]" << RESET << " Mostrar lista de alumnos";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BICYAN << "[10]" << RESET << " Registrar nuevo profesor";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << IGREEN << "[11]" << RESET << " Cargar copia de seguridad";

	PLACE(posicion++,10);
	std::cout << IGREEN << "[12]" << RESET << " Crear copia de seguridad";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Volver";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();
	return opcion;
}

void borrarAlumno(Profesor &c)
{
	int opcion=0;
	std::string dato;

    std::cout <<BIRED <<"BORRAR ALUMNO\n\n" <<RESET;
	
	std::cout << BIGREEN <<"Elija opcion para borrar alumno\n\n" <<RESET;
	std::cout << BIYELLOW << "1-apellido\n" << RESET;
	std::cout << BIBLUE << "2-DNI\n" <<RESET;	
	std::cin>>opcion;
	
	while(opcion!=1 && opcion!=2)
	{
		
		std::cout<< RED <<"Opcion erronea\n" RESET;
		std::cout << BIGREEN <<"\nElija opcion para borrar alumno\n\n" <<RESET;
		std::cout << BIYELLOW << "1-apellido\n" << RESET;
		std::cout << BIBLUE << "2-DNI\n" <<RESET;
		std::cin>>opcion;
		
		
	}
	std::system("clear");
	std::vector<int> v;
	switch(opcion)
		{
			case 1://Apellido
				std::cout << BIYELLOW <<"\nIntroduce el apellido:" <<RESET;
				std::cin>>dato;
				v = c.getAgenda().buscarAlumno(2,dato);
				c.eliminarAlumno(v.front());
				std::cout << BIRED <<"\nAlumno Borrado correctamente\n" <<RESET; 
				std::cin.ignore();
			break;
			case 2://DNI
				std::cout << BIBLUE <<"\nIntroduce el dni:" <<RESET;
				std::cin>>dato;
				if(strlen(dato.c_str())==9)
				{
				v=c.getAgenda().buscarAlumno(1,dato);
				c.eliminarAlumno(v.front());
				std::cout << BIRED <<"\nAlumno Borrado correctamente\n" <<RESET; 
				std::cin.ignore();
				}else
					{
						std::cout <<BIRED <<"El Alunmo con este dni no existe\n" <<RESET;
					}
			break;
			default:
				std::cout<<"opcion incorrecta\n";
		}
		


		


}