# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 11:38:49 by mmaqbour          #+#    #+#              #
#    Updated: 2023/08/16 23:09:44 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = *.c 

OBJ = *.o

HEAD = ./includes

all : $(NAME)

$(NAME):
	@echo "Compiling libft.."
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEAD) && ar rc $(NAME) $(OBJ)
	@echo "libft Done !"

clean:
	@echo "Remove libft *.o  ..."
	@/bin/rm -f $(OBJ)
	@echo "Done !"

fclean: clean
	@echo "Remove lib ..."
	@/bin/rm -f $(NAME)
	@echo "Done !" 

re: fclean all
