//AUTHOR:AREEB AHMED (FA19_BSE_022)_B


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFSIZE 10

int main(void)
{
	char bufin[BUFSIZE] = "empty";
	char bufout[] = "hello";
	int bytesin;
	pid_t childpid;
	int fd[2];

	if(pipe(fd)==-1){
	perror("Failed to create the pipe");
	return 1;
}
	bytesin = strlen(bufin);
	childpid = fork();
	if(childpid == -1){
	perror("Failed to fork");
	return 1;
}
	if(childpid)	/*parent code*/
	{
		write(fd[1],bufout,strlen(bufout)+1);
	}
	if(dup2(fd[0],fd[1])==-1)
	   perror("Failed to dup2()");
	close(fd[0]);
		/*child code*/
	
	bytesin = read(fd[1],bufin,BUFSIZE);
	close(fd[1]);
	fprintf(stderr,"%d ",fd[1]);

	

	return 0;
}
