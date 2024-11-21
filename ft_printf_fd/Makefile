C_FILES = ./ft_libft_utils.c ./ft_printf_fd_Uhex.c ./ft_printf_fd_char.c ./ft_printf_fd_conversion_utils.c ./ft_printf_fd_conversion_utils1.c ./ft_printf_fd_hex_utils.c ./ft_printf_fd_integer.c ./ft_printf_fd_integer_utils.c ./ft_printf_fd_lexer.c ./ft_printf_fd_lexer_1.c ./ft_printf_fd_lexer_utils.c ./ft_printf_fd_lexer_utils2.c ./ft_printf_fd_pointer.c ./ft_printf_fd_string.c ./ft_printf_fd_u_integer.c ./ft_printf_fd_u_integer_utils.c ./ft_printf_fd_lhex.c ./ft_printf_fd.c
O_FILES = $(C_FILES:%.c=build/%.o)
B_C_FILES = $(C_FILES)
B_O_FILES = $(B_C_FILES:%.c=build/%.o)
C_FLAGS = -Wall -Werror -Wextra -O2
NAME = libftprintf_fd.a 

.PHONY: all clean fclean re
.DEFAULT: all

all: $(NAME)

$(NAME): $(O_FILES)
	ar -rcs $(NAME) $^ 

build:
	@mkdir -p build

build/%.o: %.c | build
	cc $(C_FLAGS) -c $< -o $@

clean:
	-rm -f $(O_FILES)
	-rm -f $(B_O_FILES)
	-rm -rf build

fclean: clean
	-rm -f $(NAME)
	-rm -f libft.so
	-rm -f *.out

re: fclean all

bonus: fclean all
