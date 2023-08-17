# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 11:42:59 by mmaqbour          #+#    #+#              #
#    Updated: 2023/08/16 12:33:18 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC			= \033[0m
GREEN		= \033[1;32m
RED			= \033[1;31m

NAME =		minishell

LIBFT =		srcs/libft

CC =		gcc

FLAGS =		-Wall -Wextra -Werror -g

LIB	 =		-L/Users/mmaqbour/.brew/opt/readline/lib -lreadline

INC	= 		-I/Users/mmaqbour/.brew/opt/readline/include

HEADERS =	include/builtin.h include/define.h include/exec.h \
			include/minishell.h include/parsing.h include/struct.h

SRCS =  	srcs/main_file/main.c \
			srcs/main_file/free_main.c \
			srcs/main_file/free_end_stc.c \
			srcs/main_file/change_shell_lvl.c \
			srcs/parsing/ft_is_builtin.c \
			srcs/parsing/creat_fill_lst/get_cmd_line.c \
			srcs/parsing/lst_fonction/cmdl_add_back.c \
			srcs/parsing/lst_fonction/len_cmd.c	\
			srcs/parsing/parsing_utils.c \
			srcs/parsing/free_utils.c \
			srcs/parsing/free_utils_2.c \
			srcs/parsing/creat_fill_lst/split_arg.c \
			srcs/parsing/lst_fonction/init_token.c \
			srcs/parsing/expend_word/expend_word.c \
			srcs/parsing/expend_word/expend_word_utils.c \
			srcs/parsing/expend_word/expend_word_utils_two.c \
			srcs/parsing/expend_word/devellope_limitor.c \
			srcs/parsing/expend_word/word_will_single.c \
			srcs/parsing/expend_word/word_will_double.c \
			srcs/parsing/expend_word/word_will_unquote.c \
			srcs/parsing/get_env.c \
			srcs/parsing/expend_word/fake_env.c \
			srcs/parsing/expend_word/word_unquote_inter.c \
			srcs/parsing/creat_fill_lst/organise_arg.c \
			srcs/parsing/lst_fonction/token_add_back.c \
			srcs/exec/ft_exec.c \
			srcs/exec/ft_exist.c \
			srcs/exec/ft_lst_to_str.c \
			srcs/exec/pipe.c \
			srcs/exec/open_fd.c \
			srcs/exec/utils.c \
			srcs/exec/exec_free_utils.c \
			srcs/exec/exec_free_utils_two.c \
			srcs/exec/exec_utils.c \
			srcs/built_in/ft_add_value.c \
			srcs/built_in/ft_built_in_export_fd.c \
			srcs/built_in/ft_get_value.c \
			srcs/built_in/ft_env_singletone.c \
			srcs/built_in/ft_built_in.c \
			srcs/built_in/ft_built_in_env_fd.c \
			srcs/built_in/ft_built_in_echo.c \
			srcs/built_in/ft_free_env.c \
			srcs/built_in/ft_built_in_export.c \
			srcs/built_in/ft_built_in_pwd.c \
			srcs/built_in/ft_built_in_unset.c \
			srcs/built_in/ft_built_in_cd.c \
			srcs/built_in/ft_built_in_cd_helper.c \
			srcs/built_in/ft_built_in_env.c \
			srcs/built_in/ft_init_env.c \
			srcs/built_in/ft_delete_key.c \
			srcs/built_in/ft_gestion_error.c \
			srcs/built_in/ft_built_in_pwd_fd.c \
			srcs/built_in/ft_push_front.c \
			srcs/built_in/ft_built_in_echo_fd.c \
			srcs/built_in/builin_free.c \
			srcs/limitor/creat_file.c \
			srcs/limitor/open_heredoc.c

OBJ 		= ${SRCS:.c=.o}


all :
	@make -C $(LIBFT) --no-print-directory
	@make $(NAME) --no-print-directory

$(NAME)	: $(OBJ)
	@$(CC) $(FLAGS) -I srcs/libft/includes/ -I include/. $(OBJ) srcs/libft/libft.a -o $(NAME) $(LIB)
	@echo "${GREEN} ##### minishell Ready! ##### ${NC}"

%.o: %.c $(HEADERS)
	${CC} ${FLAGS} -c $< -o $@ -I include/ $(INC)

clean :
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ)
	@echo "${GREEN} ##### minishell Clean Objects ##### ${NC}"

fclean : clean
	@rm -rf libft.a
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME)
	@echo "${GREEN} ##### minishell Removed ##### ${NC}"

re : fclean all
