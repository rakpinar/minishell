#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void builtin_cd(char **input) 
{
	char *home = getenv("HOME");

  	if (input[1] != NULL) 
  	{
    	if (chdir(input[1]) != 0) 
		{
			perror("minishell: cd");
			exit(1);
    	}
  	} 

  	else if (home != NULL && *home != '\0') 
	{
			chdir(home);
 	} 	
  
	else 
  	{
    	printf(stderr, "minishell: cd: HOME not set\n");
    	exit(1);
 	}

	if (!is_parent())
		exit (errno);
}



int main(int argc, char **argv) 
{
	if(argc > 1)
    {
    	builtin_cd(argv);
	}
	printf("Invalid arguments");
    return 0;
}
