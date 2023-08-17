/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:41:17 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:41:18 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_arg(t_commande_line *cmd)
{
	t_token	*cur_t;
	int		i;

	cur_t = cmd->first_token;
	i = 0;
	while (cur_t)
	{
		if (cur_t->type == ARG || cur_t->type == BUILTIN)
		{
			cmd->argv[i] = cur_t->str;
			i++;
		}
		cur_t = cur_t->next;
	}
	cmd->argv[i] = NULL;
}

static int	nbr_arg_cmd(t_commande_line *cmd)
{
	t_token	*cur_t;
	int		len;

	len = 0;
	cur_t = cmd->first_token;
	while (cur_t)
	{
		if (cur_t->type == ARG || cur_t->type == BUILTIN)
			len++;
		cur_t = cur_t->next;
	}
	return (len);
}

int	organise_arg(t_commande_line **cmd)
{
	t_commande_line	*cur_b;
	int				len_arg;
	char			**new;

	cur_b = *cmd;
	while (cur_b)
	{
		len_arg = nbr_arg_cmd(cur_b);
		new = malloc(sizeof(char *) * (len_arg + 1));
		if (new == NULL)
			return (50);
		cur_b->argv = new;
		init_arg(cur_b);
		cur_b = cur_b->next;
	}
	return (0);
}
