all: Crypt.out Decrypt.out

Crypt.out: common.c common.h Crypt.c makefile
	gcc common.c Crypt.c -o Crypt.out -fdiagnostics-color=always -Wall -Wfatal-errors

Decrypt.out: common.c common.h Decrypt.c makefile
	gcc common.c Decrypt.c -o Decrypt.out -fdiagnostics-color=always -Wall -Wfatal-errors

clean:
	rm '*.o' '*.out'