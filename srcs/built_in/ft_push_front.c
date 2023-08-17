/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:37:19 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:37:21 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_push_front(char *env, t_env **begin_lst, int declare)
{
	t_env	*env_new;

	env_new = malloc(sizeof(t_env));
	if (env_new == NULL)
		return (50);
	env_new->str = ft_final_add(env);
	env_new->declare = declare;
	if (env_new->str == NULL)
		return (50);
	env_new->next = *begin_lst;
	*begin_lst = env_new;
	return (0);
}
