
/*Uruchomić powyższy program poprzez funkcję exec w procesie potomnym innego procesu i wysyłać do niego sygnały poprzez funkcję systemową kill z procesu macierzystego.*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


int main (int argc, char *argv[]) {
	
	int pidDziecka = 0;
	
	//niepoprawna ilość argumentów
	if (argc < 4) {
		printf("podano za mało argumentów\n");
		exit(-1);
	} else if (argc > 4) {
		printf("podano za dużo argumentów\n");
		exit(-1);
	}
	

	
	switch (pidDziecka = fork ()) {
		case -1:
			perror("błąd funkcji fork");
			exit(1);
		case 0:
			//akcja dla procesu potomnego
			// przełączanie na wcześniejszy podpunkt
			execl(argv[3], argv[3], argv[1], argv[2], NULL);
			break;
			
		default:
			//akcja dla procesu macierzystego
			sleep(1);
			printf("czekam na sygnał\n");
			sleep(1);
			
			//sprawdzam czy proces istnieje
			//jeżeli sig=0 to funkcja kill przeprowadza test błędów
			if (kill(pidDziecka, 0) == -1) {
				perror("dziecko nie istnieje\n");
				exit(2);
			}
			kill(pidDziecka, atoi(argv[1]));
			break;
			
	}
}
