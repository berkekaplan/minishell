/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:49:34 by mkaplan           #+#    #+#             */
/*   Updated: 2023/11/21 18:49:34 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_env	*ft_new_list(void)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->front = NULL;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

int	ft_index_of_equal_sign(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter))
	{
		if (*(str + counter) == '=')
			return (counter);
		counter++;
	}
	return (-1);
}

void	ft_add_tail(t_env *new, t_env **head)
{
	t_env	*temp;

	temp = *head;
	if (!(*head))
	{
		*head = new;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_fill_env(char **env, t_data	*g_data)
{
	t_env	*temp;
	int		len;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		temp = ft_new_list();
		if (!temp)
			return ;
		flag = ft_index_of_equal_sign(env[i]);
		if (flag == -1)
			ft_exit("Error: no equal sign in env variable.\n", 0, g_data);
		temp->front = ft_substr(env[i], 0, flag);
		temp->back = ft_substr(env[i], flag + 1, len);
		ft_add_tail(temp, &g_data->environmental);
		i++;
	}
}
