#include "funcionesAuxiliares.hpp"

void introducirAlumno(Profesor &p)
{
	std::system("clear");

	if(p.getAgenda().tamClase()>=150)
	{
		std::cout<<BIRED<<"ERROR se ha llegado al limite de alumnos registrados"<<RESET<<std::endl;
		return;
	}
	std::vector<int> v;
	std::string nombre,apellido,domicilio,DNI,email, equipo="0";
	int telefono,curso;
	Fecha fecha;

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
	std::cout<<"Fecha de nacimiento: \n";
	fecha.leerFecha();

	while(!fecha.esCorrecta())
	{
		std::cout<<BIRED<<"ERROR fecha invalida"<<RESET<<std::endl;

		std::cout<<"Fecha de nacimiento: \n";
		fecha.leerFecha();
	}

	std::cout<<"Telefono: ";
	std::cin>>telefono;
	std::cout<<"Curso: ";
	std::cin>>curso;
	std::cout<<"Email: ";
	std::cin>>email;
	std::cout<<"Grupo:\n(Si no desea introducirlo indique cero)\n";
	std::cin>>equipo;
	if(equipo.compare("0")!=0)
	{
		while(atoi(equipo.c_str())<1 || atoi(equipo.c_str())>150)
		{
			std::cout<<BIRED<<"ERROR grupo invalido"<<RESET<<std::endl;
			
			std::cout<<"Grupo:\n(Si no desea introducirlo indique cero)\n";
			std::cin>>equipo;
		}
		
		if(equipo.compare("0")!=0 && p.getAgenda().buscarAlumno(3,equipo).size()>=3)
		{
			std::cout<<BIRED<<"ERROR Este grupo ya se encuentra completo"<<RESET<<std::endl;
			return;
		}
	}

	Alumno aux(nombre,apellido,telefono,domicilio,DNI,fecha,curso,email,atoi(equipo.c_str()));

	if(atoi(equipo.c_str())!=0)
	{
		int lider;
		std::cout<<"Es el lider del grupo?[1:Si/2:No]"<<std::endl;
		std::cin>>lider;

		while(lider>2 || lider<1)
		{
			std::cout<<"Introduzca un valor valido"<<std::endl;
			std::cout<<"Es el lider del grupo?[1:Si/2:No]"<<std::endl;
			std::cin>>lider;
		}

		if(lider==1) aux.setLider();
	}

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
	std::string nombre="0", apellido="0", domicilio="0", correo="0", grupo="0";
	int telefono=0, curso=0;
	Fecha fecha;

	std::system("clear");
	std::cout<<BIGREEN<<"\nIntroduzca los valores que desea cambiar del alumno\n"<<RESET;
	std::cout<<BIYELLOW<<"(Indique un cero para los que no desee cambiar)"<<RESET<<std::endl;

	//Se supone que el DNI no deberia ser cambiado
	std::cout<<"\n Nombre: ";
	std::cin>>nombre;
	if(nombre.compare("0")!=0) aux.setNombre(nombre);
	std::cout<<"\n Apellido: ";
	std::cin>>apellido;

	std::cout<<"Fecha de nacimiento: ";
	fecha.leerFecha();

	while(!fecha.esCorrecta())
	{
		if(fecha.getDia()==0 || fecha.getMes()==0 || fecha.getMes()==0) return;
		std::cout<<BIRED<<"ERROR fecha invalida"<<RESET<<std::endl;

		std::cout<<"Fecha de nacimiento: ";
		fecha.leerFecha();
	}

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
	if(grupo.compare("0")!=0 && atoi(grupo.c_str())!=aux.getEquipo()) 
	{
		while(atoi(grupo.c_str())<1 || atoi(grupo.c_str())>150)
		{
			std::cout<<BIRED<<"ERROR grupo invalido"<<RESET<<std::endl;

			std::cout<<"Grupo: ";
			std::cin>>grupo;
		}

		if(p.getAgenda().buscarAlumno(3,grupo).size()>=3)
		{
			std::cout<<BIRED<<"ERROR Este grupo ya se encuentra completo"<<RESET<<std::endl;

			return;
		}

		if(atoi(grupo.c_str())==0) return;

		aux.setEquipo(atoi(grupo.c_str()));

		int lider;
		std::cout<<"Es el lider del grupo?[1:Si/2:No]"<<std::endl;
		std::cin>>lider;

		while(lider>2 || lider<1)
		{
			std::cout<<"Introduzca un valor valido"<<std::endl;
			std::cout<<"Es el lider del grupo?[1:Si/2:No]"<<std::endl;
			std::cin>>lider;
		}

		if(lider==1) aux.setLider();
	}

	if(atoi(grupo.c_str())==0) return;

	if(opcionapellido==0)
		p.modificarAlumno(opcionapellido,aux);
	else
		p.modificarAlumno(buscado.front(),aux);

	std::cout<<BIGREEN<<"Se han modificado los datos del alumno satisfactoriamente \n";

	std::cin.ignore();
}

void borrarDatosAlumno(Profesor &p)
{
	std::system("clear");

	int opcion;
	std::string dato;
	
	std::cout << BIGREEN <<"Indique el dato que aportara para identificar al alumno" <<RESET<<std::endl<<std::endl;
	std::cout << BIYELLOW << " [1] DNI" << RESET<<std::endl;;
	std::cout << BIBLUE << " [2] Apellido" <<RESET<<std::endl;	
	std::cin>>opcion;
	
	while(opcion!=1 && opcion!=2)
	{
		std::cout<< RED <<"ERROR Opcion invalida\n" RESET;
		
		std::cout << BIGREEN <<"Indique el dato que aportara para identificar al alumno" <<RESET<<std::endl<<std::endl;
		std::cout<<BIYELLOW<<"(Si desea volver al menu introduzca un cero)"<<RESET<<std::endl;
		std::cout<<" [1] DNI"<<std::endl;;
		std::cout<<" [2] Apellido"<<std::endl;	
	
		std::cin>>opcion;

		if(opcion==0)
			return;
	}

	std::system("clear");

	int opcionapellido=0;	
	std::vector<int> buscado;
	switch(opcion)
	{
		case 1://DNI
			std::cout << BIBLUE <<"Introduzca el DNI del alumno" <<RESET<<std::endl;
			std::cin>>dato;
			
			while(strlen(dato.c_str())!=9)
			{
				std::cout<<BIRED<<"ERROR DNI invalido"<<RESET<<std::endl;

				std::cout << BIBLUE <<"Introduzca el DNI del alumno" <<RESET<<std::endl;
				std::cout<<BIYELLOW<<"(Si desea volver al menu introduzca un cero)"<<RESET<<std::endl;
				std::cin>>dato;

				if(dato.compare("0")==0)
				{
					std::cin.ignore();
					return;
				}
			}
			
			buscado=p.getAgenda().buscarAlumno(1,dato);
			
			if(buscado.size()>1)//+1 alumno
			{
				std::cout<<BIRED<<"ERROR Se han encontrado varios alumnos con DNI "<<dato<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}

			if(buscado.size()<1)//ninguno
			{
				std::cout<<BIRED<<"ERROR No se ha encontrado ningun alumno con DNI "<<dato<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}

			p.eliminarAlumno(buscado.front());
			
			std::cout<<BIGREEN<<"\nAlumno borrado correctamente"<<RESET<<std::endl; 
			
			std::cin.ignore();
		break;
		case 2://Apellido
			
			std::cout<<BIYELLOW<<"Introduzca el apellido del alumno"<<RESET<<std::endl;
			std::cin>>dato;

			buscado=p.getAgenda().buscarAlumno(2,dato);

			if(buscado.size()>1)
			{
				std::cout<<BIRED<<"Se han encontrado varios alumnos apellidados '"<<dato<<"'"<<RESET<<std::endl;

				std::cout<<"Indique cual es el que desea borrar"<<std::endl;

				for(int i=0;i<buscado.size();i++)
					std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<", "<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
				std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

				std::cin>>opcionapellido;

				while(opcionapellido<0 || opcionapellido>buscado.size())
				{
					std::cout<<BIRED<<"ERROR opcion invalida"<<std::endl<<std::endl;

					std::cout<<"Indique cual es que buscaba"<<std::endl;
					for(int i=0;i<buscado.size();i++)
						std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
					std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

					std::cin>>opcionapellido;
				}
				if(opcionapellido==0) 
					return;
			}
			
			
			p.eliminarAlumno(buscado[opcionapellido]);
			
			std::cout<<BIGREEN<<"\nAlumno Borrado correctamente"<<RESET<<std::endl; 
			std::cin.ignore();
		
		break;
		default:
			std::cout<<BIRED<<"ERROR Opcion incorrecta"<<RESET<<std::endl;
	}
}

void mostrarNumeroAlumnos(Profesor &p)
{
	std::system("clear");

	std::cout<<"\nEn este momento, se encuentran registrados "<<BICYAN<<p.getAgenda().tamClase()<<RESET<<" alumnos"<<std::endl;
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

void mostrarGrupo(Profesor &p)
{
	std::system("clear");
	if(p.getAgenda().tamClase()<1)//precondicion
	{
		std::cout<<BIRED<<"ERROR no hay alumnos registrados"<<RESET<<std::endl;
		return;
	}

	std::string grupo;
	std::vector<int> buscado;
	std::cout<<"Indique el numero del grupo que busca"<<std::endl;
	std::cin>>grupo;

	//Como minimo habra un grupo
	//Como maximo habria 150 grupos, de 1 alumno cada uno
	while(atoi(grupo.c_str())<1 || atoi(grupo.c_str())>150)
	{
		std::cout<<BIRED<<"ERROR grupo invalido"<<RESET<<std::endl;

		std::cout<<"Indique el numero del grupo que busca"<<std::endl;
		std::cout<<"(Introduzca un cero sin desea volver"<<std::endl;
		std::cin>>grupo;

		if(atoi(grupo.c_str())==0) return;
	}

	buscado=p.getAgenda().buscarAlumno(3,grupo);

	if(buscado.size()>3)
	{
		std::cout<<BIRED<<"ERROR se han encontrado mas de 3 alumnos con el mismo grupo asignado"<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}

	if(buscado.size()<1)
	{
		std::cout<<BIRED<<"No se han encontrado alumnos con el grupo "<<grupo<<" asignado"<<RESET<<std::endl;
		return;
	}

	std::cout<<"Los componentes del grupo "<<BIYELLOW<<grupo<<RESET<<" son los siguientes: "<<std::endl;

	for(int i=0;i<buscado.size();i++)
	{
		std::cout<<std::endl<<BIGREEN<<" Alumno "<<i+1<<RESET<<std::endl;
		p.getAgenda().mostrarAlumno(buscado[i]);
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

 	fichero.open("listaAlumnos.txt");

 	//comprobacion de apertura correcta del fichero
 	if((fichero.rdstate() & std::ofstream::failbit)!=0)
	{
		std::cout<<BIRED<<"Se ha producido un error al intentar abrir el fichero"<<RESET<<std::endl;
		return;
	}

	int i=0;
	//insertar los alumnos en el fichero
	while(aux.tamClase()>0)
	{
		fichero<<aux.getAlumno(i);
		aux.eliminar(0);
	}

	fichero.close();

	std::cout<<BIGREEN<<"La lista de alumnos registrados es la siguiente:\n"<<RESET<<std::endl;
	std::system("cat ./listaAlumnos.txt");

	std::system("rm ./listaAlumnos.txt");

}

void registrarNuevoProfesor()
{
	std::system("clear");

	std::cout<<"Introduzca los datos del nuevo profesor"<<std::endl;

	std::vector<Profesor> profesores;
	Profesor nuevo;

	nuevo.leerProfesor();

	std::ifstream fichero;

	fichero.open("../profesores.bin", std::ifstream::binary);

	if(!fichero.is_open())
	{
		std::cout<<BIRED<<"ERROR al abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}

	Profesor aux;
	while(!fichero.eof())
	{		
		fichero.read((char*)&aux,sizeof(Profesor));
		profesores.push_back(aux);
	}

	fichero.close();

	for(int i=0;i<profesores.size();i++)
	{
		if(profesores[i].getId()==nuevo.getId())
		{
			std::cout<<BIRED<<"ERROR El profesor indicado ya se encuentra registrado"<<RESET<<std::endl;
			std::cin.ignore();
			return;
		}
	}

	std::ofstream fichero2;

	fichero2.open("../profesores.bin", std::ofstream::binary);

	if(!fichero2.is_open())
	{
		std::cout<<BIRED<<"ERROR al abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}

	fichero2.seekp(0,std::ios_base::end);

	fichero2.write((char*)&nuevo,sizeof(Profesor));

}

void cargarCopia(Profesor &p)
{
	std::system("clear");

	//crear fichero llamado clase[fechadelacopia].bin
	std::ifstream fichero;

	//nombrefichero=now->tm_mday+'-'+(now->tm_mon + 1)+'-'+(now->tm_year + 1900);
	std::cout<<"Introduzca el dia de la copia que desea recuperar"<<std::endl;

	Fecha fecha;
	fecha.leerFecha();

	std::string nombreFichero;
	std::stringstream dia, mes, ano;

	//std::time_t t = std::time(0);   // recoge el dia actual
    //std::tm* now = std::localtime(&t);

	dia<<fecha.getDia();
	mes<<fecha.getMes();
	ano<<fecha.getAgno();

    nombreFichero="../CopiasSeguridad/clase-"+ dia.str();
    nombreFichero+="-"+ mes.str();
    nombreFichero+="-"+ ano.str();
    nombreFichero+=".bin";

	std::cout<<BIGREEN<<nombreFichero<<RESET<<std::endl;


	//abrir fichero
	fichero.open(nombreFichero.c_str(), std::ifstream::binary);

	//comprobar fichero abierto
	if(!fichero.is_open())
	{
		std::cout<<BIRED<<"ERROR No se ha podido abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}

	Alumno aux;

	//meter alumnos en el fichero
	while(!fichero.eof())
	{
		fichero.read((char *)&aux,sizeof(Alumno));

		if(p.getAgenda().buscarAlumno(1,aux.getDNI()).size()==0) 
			if(aux.getFechaNacimiento().esCorrecta())
				p.nuevoAlumno(aux);
		else std::cout<<"El alumno '"<<aux.getNombre()<<" "<<aux.getApellido()<<"' ya esta guardado\nPor lo tanto no se ha registrado"<<std::endl;
	}

	fichero.close();

	std::cin.ignore();
}


void crearCopia(Profesor &p)
{
	std::system("clear");

	std::string nombreFichero;
	std::stringstream dia,mes,ano;

	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	dia<<now->tm_mday;
	mes<<now->tm_mon+1;
	ano<<now->tm_year+1900;

	nombreFichero="../CopiasSeguridad/clase-"+dia.str();
	nombreFichero+="-"+mes.str();
	nombreFichero+="-"+ano.str();
	nombreFichero+=".bin";

	std::ofstream fichero;

	fichero.open(nombreFichero.c_str(), std::ofstream::binary);

	Alumno aux;

	if(fichero.is_open())
	{
		for(int i=0;i<p.getAgenda().tamClase();i++)
		{
			aux=p.getAgenda().getAlumno(i);
			fichero.write((char*)&aux,sizeof(Alumno));
		}
			
		std::cout<<BIGREEN<<"Los alumnos se guardaron correctamente"<<RESET<<std::endl;
	}
	else
		std::cout<<BIRED<<"ERROR No se ha podido guardar los alumnos"<<RESET<<std::endl;


	fichero.close();

	std::cin.ignore();
}

Profesor logIn()
{
	std::cout<<BIYELLOW<<"BIENVENIDO"<<RESET<<std::endl;

	std::vector<Profesor> bdprofesores;
	Profesor nuevoTutor;


	std::ifstream fichero;

	fichero.open("../profesores.bin", std::ifstream::binary);

	if(!fichero.is_open())
	{
		std::cout<<BIRED<<"ERROR al abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return nuevoTutor;
	}

	Profesor aux;
	while(!fichero.eof())
	{
		fichero.read((char*)&aux,sizeof(Profesor));
		bdprofesores.push_back(aux);
	}

	std::string usuario, contrasena;

	std::cout<<"Introduzca sus credenciales"<<std::endl;

	std::cout<<" Usuario --> ";
	std::cin>>usuario;
	std::cout<<"\n Contrasena --> ";
	std::cin>>contrasena;

	for(int i=0;i<bdprofesores.size();i++)
	{
		if(bdprofesores[i].comprobarCredenciales(usuario, contrasena))
		{
			nuevoTutor=bdprofesores[i];
			break;
		}
	}

	return nuevoTutor;
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
   lista.swap(i+1, ultimo);
   return i+1;
}

int menu(bool &membresia)
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

	if(membresia)
	{
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
	}

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
