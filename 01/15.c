//Jak w (b), tylko przy uzyciu fukcji setpgid sprawic by kazdy proces potomny stawal sie liderem swojej wlasnej grupy procesow

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
  
    printf("\n\nproces macierzysty\n");
  wypisz();
  for(int i=0;i<3;i++){
   printf("potomne powstałe po %d forku\n",i+1);
		switch(fork())
		{
		case -1 : printf("fork error\n");
			exit(1);
		case 0 : wypisz();
			 setpgid(0,0); //jeśli potomny
			 break;
		default: wait(0); // jesli macierzysty
			 break;
		}

	}
	
  	
 
	return 0;
}
