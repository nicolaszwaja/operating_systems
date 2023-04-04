//podprogram tworzący trzy podprocesy korzystając z podpunktu a zadania
//oraz czekający aż dzieci odbiorą sygnał od najstarszego przodka

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	
	//niepoprawna ilość argumentów
	if (argc < 4) {
		printf("podano za mało argumentów\n");
		exit(-1);
	} else if (argc > 4) {
		printf("podano za dużo argumentów\n");
		exit(-1);
	}
	
	int status = 0;
	
	setpgid (0,0);
	printf("PID podprocesu: %d\n", getpgrp());
	
	for (int i = 0; i < 3; i++) {
		
		switch (fork ()) {
			case -1:
				perror("błąd funkcji fork");
				exit(1);
			case 0:
				// akcja dla procesu wnuka
				
				// przełączanie na programA
				execl(argv[3], argv[3], argv[1], argv[2], NULL);
				
				break;
				
			default:
				//akcja dla procesu dziecka
				
				break;
		};
	}
	
	//proces będący liderem grupy procesów ignoruje sygnały
	if (signal(atoi(argv[1]),SIG_IGN) == SIG_ERR) {
		perror("błąd funkcji signal");
		exit(2);
	}

	
	int pidProcesu;
	
	for (int i = 0; i < 3; i++) {
		if ((pidProcesu = wait(&status)) == -1) {
			perror ("błąd funkcji wait");
			exit(3);
		}
		//wypisanie statusu zwracanego przez funkcję wait
		printf("status zakończenia procesu %d: %d\n", pidProcesu, status);
	}
	
}
