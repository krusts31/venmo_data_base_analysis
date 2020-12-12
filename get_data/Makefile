# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/12 09:51:49 by mraasvel      #+#    #+#                  #
#    Updated: 2020/12/12 11:27:26 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# compilation
CC = gcc
IFLAGS = -I $(IDIR)
# CFLAGS = -Wall -Werror -Wextra
# DFLAGS = -O0 -g -fsanitize=address
FASTFLAGS = -O3
LIBFLAG = -L$(LIBDIR) -lft

# DIRS
OBJDIR = obj
SRCDIR = src
IDIR = include
LIBDIR = libft

all: $(NAME)
.PHONY: all re clean fclean

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(DFLAGS) $(LIBFLAG)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c -o $@ $(CFLAGS) $< $(IFLAGS)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(NAME)
re: fclean all
