#Makefile para Windows y Linux del codigo Laboratorio_3_19083864-1.c

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

CC = gcc 
OBJECTS = Menu.o Lectura.o TDA_Listas_Enlazadas.o Escritura.o Ejecucion.o Laboratorio_3_19083864-1.o

all: $(OBJECTS)
	$(CC)-o $(EJECUTABLE) $(OBJECTS)
	echo Compilacion Completa.
Menu.o: Menu.c
	$(CC)-c Menu.c -o Menu.o
Lectura.o: Lectura.c
	$(CC)-c Lectura.c -o Lectura.o
TDA_Listas_Enlazadas.o: TDA_Listas_Enlazadas.c
	$(CC)-c TDA_Listas_Enlazadas.c -o TDA_Listas_Enlazadas.o
Escritura.o: Escritura.c
	$(CC)-c Escritura.c -o Escritura.o
Ejecucion.o: Ejecucion.c
	$(CC)-c Ejecucion.c -o Ejecucion.o
Laboratorio_3_19083864-1.o: Laboratorio_3_19083864-1.c
	$(CC)-c Laboratorio_3_19083864-1.c -o Laboratorio_3_19083864-1.o
clean:
	$(REMOVE) $(OBJECTS) $(SALIDA)
	echo Limpieza Completa.