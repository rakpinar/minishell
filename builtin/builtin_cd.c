void builtin_cd(char **input)
{
	char *directory;

	if(input[1] == NULL)
		directory = getenv("HOME");
	else
		directory = input[1];
		
		if (chdir(directory) != 0) {
		errno = 1;
		write(2, "minishell : No such file or directory\n", 38);
		strerror(errno);
		if (!is_parent()) {
			exit(errno);
		}
	}
}
