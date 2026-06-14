all:
	$(MAKE) -C framework
	$(MAKE) -C tests

test:
	$(MAKE) -C tests test

clean:
	$(MAKE) -C framework clean
	$(MAKE) -C tests clean

fclean:
	$(MAKE) -C framework fclean
	$(MAKE) -C tests fclean

re: fclean all

.PHONY: all test clean fclean re
