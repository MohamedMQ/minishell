/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:35:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:35:51 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_home(void)
{
	t_env	*cpy;
	int		len;

	len = ft_get_lenkey("HOME=");
	cpy = *get_adress_env();
	while (cpy)
	{
		if (len == ft_get_lenkey(cpy->str)
			&& !ft_strncmp(cpy->str, "HOME", len))
		{
			if (ft_equal(cpy->str))
				return (cpy->str + len + 1);
			return (NULL);
		}
		cpy = cpy->next;
	}
	return (NULL);
}
