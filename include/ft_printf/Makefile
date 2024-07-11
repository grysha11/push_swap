# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 19:50:36 by hzakharc          #+#    #+#              #
#    Updated: 2024/07/10 15:54:24 by hzakharc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_printf.c ft_printf_util.c
LIBFTDIR	= 	../libft/

LIBFT		= 	$(LIBFTDIR)libft.a
OBJS		= 	$(SRCS:.c=.o)

CC			= 	cc
RM			= 	rm -f
CCFLAGS		= 	-Wall -Werror -Wextra -I.

NAME		= 	libftprintf.a

all:			$(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFTDIR)
				
$(NAME):		$(LIBFT) $(OBJS)
				ar rcs $(NAME) $(LIBFT) $(OBJS)


clean:
				$(RM) $(OBJS)
				$(MAKE) -C $(LIBFTDIR) clean

fclean:			clean
				$(RM) $(NAME)
				$(MAKE) -C $(LIBFTDIR) fclean

re:				fclean all

.PHONY:			all clean fclean re
