#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_data
{
    int     rows;
    int     col;
    char    c_empty;
    char    c_obst;
    char    c_full;
    char    **map;
    int     best_x;
    int     best_y;
    int     best_size;
}       t_data;

bool    parse_file(FILE *in, t_data *data);
bool    parse_header(char *line, t_data *data);

#endif