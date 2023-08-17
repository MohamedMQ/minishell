/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:42:26 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:42:27 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_add_back(t_token **first, t_token *add_back)
{
	t_token	*cur;

	cur = *first;
	if (cur == NULL)
		*first = add_back;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = add_back;
	}
}
