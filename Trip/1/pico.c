#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int	picoshell(char **cmds[])
{
	int fd[2];
	int i = 0;
	int prev = -1;
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd))
			return 1;
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return -1;
		}
		if (pid == 0)
		{
			if (prev != -1)
			{
				if(dup2(prev , STDIN_FILENO)== -1)
					exit(1);
				close(prev);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if(dup2(fd[1] , STDIN_FILENO)== -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0] , cmds[i]);
			exit(1);
		}
		if(prev != -1)
			close(prev);
		if(cmds[i + 1])
		{
			close(fd[1]);
			prev =fd[0];
		}
		i++;
	}
	while(wait(NULL) > 0);
	return 0;
}
int main(int argc, char **argv)
{
	int cmds_size = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	}
	char ***cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return 1;
	}
	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return ret;
}