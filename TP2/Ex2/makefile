main.out: main.c Menu.o Rebond.o Rectangle.o CarreClic.o
	gcc -o main.out main.c Menu.o Rebond.o Rectangle.o CarreClic.o \-fdiagnostics-color=always -Wall -Wfatal-errors -lncurses

Menu.o: Menu.c Menu.h Rebond.o
	gcc -c Menu.c Rebond.c -lMLV -lm -fdiagnostics-color=always -Wall -Wfatal-errors -lncurses

Rebond.o: Rebond.c Rebond.h
	gcc -c Rebond.c -lMLV -lm -fdiagnostics-color=always -Wall -Wfatal-errors -lncurses

Rectangle.o: Rectangle.c Rectangle.h
	gcc -c Rectangle.c -lMLV -lm -fdiagnostics-color=always -Wall -Wfatal-errors -lncurses

CarreClic.o: CarreClic.c CarreClic.h
	gcc -c CarreClic.c -lMLV -lm -fdiagnostics-color=always -Wall -Wfatal-errors -lncurses

clean:
	rm *.o *.out