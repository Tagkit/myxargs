#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_SIZE 255

int main(int argc, char * argv[]) {
	char in_buffer[MAX_SIZE];
	fflush(stdout);
	while(fgets(in_buffer, MAX_SIZE, stdin)!=NULL) {
		
		int pid=fork();
		if(pid==-1) {
			perror("ERROR: Process couldn't fork\n");
			exit(1);
		} else if (pid==0) {
			char * arg_list[3]; 
			memcpy(arg_list,&argv[1],1*sizeof(char *));
			arg_list[1]=in_buffer;
			arg_list[2]=NULL;
			execvp(argv[1],arg_list);
			perror("ERROR: '%s' failed to execute",argv[1]);
			exit(1);
		}
		fflush(stdout);
	}
	while (wait(NULL) > 0);
	printf("Finished executing commands\n");
	exit(0);
}

void print_help() {
	printf("Usage: myxargs [-n num] [-I replace] [-t] [-r] command");
}
