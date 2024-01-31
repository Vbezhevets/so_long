NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LINKS		=  -lXext -lX11 -lmlx

LIBDIR	= ./libft
LIBFT	= ${LIBDIR}/libft.a

SRCS        :=      mlx_.c main.c play.c map.c imape.c errors_and_frees.c flood_check.c
OBJS        := $(SRCS:.c=.o)

%.o : %.c
	${CC} ${CFLAGS} -o $@ -c $< -I${LIBDIR}

${NAME}	: ${LIBFT} ${OBJS}
		${CC} ${LINKS} -o $@ ${OBJS} -L . ./libft/libft.a

${LIBFT}:
		make -C $(LIBDIR) all

all		: ${NAME}

bonus	: all

clean	:
		make -C ${LIBDIR} clean
		rm -f ${OBJS} ${OBJS_B}

fclean	: clean
		make -C ${LIBDIR} fclean
		rm -f ${NAME}

re		: fclean all

.PHONY: all, clean, fclean, bonus, re
