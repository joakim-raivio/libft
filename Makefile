NAME = libft.a

FLAGS = -Wall -Werror -Wextra -I includes

CC = gcc

TEST = test_bin

FUNCTIONS = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr 	   \
			ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat 	   \
			ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr    \
			ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum 	   \
			ft_isascii ft_isprint ft_toupper ft_tolower ft_putchar ft_putstr   \
			ft_memrcpy ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr 	   \
			ft_strsplit ft_cntwords ft_get_delim_str ft_striter ft_striteri	   \
			ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin	   \
			ft_strtrim ft_itoa ft_strrev ft_intlen ft_putendl ft_putchar_fd	   \
			ft_putstr_fd ft_putendl_fd ft_putnbr ft_putnbr_fd ft_lstnew		   \
			ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_memclear  \
			ft_strlcpy ft_iswhitespace

OBJS = $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))

SRCS = $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

all: $(NAME) 

$(NAME):
	@echo "Compiling libft object files\n" 
	@$(CC) $(FLAGS) -c $(SRCS) 
	@echo "Packaging libft\n"
	@ar -rc $(NAME) $(OBJS)

clean:
	@echo "Cleaning libft object files\n"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning libft library\n"
	@rm -f $(NAME)

testclean:
	rm -f $(TEST)

re: fclean all

testlib: fclean
	$(CC) $(FLAGS) -g -c $(SRCS) 
	ar -rc $(NAME) $(OBJS)

testcomp: re testclean
	$(CC) $(FLAGS) test.c -L. -lft -o $(TEST)

testcompdebug: testlib testclean
	$(CC) $(FLAGS) -O0 -g test.c -L. -lft -o $(TEST)

run: testcomp
	./$(TEST)

print: testcomp
	./$(TEST) 1

debug: testcompdebug
	lldb $(TEST)
