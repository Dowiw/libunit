# Libunit

A lightweight, 42-compliant unit testing framework built in C from scratch.

This project implements a test runner that allows you to register test functions dynamically into Test Suites. By executing each test inside a forked process (`fork()`), the framework safely catches and reports execution crashes (such as Segmentation Faults and Bus Errors) or infinite loops without bringing down the main test suite.

## Features
- **Crash Resistance:** Tests run in isolated child processes.
- **Signal Handling:** Specifically detects and reports `[SIGSEGV]`, `[SIGBUS]`, and timeouts.
- **Timeout Protection:** Infinite loops are caught using `alarm(3)`.
- **42 Norm Compliant:** Uses custom functions instead of standard library calls like `printf`.
- **Assertion Macros:** Clean testing syntax using `UNIT_ASSERT_EQ` and others.
- **Stdout Capturing:** Test functions that print to standard output using `capture_stdout_start()`.
- **Test Suites:** Group tests logically under categorized headers.
- **Setup & Teardown Hooks:** Automatically run initialization and cleanup code around your test suites.

## Directory Structure
- **`framework/`**: Contains the core logic for the unit testing framework (`libunit.a`).
- **`tests/`**: Contains the test cases and the main test runner program.

## Quick Start

### Compiling and Running
To compile both the framework and run the included test suite:
```bash
make test
```

### Using Libunit in Your Own Project
If you want to link `libunit.a` to your own project outside of the provided `tests/` directory, you only need the `framework/` folder.

1. Build the library:
```bash
make -C framework
```

2. Compile your own tests and link against the library:
```bash
cc -Wall -Wextra -Werror your_test_file.c -I framework/inc -L framework -lunit -o my_tests
```

3. Run your executable:
```bash
./my_tests
```

### Changing the Tests Directory
By default, running `make test` from the root directory executes the Makefile inside `tests/`. If you want to use a differently named directory for your tests (e.g. `my_tests`), you can specify it via the `TEST_DIR` variable:

```bash
make test TEST_DIR=my_tests
```

## How to Write Your Own Tests

### 1. Create a Test Function
Use the provided assertion macros to make your life easier. Tests should return `0` on success and `-1` on failure (handled automatically by the macros).

```c
/* tests/src/test_strlen.c */
#include "tests.h"

int test_strlen_basic(void)
{
    UNIT_ASSERT_EQ(ft_strlen("hello"), 5);
    return (0);
}
```

### 2. Output Capturing
If your function writes to `stdout`, you can capture it:
```c
int test_putstr(void)
{
    char *out;
    
    capture_stdout_start();
    ft_putstr("Hello World");
    out = capture_stdout_end();

    UNIT_ASSERT_EQ(ft_strcmp(out, "Hello World"), 0);
    free(out);
    return (0);
}
```

### 3. Registering Tests and Suites
Load your tests into categorized suites in `tests/src/main.c`. You can optionally add `setup` and `teardown` hooks to any suite.

```c
int init_mock_data(void) {
    // Allocation logic here
    return (0); // 0 means success
}

int main(void)
{
    t_test_suite *suites = NULL;
    t_test_suite *s_string;

    // Create a new suite
    s_string = load_suite(&suites, "String Functions");
    
    // Optional: Add setup/teardown hooks
    s_string->setup = init_mock_data; 
    
    // Register tests to the suite
    load_test(s_string, "Strlen Basic", &test_strlen_basic);
    load_test(s_string, "Putstr Capturing", &test_putstr);

    // Launch all suites
    return (launch_tests(&suites));
}
```
