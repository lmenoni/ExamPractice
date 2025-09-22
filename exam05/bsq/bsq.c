#include "bsq.h"

int is_min(int n1, int n2, int n3)
{
    int res = 0;

    if (n1 < n2)
        res = n1;
    else
        res = n2;
    if (n3 < res)
        res = n3;
    return (res);
}

void    print_result(t_data *data)
{
    int i = 0;
    int j = 0;

    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (i >= data->best_y && i < (data->best_y + data->best_size)
                && j >= data->best_x && j < (data->best_x + data->best_size))
                data->map[i][j] = data->c_full;
            j++;
        }
        fprintf(stdout, "%s\n", data->map[i]);
        i++;
    }
}

void    solve(t_data *data)
{
    int *prev;
    int *curr;
    int *tmp;
    int i = 0;
    int j = 0;

    curr = calloc(data->col, sizeof(int));
    if (!curr)
        return ;
    prev = calloc(data->col, sizeof(int));
    if (!prev)
        return ;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == data->c_obst)
                curr[j] = 0;
            else if (i == 0 || j == 0)
                curr[j] = 1;
            else
                curr[j] = 1 + is_min(prev[j], prev[j - 1], curr[j - 1]);
            if (curr[j] > data->best_size)
            {
                data->best_size = curr[j];
                data->best_x = j - curr[j] + 1;
                data->best_y = i - curr[j] + 1;
            }
            else if (curr[j] == data->best_size && (i - curr[j] + 1) < data->best_y)
            {
                data->best_x = j - curr[j] + 1;
                data->best_y = i - curr[j] + 1;
            }
            else if ((curr[j] == data->best_size && (i - curr[j] + 1) == data->best_y) && (j - curr[j] + 1) < data->best_x)
                data->best_x = j - curr[j] + 1;
            j++;
        }
        tmp = prev;
        prev = curr;
        curr = tmp;
        i++;
    }
    print_result(data);
}

int     main(int ac, char **av)
{
    FILE    *input;
    t_data  data;
    int i = 1;

    data = (t_data){0};
    if (ac == 1)
    {
        if (parse_file(stdin, &data))
            solve(&data);
        return 1;
    }
    while (av[i])
    {
        data = (t_data){0};
        input = fopen(av[i], "r");
        if (!input)
        {
            fprintf(stderr, "Cannot open file: %s\n", av[i]);
            i++;
            continue;
        }
        if (parse_file(input, &data))
            solve(&data);
        fclose(input);
        i++;
    }
}