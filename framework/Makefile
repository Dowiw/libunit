NAME = libunit.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc

SRC_DIR = src
OBJ_DIR = obj

SRCS =	$(SRC_DIR)/libunit_utils.c \
		$(SRC_DIR)/load_test.c \
		$(SRC_DIR)/launch_tests.c \
		$(SRC_DIR)/libunit_assert.c \
		$(SRC_DIR)/libunit_capture.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
