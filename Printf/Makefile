NAME	=	libftprintf.a

FLAG	=	-Wall -Wextra -Werror

FILES	=	

#BONUS_FILES	= 

OBJ			=	$(FILES:.c=.o)
#BONUS_OBJ	=	$(OBJ) $(BONUS_FILES:.c=.o)
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)
	cc $(FLAG) *.o

#bonus:		$(BONUS_OBJ)
#	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
#	cc $(FLAG) *.o

%.o:%.c
	cc $(FLAG) -o $@ -c $<

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re, #bonus