/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:38:10 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:38:11 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_tabtab(t_env **envp)
{
	char	**new;
	t_env	*cur;
	int		i;

	i = 0;
	cur = *envp;
	while (cur)
	{
		cur = cur->next;
		i++;
	}
	new = malloc(sizeof(char *) * (i + 1));
	new[i] = NULL;
	cur = *envp;
	i = 0;
	while (cur)
	{
		new[i] = cur->str;
		i++;
		cur = cur->next;
	}
	return (new);
}
