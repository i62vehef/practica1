CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(IS)
set (CMAKE_CXX_FLAGS "-lrt -g")
add_executable(Principal.exe principal.cpp funcionesAuxiliares.cpp alumno.cpp listaAlumnos.cpp profesor.cpp)
