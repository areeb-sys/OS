#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define CREATE_FLAGS (O_WRONLY | O_CREAT | O_APPEND)
#define CREATE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int  main(int args, char * argv[]) 

{
   int fd;
   pid_t childpid;
   printf("I am parent, my PID is %d, and I am going to call fork\n",getpid());
   childpid = fork();

   if (childpid == 0) 
   {
   	                            /* child code */
	fd = open(argv[1], CREATE_FLAGS, CREATE_MODE);
	if(fd == -1)
	{
	perror("Failed to open file");
	return 1;
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
	perror("Failed to redirect standard output");
	return 1;
	}
	if (close(fd) == -1) 
	{
    	perror("Failed to close the file");
    	return 1;
	}
       printf ("I am child my PID is %d and my PPID is %d\n", getpid(), getppid());
       execl("/bin/ls", "ls", NULL);
       perror("Child failed to exec ls");
       return 1; 
   }
   
   if (childpid != wait(NULL)) 
   {                  
       perror("Parent failed to wait due to signal or error");
       return 1;
   }

   printf ("I am so sad, my child just died\n");
   return 0; 
}

