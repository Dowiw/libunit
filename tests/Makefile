NAME = test_bin
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -I../framework/inc

SRC_DIR = src
OBJ_DIR = obj

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/test_00_ok.c \
		$(SRC_DIR)/test_01_fail.c \
		$(SRC_DIR)/test_02_segv.c \
		$(SRC_DIR)/test_03_bus.c \
		$(SRC_DIR)/test_04_timeout.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBUNIT = ../framework/libunit.a

all: $(NAME)

$(NAME): $(LIBUNIT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L../framework -lunit -o $(NAME)

$(LIBUNIT):
	$(MAKE) -C ../framework

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
