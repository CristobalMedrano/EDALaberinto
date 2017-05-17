#Makefile para Windows y Linux del codigo Laboratorio_3_19083864-1.c

#Comprobamos el Sistema Operativo.
ifeq ($(OS),Windows_NT)
    OS_detected := Windows
else
    OS_detected := $(shell uname -s)
endif

#Seleccionamos las variables a cambiar dependiendo del OS.
ifeq ($(OS_detected), Windows)
	SALIDA = Laboratorio.exe
    REMOVE = -del
endif
ifeq ($(OS_detected), Linux)
	SALIDA = Laboratorio.out
    REMOVE = -rm
endif

CC = gcc 
OBJECTS = Lectura.o Menu.o Ejecucion.o Laboratorio_3_19083864-1.o

all: $(OBJECTS)
	$(CC)-o $(SALIDA) $(OBJECTS)
	echo Compilacion Completa.
Lectura.o: Lectura.c
	$(CC)-c Lectura.c -o Lectura.o
Menu.o: Menu.c
	$(CC)-c Menu.c -o Menu.o
Ejecucion.o: Ejecucion.c
	$(CC)-c Ejecucion.c -o Ejecucion.o
Laboratorio_3_19083864-1.o: Laboratorio_3_19083864-1.c
	$(CC)-c Laboratorio_3_19083864-1.c -o Laboratorio_3_19083864-1.o
clean:
	$(REMOVE) $(OBJECTS) $(SALIDA)
	echo Limpieza Completa.