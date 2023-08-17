/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_will_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:41:58 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:41:59 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*word_will_single(char *str, int *i, char *s1)
{
	char	*s2;
	char	*s3;
	int		j;

	s2 = NULL;
	s3 = NULL;
	j = *i;
	while (str && str[(*i)] && str[(*i)] != '\'')
		(*i)++;
	s2 = malloc(sizeof(char) * ((*i) - j + 1));
	if (s2 == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	s2 = ft_strncpy(s2, str + j, (*i) - j);
	s3 = ft_strjoin(s1, s2);
	free_both(s1, s2);
	return (s3);
}
