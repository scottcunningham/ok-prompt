#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <unistd.h>

void sighand(int sig)
{
	printf("Resistance is futile\n");
}

int main(int argc, char* argv[])
{
	assert(argc == 1); //no arguments because you can't call this program, it fucking does it itself whether you want it to or not. DEAL WITH IT.

	char input[50];

	while(1)
	{

		signal(SIGINT,&sighand);
		printf("(ok) > ");
		fgets(input,100,stdin);
		
		if(strcmp(input,"help\n") == 0)
			printf("Have you considered a job in Oracle?\n");

		else if(strcmp(input,"power off\n") == 0)
			printf("lol\n");

		else if(strcmp(input,"help power\n") == 0)
			printf("Try 'power off now'\n");

		else if(strcmp(input,"matrix is the best purple box ever\n") == 0)
		{	
			printf("A CHALLENGER APPEARS\n");
			system("$(which bash)");
		}

		else
		{
			input[strlen(input)-1] = '\0';
			printf("%s?\n",input);
		}
	}
}
