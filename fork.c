#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
  pid_t p=fork();
  if(p<0){
          printf("fork fail");
          exit(1);
  }
  printf("Hello all,My process id is: %d",getpid());
}
