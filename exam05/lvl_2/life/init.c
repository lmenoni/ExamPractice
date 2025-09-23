#include "life.h"

char    **create_board(int width, int height)
{
    char    **res;
    int     i = 0;
    int     j = 0;

    res = malloc(sizeof(char *) * (height + 1));
    if (!res)
        return (NULL);
    while (i < height)
    {
        j = 0;
        res[i] = malloc(sizeof(char) * (width + 1));
        while (j < width)
        {
            res[i][j] = ' ';
            j++;
        }
        res[i][j] = '\0';
        i++;
    }
    res[i] = NULL;
    return (res);
}

char    *get_moves( void )
{
    char    *res;
    char    *tmp;
    int     size;
    int     byte;
    char    buff[1];

    size = 1;
    res = NULL;
    while ((byte = read(0, buff, 1)) != 0)
    {
        if (byte == -1)
        {
            if (res)
                free(res);
            return (printf("Read Fail\n"), NULL);
        }
        size++;
        tmp = realloc(res, size);
        if (!tmp)
            return (free(res), NULL);
        res = tmp;
        res[size - 2] = buff[0];
        res[size - 1] = '\0';
    }
    return (res);
}

void    free_mat(char **mat, int size)
{
    int i = 0;

    while (i < size)
    {
        free(mat[i]);
        i++;
    }
    free(mat);
}

void    free_all(t_data *data)
{
    if (data->board)
        free_mat(data->board, data->map_h);
    if (data->copy)
        free_mat(data->copy, data->map_h);
    if (data->moves)
        free(data->moves);
}

bool    init_data(t_data *data, char **av)
{
    data->map_w = atoi(av[1]);
    data->map_h = atoi(av[2]);
    data->iterations = atoi(av[3]);
    data->board = create_board(data->map_w, data->map_h);
    if (!data->board)
        return (false);
    data->copy = create_board(data->map_w, data->map_h);
    if (!data->copy)
        return (free_all(data), false);
    data->moves = get_moves();
    if (!data->moves)
        return (free_all(data), false);
    return (true);
}

void    exec_commands(char *moves, char **board, int width, int height)
{
    int i = 0;
    int x = 0;
    int y = 0;
    bool writing = false;

    while (moves[i] != '\0')
    {
        if (moves[i] == 'x')
            writing = !writing;
        else if (moves[i] == 'w')
        {
            if ((y - 1) >= 0 && (y - 1) < height)
                y -= 1;
        }
        else if (moves[i] == 'a')
        {
            if ((x - 1) >= 0 && (x - 1) < width)
                x -= 1;
        }
        else if (moves[i] == 's')
        {
            if ((y + 1) >= 0 && (y + 1) < height)
                y += 1;
        }
        else if (moves[i] == 'd')
        {
            if ((x + 1) >= 0 && (x + 1) < width)
                x += 1;
        }
        if (writing)
            board[y][x] = '0';
        i++;
    }
}

void    print_result(char **result)
{
    int i = 0;
    int j = 0;

    while (result[i])
    {
        j = 0;
        while (result[i][j] != '\0')
        {
            putchar(result[i][j]);
            j++;
        }
        putchar('\n');
        i++;
    }
}