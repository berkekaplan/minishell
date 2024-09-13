/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:45:04 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:45:05 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <string.h>
#include "libft.h"

static char	*ft_getenv(char *str, t_data	*g_data)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
			return (env->back);
		env = env->next;
	}
	return (NULL);
}

static int	get_cd_path(t_block *cmd, char **path, t_data *g_data)
{
	if (cmd->args[1] == NULL || ft_strcmp(cmd->args[1], "~") == 0)
	{
		*path = ft_getenv("HOME", g_data);
		if (*path == NULL)
			return (0);
	}
	else
		*path = cmd->args[1];
	return (1);
}

int	ft_cd(t_block *cmd, t_data *g_data)
{
	char	*path;

	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (-1);
	}
	if (get_cd_path(cmd, &path, g_data) == 0)
		return (0);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
