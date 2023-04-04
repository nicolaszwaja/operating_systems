/*Napisać program do obsługi sygnałów z możliwościami:
(1) wykonania operacji domyślnej
(2) ignorowania oraz
(3) przechwycenia i własnej obsługi sygnału.
Do oczekiwania na sygnał użyć funkcji pause.
Uruchomić program i wysyłać do niego sygnały przy pomocy sekwencji klawiszy oraz przy pomocy polecenia kill z poziomu powłoki.*/

#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void przechwycenie() {
	
	printf("sygnał został przechwycony\n");
	
}

int main (int argc, char *argv[]) {
	
	
	//niepoprawna ilość argumentów
	if (argc < 3) {
		printf("podano za mało argumentów\n");
		exit(-1);
	} else if (argc > 3) {
		printf("podano za dużo argumentów\n");
		exit(-1);
	}

	
	// wypisywanie PIDu procesu
	printf("PID procesu: %d\n", getpid());
	
	if (strcmp(argv[2], "ignoruj") == 0) {
		signal(atoi(argv[1]),SIG_IGN);	//atoi:zmiana argumentu na int
	} 
	else if (strcmp(argv[2], "domyslna") == 0) {
		signal(atoi(argv[1]),SIG_DFL);
	} 
	else if (strcmp(argv[2], "przechwyc") == 0) {
		signal(atoi(argv[1]),przechwycenie);
	} 
	else {
		printf("nie ma opcji: %s\n", argv[2]);
	}
	
	pause(); //oczekiwanie na sygnał
}


