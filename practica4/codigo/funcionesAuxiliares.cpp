#include "funcionesAuxiliares.hpp"

void introducirAlumno(Profesor &p)
{
	std::system("clear");

	if(p.getAgenda().tamClase()>=150)
	{
		std::cout<<BIRED<<"\n ERROR se ha llegado al limite de alumnos registrados"<<RESET<<std::endl;
		return;
	}
	std::vector<int> v;
	std::string nombre,apellido,domicilio,DNI,email, equipo="0";
	int telefono,curso,lider=1;
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
	std::cout<<"Domicilio (en una palabra): ";
	std::cin>>domicilio;
	std::cout<<"Fecha de nacimiento \n";
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
		while(atoi(equipo.c_str())<0 || atoi(equipo.c_str())>150)
		{
			std::cout<<BIRED<<"ERROR grupo invalido"<<RESET<<std::endl;
			
			std::cout<<"Grupo:\n(Si no desea introducirlo indique cero)\n";
			std::cin>>equipo;

			if(equipo.compare("0")==0)
				return;
		}
		
		std::vector<int> grupo;
		bool hayLider=false;
		if((grupo=p.getAgenda().buscarAlumno(3,equipo)).size()>=3)
		{
			std::cout<<BIRED<<"ERROR Este grupo ya se encuentra completo"<<RESET<<std::endl;
			return;
		}
		
		for(int i=0;i<grupo.size();i++)
		{
			if(p.getAgenda().getAlumno(grupo[i]).esLider())
			{
				hayLider=true;
				break;
			} 
		}

		if(!hayLider)
		{

			std::cout<<"Es el lider del grupo?[1:No/2:Si]"<<std::endl;
			std::cin>>lider;

			while(lider>2 || lider<1)
			{
				std::cout<<"Introduzca un valor valido"<<std::endl;
				std::cout<<"Es el lider del grupo?[1:No/2:Si]"<<std::endl;
				std::cin>>lider;
			}
		}
	}

	Alumno aux(nombre,apellido,telefono,domicilio,DNI,fecha,curso,email,atoi(equipo.c_str()),(bool)(lider-1));

	p.nuevoAlumno(aux);
	
	std::cout << BIGREEN <<"Alumno registrado correctamente" <<RESET <<std::endl;
	
	std::cin.ignore();
}

void modificarDatosAlumno(Profesor &p)
{
	std::system("clear");

	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\n ERROR No hay alumnos registrados"<<RESET<<std::endl;
		return;
	}

	int opcion;

	std::cout<<"\n Indique como quiere identificar al alumno cuyos datos desea modificar\n";
	std::cout<<"\n [1] DNI \n";
	std::cout<<" [2] Apellido\n";
	std::cout<<BIRED<<"\n [0] Volver\n"<<RESET;

	std::cout<<"\n Opcion: ";
	std::cin>>opcion;

	while(opcion!=0 && opcion!=1 && opcion !=2)
	{
		std::cout<<BIRED<<"ERROR introduzca una opcion valida"<<RESET<<std::endl<<std::endl;

		std::cout<<"\n Indique como quiere identificar al alumno cuyos datos desea modificar\n";
		std::cout<<" [1] DNI"<<std::endl;
		std::cout<<" [2] Apellido"<<std::endl;
		std::cout<<BIRED<<"\n [0] Volver\n"<<RESET<<std::endl;

		std::cout<<"\n Opcion: ";
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
			std::cout<<"\nIntroduzca el DNI del alumno: ";
			std::cin>>dato;

			//comprobar DNI
			while(strlen(dato.c_str())!=9)
			{
				std::cout<<BIRED<<"ERROR DNI invalido"<<RESET;
				
				std::cout<<"\n\nIntroduzca el DNI del alumno: ";
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
			std::cout<<"\nIntroduzca el apellido del alumno: ";
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

					std::cout<<"\n Opcion: ";
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

						std::cout<<"\n Opcion: ";
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

	std::cout<<"Fecha de nacimiento: \n";
	fecha.leerFecha();

	while(!fecha.esCorrecta())
	{
		if(fecha.getDia()==0 || fecha.getMes()==0 || fecha.getMes()==0) break;
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

	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\n ERROR No hay alumnos registrados"<<RESET<<std::endl;
		return;
	}


	int opcion;
	std::string dato;
	
	std::cout << BIGREEN <<"Indique el dato que aportara para identificar al alumno" <<RESET<<std::endl<<std::endl;
	std::cout << " [1] DNI" <<std::endl;;
	std::cout << " [2] Apellido" <<std::endl;

	std::cout<<"\n Opcion: ";	
	std::cin>>opcion;
	
	while(opcion!=1 && opcion!=2)
	{
		std::cout<< RED <<"ERROR Opcion invalida\n" RESET;
		
		std::cout << BIGREEN <<"Indique el dato que aportara para identificar al alumno" <<RESET<<std::endl<<std::endl;
		std::cout<<BIYELLOW<<"(Si desea volver al menu introduzca un cero)"<<RESET<<std::endl;
		std::cout<<" [1] DNI"<<std::endl;;
		std::cout<<" [2] Apellido"<<std::endl;	
	
		std::cout<<"\n Opcion: ";
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
			std::cout <<"\nIntroduzca el DNI del alumno" <<std::endl;
			std::cin>>dato;
			
			while(strlen(dato.c_str())!=9)
			{
				std::cout<<BIRED<<"ERROR DNI invalido"<<RESET<<std::endl;

				std::cout <<"Introduzca el DNI del alumno" <<std::endl;
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
			
			std::cout<<"\nIntroduzca el apellido del alumno"<<std::endl;
			std::cin>>dato;

			buscado=p.getAgenda().buscarAlumno(2,dato);

			if(buscado.size()>1)
			{
				std::cout<<BIRED<<"Se han encontrado varios alumnos apellidados '"<<dato<<"'"<<RESET<<std::endl;

				std::cout<<"Indique cual es el que desea borrar"<<std::endl;

				for(int i=0;i<buscado.size();i++)
					std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<", "<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
				std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

				std::cout<<"\n Opcion: ";
				std::cin>>opcionapellido;

				while(opcionapellido<0 || opcionapellido>buscado.size())
				{
					std::cout<<BIRED<<"ERROR opcion invalida"<<std::endl<<std::endl;

					std::cout<<"Indique cual es que buscaba"<<std::endl;
					for(int i=0;i<buscado.size();i++)
						std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
					std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

					std::cout<<"\n Opcion: ";
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

	std::cout<<"\n En este momento, se encuentran registrados "<<BICYAN<<p.getAgenda().tamClase()<<RESET<<" alumnos"<<std::endl;
}

void mostrarDatosdeAlumno(Profesor &p)
{
	std::system("clear");
	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\n ERROR No hay alumnos registrados"<<RESET<<std::endl;
		return;
	}
	
	int opcion=0, opcionapellido;
	std::string dato;

	std::vector<int> buscado;

	std::cout<<"\nIndique el dato por el que se identificara al alumno a mostrar"<<std::endl;
	std::cout<<"\n [1] DNI"<<std::endl;
	std::cout<<" [2] Apellido"<<std::endl;
	std::cout<<BIRED <<"\n [0] Volver"<<RESET<<std::endl;

	std::cout<<"\n Opcion: ";
	std::cin>>opcion;

	while(opcion!=0 && opcion!=1 && opcion!=2)
	{
		std::cout<<BIRED<<"ERROR introduzca una opcion valida"<<RESET<<std::endl<<std::endl;

		std::cout<<"Indique el dato por el que se identificara al alumno a mostrar"<<std::endl;
		std::cout<<" [1] DNI"<<std::endl;
		std::cout<<" [2] Apellido"<<std::endl;
		std::cout<<BIRED<<"\n [0] Volver\n"<<RESET<<std::endl;

		std::cout<<"\n Opcion: ";
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
			std::cout<<"\n Introduzca el DNI del alumno: ";
			std::cin>>dato;

			//comprobar DNI
			while(strlen(dato.c_str())!=9)
			{
				std::cout<<BIRED<<"ERROR DNI invalido"<<RESET<<std::endl<<std::endl;
				
				std::cout<<"Introduzca el DNI del alumno: ";
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
			std::cout<<"\n Introduzca el apellido del alumno: ";
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

					std::cout<<"\n Opcion: ";
					std::cin>>opcionapellido;

					if(opcionapellido==0) break;
					while(opcionapellido<1 || opcionapellido>buscado.size())
					{
						std::cout<<BIRED<<"ERROR opcion invalida"<<std::endl<<std::endl;

						std::cout<<"Indique cual es que buscaba"<<std::endl;
						for(int i=0;i<buscado.size();i++)
							std::cout<<" ["<<i+1<<"] "<<p.getAgenda().getAlumno(buscado[i]).getApellido()<<","<<p.getAgenda().getAlumno(buscado[i]).getNombre()<<std::endl;
						std::cout<<BIRED<<"\n\n [0] Volver"<<RESET<<std::endl;

						std::cout<<"\n Opcion: ";
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
		std::cout<<BIRED<<"\n ERROR No hay alumnos registrados"<<RESET<<std::endl;
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
		std::cout<<BIYELLOW<<"(Introduzca un cero sin desea volver)"<<RESET<<std::endl;
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
		std::cout<<std::endl<<BIGREEN<<"\n Alumno "<<i+1<<RESET<<std::endl;
		p.getAgenda().mostrarAlumno(buscado[i]);
	}

	std::cin.ignore();

}

void mostrarListaAlumnos(Profesor &p)
{
	std::system("clear");
	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\n ERROR No hay ningun alumno registrado\n"<<RESET;
		return;
	}

 	std::fstream fichero;

 	fichero.open("listaAlumnos.txt", std::fstream::out | std::fstream::trunc);

 	//comprobacion de apertura correcta del fichero
 	if((fichero.rdstate() & std::fstream::failbit)!=0)
	{
		std::cout<<BIRED<<"Se ha producido un error al intentar abrir el fichero"<<RESET<<std::endl;
		return;
	}

	//insertar los alumnos en el fichero
	for(int i=0;i<p.getAgenda().tamClase();i++)
		fichero<<p.getAgenda().getAlumno(i);
	

	fichero.close();

	std::cout<<BIGREEN<<"La lista de alumnos registrados es la siguiente:\n"<<RESET<<std::endl;

	std::system("cat ./listaAlumnos.txt");

	std::system("rm ./listaAlumnos.txt");

}

void registrarNuevoProfesor(Profesor &p)
{
	std::system("clear");

	std::cout<<"\n Introduzca los datos del nuevo profesor"<<std::endl;

	Profesor nuevo;

	nuevo.leerProfesor();

	if(p.getId()!=-1)
	{
		std::vector<Profesor> profesores;
		std::fstream lectura;

		lectura.open("../profesores.bin", std::fstream::in | std::fstream::binary);

		if((lectura.rdstate() & std::fstream::failbit)!=0)
		{
			std::cout<<BIRED<<"ERROR al abrir el fichero"<<RESET<<std::endl;
			std::cin.ignore();
			return;
		}

		Profesor aux;
		while(lectura>>aux)
			profesores.push_back(aux);

		lectura.close();

		for(int i=0;i<profesores.size();i++)
		{
			if(profesores[i].getId()==nuevo.getId())
			{
				std::cout<<BIRED<<"ERROR El profesor indicado ya se encuentra registrado"<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}
		}
	}

	std::fstream escritura;

	escritura.open("../profesores.bin", std::fstream::app | std::fstream::binary);

	if((escritura.rdstate() & std::fstream::failbit)!=0)
	{
		std::cout<<BIRED<<"ERROR al abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}

	escritura<<nuevo;

	escritura.close();

	std::cout<<BIGREEN<<"Se ha registrado el nuevo profesor satisfactoriamente"<<RESET<<std::endl;

	std::cin.ignore();

}

void cargarCopia(Profesor &p)
{
	std::system("clear");

	//crear fichero llamado clase[fechadelacopia].bin
	std::fstream fichero;

	//nombrefichero=now->tm_mday+'-'+(now->tm_mon + 1)+'-'+(now->tm_year + 1900);
	std::cout<<"\n Introduzca el dia de la copia que desea recuperar"<<std::endl;

	Fecha fecha;
	fecha.leerFecha();

	std::string nombreFichero;
	std::stringstream dia, mes, ano;

	dia<<fecha.getDia();
	mes<<fecha.getMes();
	ano<<fecha.getAgno();

    nombreFichero="../CopiasSeguridad/clase-"+ dia.str();
    nombreFichero+="-"+ mes.str();
    nombreFichero+="-"+ ano.str();
    nombreFichero+=".bin";

	//abrir fichero
	fichero.open(nombreFichero.c_str(), std::fstream::in | std::fstream::binary);

	//comprobar fichero abierto
	if((fichero.rdstate() & std::fstream::failbit)!=0)
	{
		std::cout<<BIRED<<"ERROR No se ha podido abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return;
	}

	Alumno aux;

	//sacar alumnos del fichero
	while(fichero>>aux)
	{
		if(p.getAgenda().buscarAlumno(1,aux.getDNI()).size()==0)
			p.nuevoAlumno(aux);
		else std::cout<<"El alumno '"<<aux.getNombre()<<" "<<aux.getApellido()<<"' ya esta guardado\nPor lo tanto no se ha registrado"<<std::endl;
		aux.setLider(false);
	}

	fichero.close();

	std::cout<<BIGREEN<<"Se ha cargado el fichero satisfactoriamente"<<RESET<<std::endl;

	std::cin.ignore();
}


void crearCopia(Profesor &p)
{
	std::system("clear");

	if(p.getAgenda().tamClase()<=0)
	{
		std::cout<<BIRED<<"\n ERROR No hay alumnos registrados"<<RESET<<std::endl;
		return;
	}

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

	std::fstream fichero;

	fichero.open(nombreFichero.c_str(), std::fstream::out | std::fstream::binary);

	Alumno aux;

	if((fichero.rdstate() & std::fstream::failbit)!=0)
	{
		std::cout<<BIRED<<"ERROR No se ha podido guardar los alumnos"<<RESET<<std::endl;
		return;
	}

	for(int i=0;i<p.getAgenda().tamClase();i++)
		fichero<<p.getAgenda().getAlumno(i);
				
	std::cout<<BIGREEN<<"Los alumnos se guardaron correctamente"<<RESET<<std::endl;

	fichero.close();
}

Profesor logIn()
{
	std::cout<<BIYELLOW<<"\nBIENVENIDO"<<std::endl;
	std::cout<<"Inicie sesion antes de acceder al contenido"<<RESET<<std::endl;


	std::vector<Profesor> bdprofesores;
	Profesor nuevoTutor;


	std::fstream fichero;

	fichero.open("../profesores.bin", std::fstream::in | std::fstream::binary);

	if((fichero.rdstate() & std::fstream::failbit)!=0)
	{
		std::cout<<BIRED<<"ERROR al abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
		return nuevoTutor;
	}

	fichero.seekg(0,std::ios::beg);

	Profesor aux;
	while(fichero>>aux)
		bdprofesores.push_back(aux);
	
	std::string usuario, contrasena;

	std::cout<<"Introduzca sus credenciales"<<std::endl;

	std::cout<<"\n Usuario --> ";
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
