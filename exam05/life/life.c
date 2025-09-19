#include "life.h"

char    new_status(t_data *data, char *curr, int x, int y)
{
    int ppl = 0;
    int dx  = -1;
    int dy  = -1;

    while (dy <= 1)
    {
        dx = -1;
        while (dx <= 1)
        {
            if (dx != 0 || dy != 0)
            {
                if ((x + dx) >= 0 && (x + dx) < data->map_w 
                    && (y + dy) >= 0 && (y + dy) < data->map_h
                    && data->board[y + dy][x + dx] == '0')
                    ppl++;
            }
            dx++;
        }
        dy++;
    }
    if (*curr == '0' && (ppl < 2 || ppl > 3))
        return (' ');
    if (*curr == ' ' && ppl == 3)
        return ('0');
    return (*curr);
}

void    simulate(t_data *data)
{
    char **tmp;
    int iter = 0;
    int i = 0;
    int j = 0;

    while (iter < data->iterations)
    {
        i = 0;
        while (data->board[i])
        {
            j = 0;
            while (data->board[i][j])
            {
                data->copy[i][j] = new_status(data, &data->board[i][j], j, i);
                j++;
            }
            i++;
        }
        tmp = data->board;
        data->board = data->copy;
        data->copy = tmp;
        // printf("-----------------------\n");
        // print_result(data->board);
        // printf("-----------------------\n");
        iter++;
    }
}

int main(int ac, char **av)
{
    t_data  data;

    data = (t_data){0};
    if (ac == 4 && init_data(&data, av))
    {
        exec_commands(data.moves, data.board, data.map_w, data.map_h);
        // printf("---INITIAL---\n");
        // print_result(data.board);
        simulate(&data);
        printf("---RESULT---\n");
        print_result(data.board);
        free_all(&data);
    }
}