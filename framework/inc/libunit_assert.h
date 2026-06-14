#ifndef LIBUNIT_ASSERT_H
# define LIBUNIT_ASSERT_H

# define UNIT_ASSERT(cond) if (!(cond)) return (-1)
# define UNIT_ASSERT_EQ(a, b) if ((a) != (b)) return (-1)
# define UNIT_ASSERT_NEQ(a, b) if ((a) == (b)) return (-1)

# ifndef UNIT_EPSILON
#  define UNIT_EPSILON 0.00001f
# endif

# define UNIT_ASSERT_FEQ(a, b) UNIT_ASSERT(((a) - (b) < UNIT_EPSILON) && ((b) - (a) < UNIT_EPSILON))

#endif
