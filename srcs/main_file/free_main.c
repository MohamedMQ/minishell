/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:40:29 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:40:30 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exit_free_env_all(t_commande_line **cmd)
{
	printf("exit\n");
	ft_clean_env();
	return (free_all(cmd));
}

int	free_all_env_str_ret_malloc_error(t_commande_line **cmd, char *str)
{
	free(str);
	free_all(cmd);
	ft_clean_env();
	write(2, "malloc error\n", 13);
	return (50);
}

int	free_all_error(t_commande_line **cmd, char *str, int error)
{
	if (error == 40)
		write(2, "pipe fails\n", 11);
	if (error == 50)
		write(2, "malloc error\n", 13);
	free(str);
	ft_clean_env();
	free_all(cmd);
	return (1);
}

void	free_end(t_commande_line **cmd, char *str)
{
	if (str)
		free(str);
	free_all(cmd);
}

int	free_str_all_ret_malloc_error(t_commande_line **cmd, char *str)
{
	free(str);
	free_all(cmd);
	return (50);
}
