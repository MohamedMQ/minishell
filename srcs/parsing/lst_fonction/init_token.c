/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:42:16 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:42:18 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token(t_token *new)
{
	new->str = NULL;
	new->type = NON;
	new->expanded = false;
	new->next = NULL;
}

void	init_type(t_token *new)
{
	int	len;

	len = 0;
	if (new->str)
		len = ft_strlen(new->str);
	if (len == 1)
	{
		if (new->str[0] == '<')
			new->type = OPEN_FILE;
		else if (new->str[0] == '>')
			new->type = CREAT_FILE;
	}
	if (len == 2)
	{
		if (new->str[0] == '<' && new->str[1] == '<')
			new->type = HERE_DOC;
		if (new->str[0] == '>' && new->str[1] == '>')
			new->type = WRITE_FILE;
	}
	if (ft_is_builtin(new->str))
		new->type = BUILTIN;
	if (new->type == NON && len != 0)
		new->type = ARG;
}
