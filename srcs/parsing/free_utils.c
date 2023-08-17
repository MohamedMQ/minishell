/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:42:34 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 13:15:04 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_cmdl_ret_malloc_error(t_commande_line *stc)
{
	if (stc)
		free(stc);
	return (50);
}

int	free_token_ret_malloc_error(t_token *tok)
{
	if (tok)
		free(tok);
	return (50);
}

char	*free_str_ret_null(char *s1)
{
	if (s1)
		free(s1);
	return (NULL);
}

void	free_both(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return ;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			if (split[i])
				free(split[i]);
			i++;
		}
	}
	if (split)
		free(split);
}
