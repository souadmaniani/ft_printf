# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 09:36:56 by smaniani          #+#    #+#              #
#    Updated: 2019/11/11 11:47:46 by smaniani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	create_str.c flag_minus.c flag_prc.c flag_width.c flag_zero.c ft_check_flags.c ft_itoa.c ft_libft.c ft_print_adress.c ft_printf.c ft_putnbr_base_f.c ft_reception_struct.c
OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)
$(NAME) :
		gcc  -Wall -Wextra -Werror -c $(SRC)
		ar rc $(NAME) $(OBJ) 
clean	:
		rm -f *.o
fclean	: clean
		rm -f $(NAME)
re		: fclean
		make all
