NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = 	src/main.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
MLX =./minilibx/libmlx.a
LIBS = -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(MLX):
	@$(MAKE) -C minilibx

clean:
	@$(MAKE) -C minilibx clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
