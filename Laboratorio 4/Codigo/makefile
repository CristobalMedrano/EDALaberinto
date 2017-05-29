#Makefile para Windows y Linux del codigo Laboratorio_4_19083864-1.c por Cristobal Medrano.

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
SOURCES = Sources/
HEADERS = Headers/

#Variables
CCDebug = gcc -Wall
CC = gcc
INCLUDE = -I $(HEADERS)
OBJECTS = Lectura.o TDA_ABO.o Laboratorio_4_19083864-1.o

.SILENT: clean all
all: $(OBJECTS)
	$(CC) -o $(EJECUTABLE) $(OBJECTS)
	echo Compilacion Completa. Ejecutable: $(EJECUTABLE)

Lectura.o: $(SOURCES)Lectura.c $(HEADERS)Lectura.h
	$(CC) $(INCLUDE) -c $(SOURCES)Lectura.c -o Lectura.o

TDA_LE.o: $(SOURCES)TDA_LE.c $(HEADERS)TDA_LE.h
	$(CC) $(INCLUDE) -c $(SOURCES)TDA_LE.c -o TDA_LE.o

TDA_ABO.o: $(SOURCES)TDA_ABO.c $(HEADERS)TDA_ABO.h
	$(CC) $(INCLUDE) -c $(SOURCES)TDA_ABO.c -o TDA_ABO.o

Laboratorio_4_19083864-1.o: Laboratorio_4_19083864-1.c $(HEADERS)Estructuras.h
	$(CC) $(INCLUDE) -c Laboratorio_4_19083864-1.c -o Laboratorio_4_19083864-1.o

.PHONY: clean
clean:
	$(REMOVE) $(OBJECTS) $(EJECUTABLE)
	echo Limpieza Completa.