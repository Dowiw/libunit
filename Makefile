TEST_DIR ?= tests

all:
	$(MAKE) -C framework
	$(MAKE) -C $(TEST_DIR)

test:
	$(MAKE) -C $(TEST_DIR) test

clean:
	$(MAKE) -C framework clean
	$(MAKE) -C $(TEST_DIR) clean

fclean:
	$(MAKE) -C framework fclean
	$(MAKE) -C $(TEST_DIR) fclean

re: fclean all

.PHONY: all test clean fclean re
