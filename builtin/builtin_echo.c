
#include "../minishell.h"

extern t_minishell	g_ms;

int	is_parent(void)
{
	return (g_ms.parent_pid == getpid());
}

void	put_char(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		write(STDOUT_FILENO, &(input[i]), 1);
		i++;
	}
}

int	skip_flag(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (strcmp(str[i], "-n"))
			i++;
		else
			break ;
	}
	return (i);
}

void	builtin_echo(char **input)
{
	int	i;
	int	flag;

	i = 1;
	flag = TRUE;
	i = skip_flag(input);
	if (i > 1)
		flag = FALSE;
	while (input[i])
	{
		put_char(input[i]);
		if (input[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (flag)
		write(STDOUT_FILENO, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {


  if (argc == 1) {
    printf("\n");
  } else {
    builtin_echo(argv + 1);
  }

  return 0;
}