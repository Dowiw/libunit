# Libunit

A lightweight, 42-compliant unit testing framework built in C from scratch.

This project implements a test runner that allows you to register test functions dynamically using a linked list. By executing each test inside a forked process (`fork()`), the framework safely catches and reports execution crashes (such as Segmentation Faults and Bus Errors) or infinite loops without bringing down the main test suite.

## Features
- **Crash Resistance:** Tests run in isolated child processes.
- **Signal Handling:** Specifically detects and reports `[SIGSEGV]`, `[SIGBUS]`, and timeouts.
- **Timeout Protection:** Infinite loops are caught using `alarm(3)`.
- **42 Norm Compliant:** Uses custom functions (`ft_putstr`, `ft_putnbr`) instead of standard library calls like `printf`.
- **Colored Output:** Easy-to-read success, failure, and crash indicators.

## Directory Structure
- **`framework/`**: Contains the core logic for the unit testing framework.
  - `load_test.c`: Registers tests into the `t_unit_test` linked list.
  - `launch_tests.c`: Executes the tests and reports results.
  - `libunit_utils.c`: Basic I/O functions.
- **`tests/`**: Contains the test cases and the main test runner program.

## Quick Start

### Compiling
To compile both the framework and the test suite:
```bash
make
```

### Running Tests
To compile and automatically execute the tests:
```bash
make test
```

## How to Write Your Own Tests

1. **Create a Test Function:**
Create a function that returns `0` on success and `-1` on failure.
```c
/* tests/src/my_custom_test.c */
#include "tests.h"

int my_custom_test(void)
{
    int result = my_function_to_test();
    if (result == EXPECTED_VALUE)
        return (0); // Pass
    return (-1);    // Fail
}
```

2. **Add Prototype:**
Add the function prototype to `tests/inc/tests.h`.

3. **Register Test in Main:**
Load the test in your `tests/src/main.c` file using `load_test()`.
```c
int main(void)
{
    t_unit_test *testlist = NULL;

    load_test(&testlist, "My Custom Test", &my_custom_test);
    
    // ... add more tests

    return (launch_tests(&testlist));
}
```

4. **Update Makefile:**
Add your new `.c` file to the `SRCS` variable in `tests/Makefile`.

5. **Run!**
Run `make test` to see your results!
