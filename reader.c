#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define FIFO_NAME "myfifo"
#define SIZE 100
int main()
{
int fd;
char data[SIZE];
fd=open(FIFO_NAME,O_RDONLY);
if(fd==-1)
{
printf("Error opening the FIFO for reading");
exit(0);
}
ssize_t bytes=read(fd,data,SIZE);
printf("Received: %s\n",data);
close(fd);
}
