NAME	=	libft.a

FLAG	=	-Wall -Wextra -Werror

FILES	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_striteri.c ft_printf.c ft_puthex.c ft_putnbr_unsigned.c \
			ft_putnbr.c ft_putstr.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c get_next_line.c #main_libft.c

#BONUS_FILES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
#				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
#				ft_lstmap.c

OBJ			=	$(FILES:.c=.o)
#BONUS_OBJ	=	$(OBJ) $(BONUS_FILES:.c=.o)
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

#bonus:		$(BONUS_OBJ)
#	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
#	cc $(FLAG) *.o

%.o:%.c
	cc $(FLAG) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re #bonus