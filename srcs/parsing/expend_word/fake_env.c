/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:41:45 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:41:46 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_fake_env(char *str)
{
	int		i;
	char	*cpy;

	i = len_fake_env(str);
	cpy = malloc(sizeof(char) * (i + 1));
	if (cpy == NULL)
		return (NULL);
	cpy = ft_strncpy(cpy, str, i);
	return (cpy);
}

char	*fake_env(int *j, int len_str)
{
	char	*new;

	new = NULL;
	*j = *j + len_str + 1;
	new = malloc(sizeof(char));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}

int	len_fake_env(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i++;
	while (str && str[i] && str[i] != '$')
	{
		if (str[i] && (ft_is_alpha_num(str[i]) == 1) && str[i] != '_')
			return (i + 1);
		i++;
	}
	if (i == 1)
		return (i + 1);
	return (i);
}
