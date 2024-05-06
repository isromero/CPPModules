# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 20:36:31 by isromero          #+#    #+#              #
#    Updated: 2024/05/06 21:18:06 by isromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

OBJSDIR = objs

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:%.cpp=${OBJSDIR}/%.o)

# Colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NC = \033[0m # No Color

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)✔ $(NAME) has been created.$(NC)\n"

$(OBJSDIR)/%.o: %.cpp | $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	@if [ -d "$(OBJSDIR)" ]; then \
        $(RM) -r $(OBJSDIR) && \
        printf "$(YELLOW)✔ Objects have been removed.$(NC)\n"; \
    else \
        printf "$(YELLOW)✘ No objects to remove.$(NC)\n"; \
    fi

fclean:
	@if [ -d "$(OBJSDIR)" ] || [ -f "$(NAME)" ]; then \
        $(RM) -r $(OBJSDIR) && \
        $(RM) $(NAME) && \
        printf "$(RED)✔ $(NAME) and objects have been removed.$(NC)\n"; \
    else \
        printf "$(RED)✘ Nothing to clean.$(NC)\n"; \
    fi

re: fclean all
