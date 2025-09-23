#ifndef BSQ_H
#define BSQ_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_vctr
{
    int x;
    int y;
}   t_vctr;

typedef struct s_data
{
    char    c_empty;
    char    c_obst;
    char    c_full;
    int     rows;
    int     cols;
    int     best_size;
    t_vctr  best;
    char    **map;
}   t_data;

bool    parsing(FILE *input, t_data *data);
bool    parse_header(char *line, t_data *data);
bool    parse_char(char *line, char *dst, int *i);


#endif