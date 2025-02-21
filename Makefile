# LIBFT
SOURCES     = ft_strndup.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_atol.c ft_isascii.c ft_isprint.c ft_strlen.c ft_strstr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_atof.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
B_SOURCES   = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstadd_front_bonus.c
OBJECTS     = ${SOURCES:.c=.o} ${B_SOURCES:.c=.o}
NAME        = libft.a
CC          = cc
FLAGS       = -Wall -Werror -Wextra
GREEN   = \033[92m
BLUE    = \033[94m
ORANGE  = \033[93m
RED     = \033[91m
BOLD            = \033[1m
WHITE   = \033[0m
count				= 0

all: ft_printf ft_printf_compile ${NAME}

ft_printf:
	@if [ ! -d "ft_printf/" ]; then \
		(git clone git@github.com:LAPORTENicolas/ft_printf.git ft_printf) > /dev/null 2>&1; \
	fi
	@cd ft_printf && git pull > /dev/null 2>&1

ft_printf_compile:
	@${MAKE} -s -C ft_printf/
	@printf "\n"

${NAME}: ${OBJECTS}
	@ar crs ${NAME} ${OBJECTS} ft_printf/*.o
	@printf "\n${GREEN}✅ Compilation ${BOLD}${NAME}${WHITE}${GREEN} Termine !\n"; \

%.o: %.c
	@${CC} ${FLAGS} -c $< -o $@
	@$(eval count=$(shell echo $$(($(count)+1))))  # Incrémenter le compteur
	@if ((${count} % 2 == 0)); then \
		printf "${BLUE}\r⌛ Compilation ${BOLD}$< ${WHITE}${BLUE}to ${BOLD}$@${WHITE}${BLUE}"; \
	else \
		printf "${BLUE}\r⏳ Compilation ${BOLD}$< ${WHITE}${BLUE}to ${BOLD}$@${WHITE}${BLUE}"; \
	fi

clean:
	@rm -rf ${OBJECTS}
	@if [ -d "ft_printf/" ]; then \
		${MAKE} -s -C ft_printf/ clean; \
	fi
	@printf "${ORANGE}🗑️ Clean ${BOLD}${OBJECTS}\n${WHITE}"; \

fclean: clean
	@rm -rf ${NAME}
	@if [ -d "ft_printf/" ]; then \
		${MAKE} -s -C ft_printf/ fclean; \
	fi
	@printf "${RED}🗑️ Clean ${BOLD}${NAME}\n${WHITE}"; \

reset: fclean
	@rm -rf ft_printf

re: fclean all

.PHONY: all clean fclean re
