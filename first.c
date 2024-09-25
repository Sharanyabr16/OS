#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
//pid_t wait(int *wstatus);
int main()
{
  pid_t p=fork();
  if(p==0){
           printf("Child Process\n");
  }else{
        printf("Parent  Process\n");
  wait(NULL);
  printf("Child process has terminated\n");
  }
  printf("BYE\n");
}
