NAME = libftprintf.a

HEAD = ft_printf.h

SRC = ft_hex.c \
		ft_itoa.c \
		ft_printf.c \
		ft_switch.c \
		ft_utoa.c \

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

CC = gcc $(CFLAGS) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(SRC)
	@$(LIB) $(OBJ)
	@$(RANLIB)
	@echo "[INFO] Library [$(NAME)] created"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@echo "[INFO] Removed objects"

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "[INFO] Library and objects removed "

re: fclean all

.PHONY: all clean fclean re
