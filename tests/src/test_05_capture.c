#include "tests.h"

static int  ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int test_05_capture(void)
{
    char *out;

    capture_stdout_start();
    ft_putstr("Hello Capture");
    out = capture_stdout_end();

    UNIT_ASSERT_EQ(ft_strcmp(out, "Hello Capture"), 0);
    free(out);
    return (0);
}
