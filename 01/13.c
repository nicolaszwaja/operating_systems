//Jak w (b), tylko przy użyciu funkcji sleep (! nie używać funkcji wait) sprawić by procesy potomne były adoptowane przez proces init lub systemd; poleceniem pstree -p z poziomu powloki wyswietlic drzewo procesow w danym systemie i zidentyfikować proces adoptujący osierocone procesy.
//proces adoptujący osierocone procesy to systemd

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
  
 	
 	switch(fork())
		{
		case -1 : printf("fork error\n");
			exit(1);
		case 0 : 
			sleep(1);
			printf("potomne powstałe po %d forku\n",i+1);	
			wypisz();
			break;
		default: 
			break;
		}	

	}
}


