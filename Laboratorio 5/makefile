#Makefile para Windows y Linux del codigo Laboratorio_5_19083864-1.c por Cristobal Medrano.

#Comprobamos el Sistema Operativo.
ifeq ($(OS),Windows_NT)
    OS_detected := Windows
else
    OS_detected := $(shell uname -s)
endif

#Seleccionamos las variables a cambiar dependiendo del OS.
ifeq ($(OS_detected), Windows)
	EJECUTABLE = Laboratorio.exe
    REMOVE = -del
endif
ifeq ($(OS_detected), Linux)
	EJECUTABLE = Laboratorio.out
    REMOVE = -rm -f
endif

#Carpeta de modulos y cabeceras
SOURCES = Source_files/
HEADERS = Header_files/

#Variables
CCDebug = gcc -Wall
CC = gcc -Wall
INCLUDE = -I $(HEADERS)
OBJECTS = Menu.o TDA_LE.o TDA_ABO.o TDA_AVL.o Lectura.o Busqueda.o Escritura.o Laboratorio_5_19083864-1.o

.SILENT: clean all
all: $(OBJECTS)
	$(CC) -o $(EJECUTABLE) $(OBJECTS)
	echo Compilacion Completa. Ejecutable: $(EJECUTABLE)

Menu.o: $(SOURCES)Menu.c $(HEADERS)Menu.h
	$(CC) $(INCLUDE) -c $(SOURCES)Menu.c -o Menu.o

Lectura.o: $(SOURCES)Lectura.c $(HEADERS)Lectura.h
	$(CC) $(INCLUDE) -c $(SOURCES)Lectura.c -o Lectura.o

TDA_LE.o: $(SOURCES)TDA_LE.c $(HEADERS)TDA_LE.h
	$(CC) $(INCLUDE) -c $(SOURCES)TDA_LE.c -o TDA_LE.o

TDA_ABO.o: $(SOURCES)TDA_ABO.c $(HEADERS)TDA_ABO.h
	$(CC) $(INCLUDE) -c $(SOURCES)TDA_ABO.c -o TDA_ABO.o

TDA_AVL.o: $(SOURCES)TDA_AVL.c $(HEADERS)TDA_AVL.h
	$(CC) $(INCLUDE) -c $(SOURCES)TDA_AVL.c -o TDA_AVL.o

Busqueda.o: $(SOURCES)Busqueda.c $(HEADERS)Busqueda.h
	$(CC) $(INCLUDE) -c $(SOURCES)Busqueda.c -o Busqueda.o

Escritura.o: $(SOURCES)Escritura.c $(HEADERS)Escritura.h
	$(CC) $(INCLUDE) -c $(SOURCES)Escritura.c -o Escritura.o

Laboratorio_5_19083864-1.o: Laboratorio_5_19083864-1.c $(HEADERS)Estructuras.h
	$(CC) $(INCLUDE) -c Laboratorio_5_19083864-1.c -o Laboratorio_5_19083864-1.o

.PHONY: clean
clean:
	$(REMOVE) $(OBJECTS) $(EJECUTABLE)
	echo Limpieza Completa.