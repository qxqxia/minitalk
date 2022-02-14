# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 15:09:50 by qxia              #+#    #+#              #
#    Updated: 2022/02/14 15:13:04 by qxia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
SRCS	= utils.c
SRCS_S	= server.c
SRCS_C	= client.c
OBJS	= utils.o
OBJS_S	= server.o
OBJS_C	= client.o
CLIENT	= client
$(NAME)	: $(OBJS) $(OBJS_S) $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_S) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_C) -o $(CLIENT)
all:	$(NAME)
clean:
		rm -rf $(OBJS) $(OBJS_S) $(OBJS_C)
fclean:	clean
		rm -rf $(NAME) $(CLENT)
re:		fclean all
.PHONY:	all clean fclean re
