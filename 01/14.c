//Jak w (b), tylko wstawic funkcje sleep w takich miejscach programu, aby procesy pojawialy sie na ekranie grupowane pokoleniami od najstarszego donajmlodszego, a proces macierzysty konczyl sie dopiero po procesach potomnych(! nie uzywac funkcji wait). Na podstawie wynikow programu sporzadzic (w pliku tekstowym) ,,drzewo genealogiczne” tworzonych proces´ow z zaznaczonymi identyfikatorami PID, PPID i PGID.

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

void wypisz2(char file[], const char * restrict mode){
  FILE *fout=fopen(file, mode);
  fprintf(fout,"PID:%d,PPID:%d,PGID:%d\n", getpid(),getppid(),getpgid(getpid()));
  fclose(fout);
}

void wypiszpokolenie(char file[], const char * restrict mode, int i){
  FILE *fout=fopen(file, mode);
  fprintf(fout,"pokolenie nr%d\n", i+2);
  fclose(fout);
}

int main(){
  
  printf("\n\nproces macierzysty\n");
  wypisz();
  int i =-1;
  wypiszpokolenie("drzewo.txt","w", i);
  wypisz2("drzewo.txt","a");
  
  for(int i=0;i<3;i++){
  
 	printf("ten proces potomny powstał po %d forku\n",i+1);
 	switch(fork())
		{
		case -1 : printf("fork error\n");
			exit(1);
		case 0 : 
			wypisz();
			wypiszpokolenie("drzewo.txt","a", i);
			wypisz2("drzewo.txt","a");
			break;
		default: 
			sleep(5);
			break;
		}	
		sleep(7);
	}
}

