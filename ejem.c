#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int main(int argc, char *argv[]) {
  pid_t pid_h1, pid_h2;
  int status;
  pid_h1 = fork();
  if(pid_h1 == 0) {
    // Proceso hijo el cual ejecuta el comando ls
    execl("/bin/lp","/bin/lp",NULL);
    execl("/bin/ls","/bin/ls","-l",NULL);
  }
  else {
   
      // Proceso padre
      wait(&status); // wait para esperar un proceso
      printf("Ya termino el padre"); 
  }
  return 0;
}