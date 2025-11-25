#include <stdlib.h>
#include <unistd.h>

int	picoshell(char **cmds[])
{
	pid_t pid;
	int fd[2];
	int i;
	int prev;

	i = 0;
	prev = -1;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd))
			return (1);
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (prev != -1)
			{
				if (dup2(prev, STDIN_FILENO) == -1)
					exit(1);
				close(prev);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev != -1)
			close(prev);
		if (cmds[i + 1])
		{
			close(fd[1]);
			prev = fd[0];
		}
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}