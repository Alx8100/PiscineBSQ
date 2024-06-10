# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nipollin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 11:33:03 by nipollin          #+#    #+#              #
#    Updated: 2024/06/06 21:46:10 by nipollin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = src
OBJDIR = build
INCDIR = include
LIBDIR = lib

# Source
SOURCES = 			\
	ft_strjoin.c	\
	helper.c		\
	init.c			\
	input.c			\
	main.c			\
	max_square.c	\
	memory.c		\
	print.c			\
	solver.c		\

# Target
TARGET = bsq

SRC = $(addprefix	$(SRCDIR)/, $(SOURCES))
INC = $(addprefix	-I, $(INCDIR))
OBJ = $(patsubst	$(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
