/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:36:12 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:36:14 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_built_in_env(char **str)
{
	t_env	**env;

	if (*str == NULL)
		return (0);
	env = get_adress_env();
	ft_built_in_show_env(env);
	return (0);
}

int	ft_is_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_built_in_show_env(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (ft_is_equal(cur->str))
			printf("%s\n", cur->str);
		cur = cur->next;
	}
}
