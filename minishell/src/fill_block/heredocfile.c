/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:47:08 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:47:09 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include <signal.h>
#include <sys/wait.h>

int	g_sin;

static void	write_to_file(char *line, int fd)
{
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

static void	sig_heredoc(int sig)
{
	(void)sig;
	g_sin = -3;
}

static void	ft_signl(void)
{
	signal(SIGINT, sig_heredoc);
	if (g_sin == -3)
		exit(1);
}

void	ft_get_heredoc_lines(char *delim, int fd, t_data *g_data)
{
	char	*line;
	char	*prompt;

	line = NULL;
	while (1)
	{
		ft_signl();
		prompt = ft_strdup("> ");
		line = readline(prompt);
		if (line)
		{
			if (!ft_strcmp(line, delim))
				break ;
			else
				write_to_file(line, fd);
			free_string(prompt);
			free_string(line);
		}
		else
			ft_signal(3, g_data);
	}
	free_string(prompt);
	free_string(line);
	close(fd);
}

void	handle_heredoc_file(t_block *block, char *delim, t_data *g_data)
{
	int	pid;

	pipe(g_data->fd_heredoc);
	block->infile = g_data->fd_heredoc[0];
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		close(g_data->fd_heredoc[0]);
		ft_get_heredoc_lines(delim, g_data->fd_heredoc[1], g_data);
		exit(0);
	}
	else
	{
		close(g_data->fd_heredoc[1]);
		waitpid(pid, &g_data->exit_status, 0);
		g_data->exit_status = g_data->exit_status / 256;
	}
}
