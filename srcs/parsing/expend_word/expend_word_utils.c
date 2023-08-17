/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expend_word_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:41:36 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 18:15:58 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*init_str(char **str, char *duplica, int *cur, char **s1)
{
	*s1 = NULL;
	*cur = 0;
	*str = ft_strdup(duplica);
	free(duplica);
	if (*str == NULL)
		return (NULL);
	return (*str);
}

int	end_modif_two(char *str, t_token **stc, char *s1)
{
	free(str);
	(*stc)->str = s1;
	return (0);
}

int	is_type_file(t_e_token type)
{
	if (type == CREAT_FILE || type == WRITE_FILE
		|| type == OPEN_FILE || type == HERE_DOC)
		return (1);
	return (0);
}

int	ret_file_without_obj(t_e_token type)
{
	write(2, "minishell: syntax error near unexpected token",
		ft_strlen("minishell: syntax error near unexpected token"));
	if (type == NON)
		write(2, " `newline'\n", 9);
	if (type == CREAT_FILE)
		write(2, " `>'\n", 5);
	else if (type == WRITE_FILE)
		write(2, " `>>'\n", 6);
	else if (type == OPEN_FILE)
		write(2, " `<'\n", 5);
	else if (type == HERE_DOC)
		write(2, " `<<'\n", 6);
	g_exit_status = 258;
	return (12);
}

t_e_token	cp_type_change_file(t_e_token type, int *file)
{
	*file = 1;
	return (type);
}
