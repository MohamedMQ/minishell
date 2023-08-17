/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_word_utils_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:41:31 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 18:11:50 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	edit_type_2(t_commande_line **block)
{
	t_commande_line	*cur_g;
	t_token			*cur_s;

	cur_g = *block;
	while (cur_g)
	{
		cur_s = cur_g->first_token;
		while (cur_s)
		{
			if (!ft_strncmp(cur_s->str, ">>>", 3)
				|| !ft_strncmp(cur_s->str, "<<<", 3))
			{
				write(2, "minishell: syntax error near unexpected token\
 `newline'\n",
					ft_strlen("minishell: syntax error near unexpected token\
 `newline'\n"));
				g_exit_status = 258;
				return (12);
			}
			cur_s = cur_s->next;
		}
		cur_g = cur_g->next;
	}
	return (0);
}

int	ret_error_file_without_file(t_commande_line *cur_b)
{
	write(2, "minishell: syntax error near unexpected token",
		ft_strlen("minishell: syntax error near unexpected token"));
	if (cur_b)
		write(2, " `|'\n", 5);
	else
		write(2, " `newline'\n", 11);
	g_exit_status = 258;
	return (12);
}

t_e_token	change_type_file(t_e_token type, int *file)
{
	*file = 0;
	if (type == OPEN_FILE)
		return (FILE_IN);
	else if (type == CREAT_FILE)
		return (FILE_OUT);
	else if (type == WRITE_FILE)
		return (FILE_OUT_OVER);
	else if (type == HERE_DOC)
		return (LIMITOR);
	return (NON);
}
