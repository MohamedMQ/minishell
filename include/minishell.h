/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:34:35 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 13:28:16 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../srcs/libft/includes/libft.h"
# include <stdbool.h>
# include "parsing.h"
# include "exec.h"
# include "builtin.h"
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# define NC	"\033[0m"
# define GREEN "\033[1;32m"

void	signal_cmd(int sig);
int		print_exit_free_env_all(t_commande_line **cmd);

int		free_all_env_str_ret_malloc_error(t_commande_line **cmd, char *str);

int		free_all_error(t_commande_line **cmd, char *str, int error);

void	free_end(t_commande_line **cmd, char *str);

void	free_token(t_commande_line **cmd_line);
int		free_str_all_ret_malloc_error(t_commande_line **cmd, char *str);
void	error_str(void);
int		free_all(t_commande_line **cmd_line);
char	*ft_get_pwd(void);
void	welcome_msg(void);
#endif
