
//Zmodyfikowac program z ´cwiczenia 1b, tak aby komunikaty procesow potomnych byly wypisywane przez program uruchamiany przez funkcje execlp. Nazwe programu do uruchomienia przekazywac przez argumenty programu procesu macierzystego.
// Ile procesow powstanie przy n-krotnym wywolaniu funkcji fork-exec jak wy˙zej i dlaczego?

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main (int argc, char *argv[]) { //przekazanie nazwy podprogramu
	
	
	int i = 0;
	for (i = 0; i < 3; i++) {
		
		switch (fork ()) {
			case -1:
				perror("fork error");
				exit(1);
				
			case 0:
				 //jeśli jest potomny to wypisz jego id za pomocą podprogramu
				 //printf(argv[]);
				printf(argv[1]);
				execl( argv[1], NULL);
				break;
				
			default:
				wait(0);
		}
		
	}
	printf ("Macierzysty\n");
	execl (argv[1], argv[1], NULL);
	
}
