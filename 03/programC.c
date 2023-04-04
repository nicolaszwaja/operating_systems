/*W procesie macierzystym utworzyć proces potomny i sprawić, aby stał się liderem nowej grupy procesów (funkcja setpgid), a następnie uruchomić w nim kilka procesów potomnych wykonujących program do obsługi sygnałów.
Z pierwszego procesu macierzystego wysyłać sygnały do całej grupy procesów potomnych po uprzednim sprawdzeniu jej istnienia (jak wyżej).
Identyfikator tej grupy procesów uzyskać przy pomocy funkcji getpgid.
Proces będący liderem grupy procesów niech ignoruje sygnały, a na końcu czeka na zakończenie wszystkich swoich procesów potomnych i wypisuje ich status zakończenia zwracany przez funkcję wait.
*/

#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L //warningi dla kill 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main (int argc, char *argv[]) {
	
	int pidDziecka = 0;
	int pidGrupyDziecka = 0;
	
	// obsługa niepoprawnej ilość argumentów
	if (argc < 5) {
		printf("podano za mało argumentów\n");
		exit(-1);
	} else if (argc > 5) {
		printf("podano za dużo argumentów\n");
		exit(-1);
	}
	
	printf("PID procesu: %d\n", getpid());
	
	switch (pidDziecka=fork ()) {
		case -1:
			perror("błąd funkcji fork");
			exit(1);
		case 0:
			//akcja dla procesu potomnego
			// przełączanie na podprogram
			if (execl(argv[3], argv[3], argv[1], argv[2], argv[4], NULL) == -1) {
				perror("błąd funkcji execl");
				exit(2);
			}
			
			break;
			
		default:
			//akcja dla procesu macierzystego
			printf("czekam na sygnał\n");
			sleep(3);
			pidGrupyDziecka = getpgid (pidDziecka);
			
			//sprawdzam czy proces istnieje
			//jeżeli sig=0 to funkcja kill przeprowadza test błędów
			//np sprawdza czy proces istnieje
			
			if (kill (-1 * pidGrupyDziecka, 0) == -1) {
				perror("dziecko nie istnieje");
				exit(3);
			}
			
			if (kill (-1 * pidGrupyDziecka, atoi(argv[1]))) {
				perror ("błąd funkcji kill");
				exit(4);
			}
			//-1 bo wtedy sygnał zostanie odebrany przez procesy należące
			//do grupy o pgid=-pid, a nie tylko proces o danym pid
		
	}
}
