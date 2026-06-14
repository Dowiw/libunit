#ifndef LIBUNIT_ASSERT_H
# define LIBUNIT_ASSERT_H

void unit_print_error(const char *file, int line, const char *cond);

# define UNIT_ASSERT(cond) if (!(cond)) { unit_print_error(__FILE__, __LINE__, #cond); return (-1); }
# define UNIT_ASSERT_EQ(a, b) if ((a) != (b)) { unit_print_error(__FILE__, __LINE__, #a " == " #b); return (-1); }
# define UNIT_ASSERT_NEQ(a, b) if ((a) == (b)) { unit_print_error(__FILE__, __LINE__, #a " != " #b); return (-1); }

# ifndef UNIT_EPSILON
#  define UNIT_EPSILON 0.00001
# endif

# define UNIT_ASSERT_FEQ(a, b) if (!(((a) - (b) < UNIT_EPSILON) && ((b) - (a) < UNIT_EPSILON))) { unit_print_error(__FILE__, __LINE__, #a " ~= " #b); return (-1); }

#endif
