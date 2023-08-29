//A hard link is a feature of many file systems in Unix-like operating systems where multiple directory entries point to the same inode (the data structure that contains metadata and pointers to the file's data blocks). In other words, it's like having multiple filenames that all refer to the same underlying file data. All hard links to the same file are treated equally – there's no concept of a "main" link.
/*It takes the old path as a command-line argument (argc and argv).
It includes error handling to check if the provided arguments are sufficient.
It uses the stat function to get the number of hard links before and after the linking and unlinking operations.
It uses the system function to execute the ls command and display the directory contents.
It is less verbose and does not include user prompts.*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
void main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Insufficient arguments\n");
        return;
    }
 
    char new_path[100]="q1l3.c";
    struct stat start;
    int ret1 = stat(argv[1],&start);
    printf("Number of hard links:%ld\n", start.st_nlink);
    system("ls");
    printf("Linking..\n");
    int ret2 = link(argv[1],new_path);
    struct stat intermediate;
    int ret3 = stat(argv[1],&intermediate);
    printf("Number of hard links:%ld\n", intermediate.st_nlink);
    printf("New path:%s\n",new_path);
    system("ls");
    int ret4 = unlink(argv[1]);
    struct stat ending;
    int ret5 = stat(new_path,&ending);
    printf("Unlinking...\n");
    printf("Number of hard links after unlinking:%ld\n", ending.st_nlink);
    system("ls");
}