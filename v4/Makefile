SRC_DIR = ./src/
OBJS_DIR = $(SRC_DIR)objs/

# Colors
RED=\033[1;31m
GREEN=\033[1;32m
CURRENT=\033[1;36m
NC=\033[0m

NAME = get_next_line

FLAGS = -Wall -Wextra -Werror
RM = rm -f


SRC_NAME = 	get_next_line.c\
			get_next_line_utils.c\

OBJS_NAME =	get_next_line.o\
			get_next_line_utils.o\

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))

${NAME}:${OBJS}
	@ar -rcs ${NAME} ${OBJS} $(SRC_DIR)get_next_line.h
#	@gcc -o ${NAME} ${OBJS}
	@echo "\n${GREEN}$(NAME) is ready${NC}"
	@echo "${CURRENT}"
	@echo " ██████╗         ███╗   ██╗        ██╗         ██╗  ██╗██████╗ ██╗ ██████╗███████╗██╗   ██╗██╗  ██╗"
	@echo "██╔════╝         ████╗  ██║        ██║         ██║ ██╔╝██╔══██╗██║██╔════╝╚══███╔╝╚██╗ ██╔╝██║ ██╔╝"
	@echo "██║  ███╗        ██╔██╗ ██║        ██║         █████╔╝ ██████╔╝██║██║       ███╔╝  ╚████╔╝ █████╔╝ "
	@echo "██║   ██║        ██║╚██╗██║        ██║         ██╔═██╗ ██╔══██╗██║██║      ███╔╝    ╚██╔╝  ██╔═██╗ "
	@echo "╚██████╔╝███████╗██║ ╚████║███████╗███████╗    ██║  ██╗██████╔╝██║╚██████╗███████╗   ██║   ██║  ██╗"
	@echo " ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝    ╚═╝  ╚═╝╚═════╝ ╚═╝ ╚═════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝"
	@echo "${NC}"

${OBJS_DIR}%.o:${SRC_DIR}%.c
	@mkdir -p $(OBJS_DIR)
	@echo "${CURRENT}Compiling: \"$<\"${NC}"
	@gcc -c $< -o $@ $(FLAGS)

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\n${RED}Cleaning...${NC}\n"

fclean:		clean
	@rm -f $(NAME)

re:			fclean all                                       