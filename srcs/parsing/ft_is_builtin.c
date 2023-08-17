/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:42:42 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:42:43 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strcmp("exit", str))
		return (2);
	if (ft_strcmp("cd", str))
		return (1);
	else if (ft_strcmp("echo", str))
		return (1);
	else if (ft_strcmp("env", str))
		return (1);
	else if (ft_strcmp("pwd", str))
		return (1);
	else if (ft_strcmp("export", str))
		return (1);
	else if (ft_strcmp("unset", str))
		return (1);
	return (0);
}
