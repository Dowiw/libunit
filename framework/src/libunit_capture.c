#include "libunit.h"

static int g_capture_fd[2];
static int g_saved_stdout;

void capture_stdout_start(void)
{
    g_saved_stdout = dup(STDOUT_FILENO);
    if (pipe(g_capture_fd) == -1)
        return ;
    dup2(g_capture_fd[1], STDOUT_FILENO);
}

char *capture_stdout_end(void)
{
    char    *buffer;
    int     ret;

    close(g_capture_fd[1]);
    dup2(g_saved_stdout, STDOUT_FILENO);
    close(g_saved_stdout);

    buffer = (char *)malloc(1024);
    if (!buffer)
        return (NULL);
    ret = read(g_capture_fd[0], buffer, 1023);
    if (ret >= 0)
        buffer[ret] = '\0';
    else
        buffer[0] = '\0';
    close(g_capture_fd[0]);
    return (buffer);
}
