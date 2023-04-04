//Napisać program wypisujący identyfikatory UID, GID, PID, PPID i PGID dla danego procesu

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

  printf("id UID: %d\n", getuid());
  printf("id GID: %d\n", getgid());
  printf("id PID: %d\n", getpid());
  printf("id PPID: %d\n", getppid());
  printf("id PGID: %d\n\n", getpgid(getpid()));
 
return 0;
}
