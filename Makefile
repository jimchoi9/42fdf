CC = gcc
CFLAG = -fsanitize=address -Wall -Wextra -Werror
NAME = test1
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
SRCS = test.c parsing.c bresenham.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

MLXDIR = ./minilibx_mms_20210621
MLXFLAG = -L $(MLXDIR) -lmlx -L $(LIBFT_DIR)  -lft -framework OpenGL -framework AppKit
LIBMLXDIR = /Users/jimchoi/Desktop/sub/42fdf/minilibx_mms_20210621
.PHONY: all
all: $(NAME)


$(NAME): $(OBJS)

	make -s -C $(MLXDIR)
	cp ./$(MLXDIR)/libmlx.dylib ./libmlx.dylib
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAG) $(OBJS) $(MLXFLAG) -o $(NAME)


# $(LIBFT_DIR)$(LIBFT_NAME):
# 	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLXDIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
