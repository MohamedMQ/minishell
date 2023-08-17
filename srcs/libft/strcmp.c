/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:39:26 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 23:07:01 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(char *str, char *in)
{
	int	len_str;
	int	len_in;
	int	i;

	i = 0;
	len_str = 0;
	len_in = 0;
	len_str = ft_strlen(str);
	len_in = ft_strlen(in);
	if (len_str != len_in)
		return (0);
	while (i < len_in)
	{
		if (str[i] != in[i])
			return (0);
		i++;
	}
	return (1);
}
