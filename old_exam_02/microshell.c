#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int main(int ac, char **av, char **e)
{
    int i = 0;
    int fd[2];
    int in = dup(STDIN_FILENO);
    (void)ac;

    while (av[i] && av[i + 1])
    {
        av = av[i + 1];
        i = 0;
        while (av[i] && strcmp(av[i], ";") != 0 && strcmp(av[i], "|") != 0)
            i++;
        if (strcmp(av[0], "cd") == 0)
            do_cd(av[i], i);
        else if (i != 0 && (!av[i] || strcmp(av[i], ";") == 0))
            exec_last(av, i, &in, e);
        else if (i != 0 && strcmp(av[i], "|") == 0)
            exec_cmd(av, i, &in, e, fd);
    }
    close(in);
}