# replace C_FILES with hard coded path i.e. make a bash script
C_FILES = $(wildcard libft/ft_*.c ft_printf_fd/ft_*.c gnl/*bonus.c mylibc/*.c)
O_FILES = $(C_FILES:%.c=build/%.o)
C_FLAGS = -Wall -Werror -Wextra
NAME = libft.a 

.PHONY: all clean fclean re
.DEFAULT: all

all: $(NAME)

$(NAME): $(O_FILES)
	ar -rcs $(NAME) $^

build:
	@mkdir -p build/libft
	@mkdir -p build/ft_printf_fd
	@mkdir -p build/gnl
	@mkdir -p build/mylibc

build/%.o: %.c | build
	cc $(C_FLAGS) -I. -c $< -o $@

clean:
	-rm -f $(O_FILES)
	-rm -f $(B_O_FILES)
	-rm -rf build

fclean: clean
	-rm -f $(NAME)

re: fclean all
