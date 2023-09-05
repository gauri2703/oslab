#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h> 
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
 
int main(int argc, char *argv[])
{    int  n;// An integer variable used to store the result of the read function.
    int fd[2];//: An integer array of size 2, representing a pipe. fd[0] is the file descriptor for reading from the pipe, and fd[1] is the file descriptor for writing to the pipe.
    char buf[1025];// A character array (string) to store the data read from the pipe.
    char *data="My name is Gauri";//A pointer to a constant string containing the message "Mid Term Lab Exams from tomorrow!"
    pipe(fd);//creates a pipe using the pipe system call.After this line, fd[0] will be the read end of the pipe, and fd[1] will be the write end.
    write(fd[1],data,strlen(data));//It writes the content of the data string to the write end of the pipe (fd[1]) using the write system call
    //It reads data from the read end of the pipe (fd[0]) using the read system call.
    n = read(fd[0], buf, 1024);
    if (n >= 0)
    {
        buf[n] = 0;
        printf("Read %d bytes from pipe: \"%s\"\n", n, buf);
        }
    else
        perror("Read");
        exit(0);
}