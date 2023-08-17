/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:37:36 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:37:37 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_fd_all_exit_malloc_error(t_commande_line **first)
{
	close_fd_all(first);
	exit (50);
}

void	free_str_fd_exit_malloc_error(char **str, t_commande_line **first)
{
	free(str);
	close_fd_all(first);
	exit (50);
}

void	free_str_exit_fd_error(char **str)
{
	free(str);
	exit(1);
}

void	free_str_fd_all_env_pid_exit(t_commande_line **cmd,
	pid_t *pid, char **str)
{
	free_all(cmd);
	ft_clean_env();
	free(pid);
	free(str);
	exit(1);
}

void	free_file_name(char *file_name)
{
	if (file_name != NULL)
	{
		unlink(file_name);
		free(file_name);
	}
}
