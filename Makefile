LIBFT		:= 	libft/libft.a
PUSH_SWAP	:= 	push_swap
CHECKER		:= 	checker
CC 			:= 	gcc
CFLAGS		:= 	-Wall -Werror -Wextra

SRC_PS 		:= 	push_swap.c
SRC_CK		:= 	checker.c
SRCS 		:= 	handle_atoi.c handle_error.c operations.c \
				parse_args.c push_sort_a.c push_sort_b.c \
				sort.c stack_utils.c

OBJS 		:= $(SRCS:.c=.o)
AR 			:= ar rc
RM 			:= rm -f

.PHONY: all clean fclean re

all: $(PUSH_SWAP)

$(PUSH_SWAP):
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(SRC_PS) $(SRCS) $(LIBFT) 
#	$(CC) $(CFLAGS) -o $(FILE_CK) $(SRC_CK) $(NAME) $(LIBFT) 
#	make clean

$(CHECKER):
	echo to do checker

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(FILE_PS) $(FILE_CK)

re: fclean all