#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
    if(pid<0){
              printf("fork failed\n");
              return 1;
    }else if(pid==0){
                     printf("C) Child is having id: %d\n",getpid());
                     printf("D) My Parent id is: %d\n",getpid());
    }else{
          printf("A) Parent(P) is having id: %d\n",getpid());
          wait(NULL);
          printf("B) id of P's Child is: %d\n",pid);
    }

    return 0;
}
