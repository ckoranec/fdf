NAME = fdf

SRC = srcs/main.c srcs/draw.c srcs/matrix.c srcs/error.c srcs/keys.c srcs/init.c srcs/image.c srcs/reader.c srcs/projecter.c

FLAGS = -Wall -Wextra -Werror

SRC2 = main.o draw.o matrix.o error.o keys.o init.o image.o reader.o projecter.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@make -C ./libft all
	@make -C ./minilibx_macos all
	@cp ./minilibx_macos/libmlx.a ./lib
	@cp ./libft/libft.a ./lib
	gcc  $(FLAGS) -I ./include/  -L./lib  -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

leaks:
	gcc  $(FLAGS) -I ./include/  -L./lib  -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC) -g -fsanitize=address