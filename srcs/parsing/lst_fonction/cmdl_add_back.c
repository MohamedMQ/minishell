/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdl_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:42:12 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:42:13 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmdl_add_back(t_commande_line **first, t_commande_line *add_back)
{
	t_commande_line	*cur;

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
