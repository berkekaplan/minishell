/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:46:15 by mkaplan           #+#    #+#             */
/*   Updated: 2023/12/01 20:38:14 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	ft_pipe_process(t_block *block, t_data *g_data, int indx)
{
	if (block->outfile > 1)
		close(block->outfile);
	if (block->infile > 0)
		close(block->infile);
	if (indx == 0)
	{
		close(g_data->fd_pipe[indx][0]);
		close(g_data->fd_pipe[indx][1]);
	}
	if (indx == g_data->block_cnt - 1)
	{
		close(g_data->fd_pipe[indx][0]);
		close(g_data->fd_pipe[indx][1]);
	}
	if (indx > 0 && indx < g_data->block_cnt - 1)
	{
		close(g_data->fd_pipe[indx - 1][1]);
		close(g_data->fd_pipe[indx][0]);
	}
}
