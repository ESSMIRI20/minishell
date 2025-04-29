#include "../include/minishell.h"
#include "../Libft/libft.h"

char *check_exec(char *s)
{
	int    i;

	i = 0;
	char **str = ft_split(getenv("PATH"), ':');
	while(str[i])
	{
		char *path = ft_strjoin(str[i], "/");
		path = ft_strjoin(path, s);
		if(access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

void command_exec()
{
		char buffer[1024];
		char *buff = "";
		buff = ft_strjoin(buff, CYELL "enigma@minishell:" GREEN);
		buff = ft_strjoin(buff, getenv("PWD"));
		buff = ft_strjoin(buff, RESET "$ ");
		char *s = readline(buff);
	while(1)
	{
		char **str = ft_split(s, ' ');
		char *path = check_exec(str[0]);
		pid_t pid = fork();

		if(pid == 0)
		{
			if(ft_strncmp(path, "cd", 2) == 0)
			{
				chdir("src");
    			if (getcwd(buffer, sizeof(buffer)) != NULL)
       				printf("Current working directory: %s\n", buffer);
				else
        			perror("getcwd failed");
			}
			else
				execve(path, &str[0], NULL);
		}
		else if(pid > 0)
			wait(NULL);
		s = readline(buff);
	}
}

int main()
{
	command_exec();
	return (0);
}
