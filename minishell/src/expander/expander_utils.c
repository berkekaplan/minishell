/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaplan     <student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:46:33 by mkaplan           #+#    #+#             */
/*   Updated: 2023/12/04 17:42:26 by mkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_expand	*ft_add_tail_expander(t_expand *head, char *str)
{
	t_expand	*temp;
	t_expand	*new;

	temp = NULL;
	new = NULL;
	temp = head;
	new = (t_expand *)malloc(sizeof(t_expand));
	new->str = ft_strdup(str);
	if (new->str == NULL)
		return (NULL);
	new->next = NULL;
	if (!(head))
		head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (head);
}

int	ft_ultimate_check(const char *s1, const char *s2)
{
	int	j;
	int	i;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			i++;
			j++;
			if (!s2[j])
			{
				if (!ft_isalnum(s1[i]))
					return (1);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_search_env(char *splitted_input, t_data *g_data)
{
	char	*str;
	char	*after;
	t_env	*tmp;

	str = NULL;
	tmp = NULL;
	tmp = g_data->environmental;
	if (!splitted_input || *splitted_input == '\0')
		return (NULL);
	while (tmp)
	{
		if (ft_ultimate_check(splitted_input, tmp->front))
		{
			after = after_dollar(tmp->front, splitted_input);
			str = ft_strdup(tmp->back);
			str = ft_strjoin(str, after, \
			ft_strlen(tmp->back) + ft_strlen(after));
			free_string(after);
			return (str);
		}
		tmp = tmp->next;
	}
	return (str);
}

int	i_x(char c, char x)
{
	return ((c == '$' && (ft_isalnum(x) || x == '?')));
}

int	is_in_single_quote(char *str, int indx)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (i < indx)
	{
		if (str[i] == '\'')
			flag++;
		i++;
	}
	if (flag && flag % 2 == 0)
		return (0);
	else if (ft_strchr(str + indx + 1, '\'') != 0)
		return (1);
	return (0);
}
