all: Lectura.out Menu.out Laboratorio_3_19083864-1.out
	gcc Lectura.out Menu.out Laboratorio_3_19083864-1.out -o Laboratorio.exe
Lectura.out: Lectura.c
	gcc -c Lectura.c -o Lectura.out
Menu.out: Menu.c
	gcc -c Menu.c -o Menu.out
Laboratorio_3_19083864-1.out: Laboratorio_3_19083864-1.c
	gcc -c Laboratorio_3_19083864-1.c -o Laboratorio_3_19083864-1.out
clean:
	rm Lectura.out Menu.out Laboratorio_3_19083864-1.out Laboratorio.exe