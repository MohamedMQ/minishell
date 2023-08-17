/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:37:01 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:37:03 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_env(void)
{
	ft_singletone(NULL, FREE);
}

void	ft_clean_envlist(t_env **env)
{
	t_env	*cpy;
	t_env	*tmp;

	cpy = *env;
	tmp = cpy;
	while (cpy)
	{
		tmp = cpy;
		cpy = cpy->next;
		free(tmp->str);
		free(tmp);
	}
}

void	ft_free_env_elem(t_env *env)
{
	free(env->str);
	free(env);
}
