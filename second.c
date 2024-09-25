#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
  pid_t p=fork();
  if(p<0){
          printf("fork fail\n");
  }if(p==0){
            printf("I am a child process with id: %d\n", getpid());
            printf("My parent id is: %d\n", getpid());
  }else{
        printf("I am a parent process with id: %d\n", getpid());
        printf("My child process is: %d\n", p);
  }
}
