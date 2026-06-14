#ifndef LIBUNIT_ASSERT_H
# define LIBUNIT_ASSERT_H

# define UNIT_ASSERT(cond) if (!(cond)) return (-1)
# define UNIT_ASSERT_EQ(a, b) if ((a) != (b)) return (-1)
# define UNIT_ASSERT_NEQ(a, b) if ((a) == (b)) return (-1)

#endif
