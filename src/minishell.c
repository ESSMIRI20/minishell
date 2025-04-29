#include "../include/minishell.h"
#include "../Libft/libft.h"

const char *check_exec(char *s)
{
	int    i;

	i = 0;
	char **str = ft_split(getenv("PATH"), ':');
	while(str[i])
	{
		const char *path = ft_strjoin(str[i], "/");
		path = ft_strjoin(path, s);
		if(access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void command_exec()
{
	while(1)
	{
		char *s = readline("$>");
		char **str = ft_split(s, ' ');
		const char *path = check_exec(str[0]);
		pid_t pid = fork();
		if(pid == 0)
			execve(path, &str[0], NULL);
		else if(pid > 0)
			wait(NULL);
	}
}

int main()
{
	command_exec();
	return (0);
}
