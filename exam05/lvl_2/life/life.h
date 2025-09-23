#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
    int     map_w;
    int     map_h;
    int     iterations;
    char    **board;
    char    **copy;
    char    *moves;
}       t_data;

void    print_result(char **result);
void    exec_commands(char *moves, char **board, int width, int height);
bool    init_data(t_data *data, char **av);
void    free_all(t_data *data);
void    free_mat(char **mat, int size);
char    *get_moves( void );
char    **create_board(int width, int height);


#endif