#include "funcionesAuxiliares.hpp"

/*void cargarClasedeFichero(Profesor &p)
{
	std::ifstream fichero;

	string nombreFichero; //Hay que ver como vamos a hacer lo del nombre del fichero

	fichero.open(nombreFichero.c_str());

	if((fichero.rdstate() & std::ofstream::failbit)!=0)	
      std::cout<<BIRED<<"Se ha producido un error al intentar abrir el fichero"<<RESET<<std::endl;
	else 
	{
		Alumno aux;
		while(fichero>>aux) lista.insertar(aux);		
		std::cout<<BIGREEN<<"Fichero cargado con exito"<<RESET<<std::endl;
	}
	
	fichero.close();

	quicksort(0,lista.tamClase()-1,lista);
}
*/
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
   string pivote=lista.getAlumno(ultimo).getApellidos();
   int i=primero-1;

   for(int j=primero; j<=ultimo-1; j++)
   {
   		if(strcmp(lista.getAlumno(j).getApellidos().c_str(),pivote.c_str())>=0)
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
	std::cout << BIGREEN << "[6]" << RESET << " Mostrar datos de un alumno";

	PLACE(posicion++,10);	
	std::cout << BIGREEN << "[7]" << RESET << " Mostrar alumnos de un grupo";

	PLACE(posicion++,10);
	std::cout << BIGREEN << "[8]" << RESET << " Mostrar lista de alumnos";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BICYAN << "[9]" << RESET << " Registrar nuevo profesor";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << IGREEN << "[10]" << RESET << " Cargar copia de seguridad";

	PLACE(posicion++,10);
	std::cout << IGREEN << "[11]" << RESET << " Crear copia de seguridad";

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

void introducirAlumno(Profesor &c)
{
	
	std::vector<int> v;
	string nombre,apellido,domicilio,DNI,email;
	int telefono,curso,equipo;
cout<<"INTRODUCIR DATOS DEL ALUMNO\n\n";

	cout<<"DNI:";
	cin>>DNI;
	if(strlen(DNI.c_str())!=9)
	{
		cout <<"Error dni invalido";
		std::cin.ignore();
		return;
	}
	
	v = c.getAgenda().buscarAlumno(1,DNI);
	if(v.size()>0)
	{
		std::cout <<"Ya exite el alumno con ese dni";
	}
	cout<<"Nombre:";
	cin>>nombre;
	cout<<"Apellido:";
	getline(cin,apellido);
	std::cin.ignore();
	cout<<"Domicilio:";
	getline(cin,domicilio);
	std::cin.ignore();
	while ( getchar ( ) != '\n' );
	cout<<"Curso:";
	cin>>curso;
	cout<<"Email:";
	cin>>email;
	cout<<"Equipo:";
	cin>>equipo;
	c.getAgenda().insertar(Alumno(nombre,apellido,telefono,domicilio,DNI,curso,email,equipo));
	std::cout << BIGREEN <<"Alumno ingresado correctamente" <<RESET <<std::endl;
	std::cin.ignore();
}

void borrarAlumno(Profesor c)
{
	int opcion=0;
	string dato;

    std::cout <<BIRED <<"BORRAR ALUMNO\n\n" <<RESET;
	
	std::cout << BIGREEN <<"Elija opcion para borrar alumno\n\n" <<RESET;
	std::cout << BIYELLOW << "1-apellido\n" << RESET;
	std::cout << BIBLUE << "2-DNI\n" <<RESET;	
	cin>>opcion;
	
	while(opcion!=1 && opcion!=2)
	{
		
		std::cout<< RED <<"Opcion erronea\n" RESET;
		std::cout << BIGREEN <<"\nElija opcion para borrar alumno\n\n" <<RESET;
		std::cout << BIYELLOW << "1-apellido\n" << RESET;
		std::cout << BIBLUE << "2-DNI\n" <<RESET;
		cin>>opcion;
		
		
	}
	std::system("clear");
	switch(opcion)
		{
			case 1:
					std::cout << BIYELLOW <<"Introduce el apellido:" <<RESET;
					cin>>dato;
					

		break;
			
			case 2:		
					std::cout << BIBLUE <<"Introduce el dni:" <<RESET;
					cin>>dato;
					if(strlen(dato.c_str())==9)
					{
						c.getAgenda().buscarAlumno(1,dato);
					}else
						{
							cout<<"DNI invalido";
						}

			break;
			default:
					cout<<"opcion incorrecta\n";
		}
		


		


}