/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:39:48 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/16 23:07:09 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ((size_t)0);
	while (s[i])
		i++;
	return ((size_t)i);
}
