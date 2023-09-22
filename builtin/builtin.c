/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:33:08 by rakpinar          #+#    #+#             */
/*   Updated: 2023/09/13 17:33:08 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

#include <stdio.h>
#include <string.h>


int is_builtin(char *input)
{
	const char *builten_commands[] = {"cd","exit", "unset", "export", "env", "pwd", "echo",'\0'};

	int i = 0;

	while(builten_commands[i] != NULL)
	{
		if(strcmp(builten_commands[i], input) == 0) //gecerli bir konut girildiyse strcmpden 0 degeri gelir.
		return(1);									//direkt if(strcmp(builten_commands[i], input)) da yazilabilir.

	i++;
	}
	return(0);
}

// int main(int argc, char **argv)
// {
// 	if(argc > 1)
// 	{
// 		int return_value;

// 		return_value = is_builtin(argv[1]);
// 		printf("return_value %d\n", return_value);

// 		if(return_value == 1)
// 			printf("successful input %s\n", argv[1]);

// 		else
// 			printf("Command '%s' not found \n", argv[1]);
		 
// 		return 0;
// 	}
// 	printf("Invalid argument");
// }


void	run_builtin(char **execute)
{
	int	command;

	command = is_builtin(execute[0]);
	// if (command == CD)
	// 	builtin_cd(execute);
	// if (command == ENV)
	// 	builtin_env();
	// if (command == PWD)
	// 	builtin_pwd();
	if (command == ECHO)
		builtin_echo(execute);
	// if (command == EXIT)
	// 	builtin_exit(execute);
	// if (command == UNSET)
	// 	builtin_unset(execute);
	// if (command == EXPORT)
	// 	builtin_export(execute);
}

