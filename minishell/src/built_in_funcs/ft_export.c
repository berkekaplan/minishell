/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:45:37 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:45:38 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	**ft_sort_env(char **tmp_env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tmp_env[i])
	{
		j = i + 1;
		while (tmp_env[j])
		{
			if (ft_strcmp(tmp_env[i], tmp_env[j]) > 0)
			{
				tmp = tmp_env[i];
				tmp_env[i] = tmp_env[j];
				tmp_env[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tmp_env);
}

static int	ft_matrix_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**ft_copy_env(t_data *g_data)
{
	char	**env;
	char	**new;
	int		i;
	int		len;

	i = -1;
	len = ft_matrix_size(g_data->env);
	env = g_data->env;
	new = (char **)malloc(sizeof(char *) * (len + 1));
	while (env[++i])
		new[i] = ft_strdup(env[i]);
	new[i] = NULL;
	return (new);
}

static void	ft_only_export(t_data *g_data)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_copy_env(g_data);
	if (tmp == NULL)
		return ;
	tmp = ft_sort_env(tmp);
	while (tmp[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp[i], 1);
		ft_putstr_fd("\n", 1);
	}
	free_matrix(tmp);
}

int	ft_export(t_block *cmd, t_data	*g_data)
{
	char	**splitted_input;
	char	*tmp;

	if (cmd->args[1] == NULL)
	{
		ft_only_export(g_data);
		return (0);
	}
	tmp = ft_strstr(cmd->args[1], "=");
	if (!tmp)
		return (0);
	if (!tmp || *tmp == cmd->args[1][0] || ft_strcmp(cmd->args[1], "=") == 0)
	{
		ft_error('e', cmd);
		return (-1);
	}
	splitted_input = ft_split(cmd->args[1], '=');
	if (ft_is_valid_env(splitted_input[0], g_data))
		ft_change_env(splitted_input[0], splitted_input[1], g_data);
	else
		ft_new_env(cmd->args[1], g_data);
	free_matrix(splitted_input);
	free_matrix(g_data->env);
	g_data->env = ft_env_to_matrix(g_data);
	return (0);
}
