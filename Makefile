# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 13:25:52 by hzakharc          #+#    #+#              #
#    Updated: 2024/07/10 17:41:33 by hzakharc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSDIR		=		src
SRCS		=		$(SRCSDIR)/main.c
PRINTFDIR	=		include/ft_printf/

PRINTF		=		$(PRINTFDIR)libftprintf.a
OBJS		=		$(SRCS:.c=.o)

CC			=		cc
RM			=		rm -f
CCFLAGS		=		-Wall -Werror -Wextra

NAME		=		push_swap

all:				$(NAME)

$(PRINTF):			
					$(MAKE) -C $(PRINTFDIR)

$(NAME):			$(PRINTF) $(OBJS)
					$(CC) $(FLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean:
					$(RM) $(OBJS)
					$(MAKE) -C $(PRINTFDIR) clean

fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C $(PRINTFDIR) fclean

re:					fclean all

.PHONY:				all clean fclean re