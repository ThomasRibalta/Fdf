NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f
FRAMEDIR = ./mlx
FRAMEWORK = -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz
SRC = main.c readfile.c draw.c utils/ft_atoi.c utils/ft_strcmp.c utils/ft_putstr_fd.c utils/utils2.c utils/ft_split.c utils/utils.c utils/get_next_line/get_next_line.c utils/get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

.c.o: 
	$(CC) $(FLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(FRAMEWORK) -o $(NAME)

all:
	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
