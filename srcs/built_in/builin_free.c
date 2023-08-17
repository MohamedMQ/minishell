/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builin_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:35:36 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:35:37 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_in_builin(t_commande_line **first, pid_t *pid, int ret)
{
	free(pid);
	free_all(first);
	ft_clean_env();
	exit (ret);
	return (ret);
}
