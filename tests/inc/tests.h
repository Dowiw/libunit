#ifndef TESTS_H
# define TESTS_H

# include "../../framework/inc/libunit.h"

int test_00_ok(void);
int test_01_fail(void);
int test_02_segv(void);
int test_03_bus(void);
int test_04_timeout(void);

#endif
