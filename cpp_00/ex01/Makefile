# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 12:42:43 by isromero          #+#    #+#              #
#    Updated: 2023/09/05 12:42:43 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PhoneBook.cpp
OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

all : $(NAME)

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
