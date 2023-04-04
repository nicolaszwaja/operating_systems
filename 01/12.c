//Wywołać funkcje fork trzy razy (najlepiej w pętli for) i wypisać powyższe identyfikatory dla procesu macierzystego oraz wszystkich procesów potomnych. Przy pomocy funkcji wait sprawić, aby proces macierzysty zaczekał na zakonczenie wszystkich procesów potomnych.

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


void wypisz(){
  printf("id UID: %d\n", getuid());
  printf("id GID: %d\n", getgid());
  printf("id PID: %d\n", getpid());
  printf("id PPID: %d\n", getppid());
  printf("id PGID: %d\n\n", getpgid(getpid()));
}

int main(){
  
  wypisz();
  for(int i=0;i<3;i++){
		switch(fork())
		{
		case -1 : printf("fork error\n");
			 exit(1);  //wyjście z procesu
		case 0 : wypisz(); //jeśli jest potomny to wypisz jego id
			 break;
		default: wait(0); // wstrzymanie p. wywolujacego fork() do momentu zakonczenia p. potomnego
			 break;
		}
	}
 
	return 0;
}
