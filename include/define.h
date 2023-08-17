/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:33:49 by mmaqbour          #+#    #+#             */
/*   Updated: 2023/08/13 11:33:51 by mmaqbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

typedef enum quote
{
	NONE,
	SINGLE,
	DOUBLE,
	BACKSLASH,
	END
}	t_quote;

typedef enum mod
{
	GET,
	DELETE,
	FREE,
	ADD
}			t_mod;

typedef enum token
{
	NON,
	ARG,
	BUILTIN,
	OPEN_FILE,
	HERE_DOC,
	LIMITOR,
	CREAT_FILE,
	WRITE_FILE,
	FILE_IN,
	FILE_OUT,
	FILE_OUT_OVER,
	ENDS
}				t_e_token;

#endif