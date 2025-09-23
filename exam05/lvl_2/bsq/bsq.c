#include "bsq.h"

int     is_min(int n1, int n2, int n3)
{
    if (n2 < n1)
        n1 = n2;
    if (n3 < n1)
        n1 = n3;
    return (n1);
}

void    print_result(t_vctr best, int size, char **map, char full)
{
    int i = 0;
    int j = 0;

    fprintf(stdout, "best x: %d best y: %d\n", best.x, best.y);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (i < (size + best.y) && i >= best.y
                && j < (size + best.x) && j >= best.x)
                map[i][j] = full;
            j++;
        }
        fprintf(stdout, "%s\n", map[i]);
        i++;
    }
}

void    solve(t_data *data, char **map)
{
    int *curr;
    int *prev;
    int *temp;
    int i = 0;
    int j = 0;

    curr = calloc(data->cols, sizeof(int));
    prev = calloc(data->cols, sizeof(int));
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == data->c_obst)
                curr[j] = 0;
            else if (i == 0 || j == 0)
                curr[j] = 1;
            else
                curr[j] = 1 + is_min(prev[j], prev[j - 1], curr[j - 1]);
            if (data->best_size < curr[j])
            {
                data->best_size = curr[j];
                data->best.x = j - curr[j] + 1;
                data->best.y = i - curr[j] + 1;
            }
            else if (data->best_size == curr[j] && data->best.y > (i - curr[j] + 1))
            {
                data->best.x = j - curr[j] + 1;
                data->best.y = i - curr[j] + 1;
            }
            else if (data->best_size == curr[j] && data->best.y == (i - curr[j] + 1) && data->best.x > (j - curr[j] + 1))
                data->best.x = j - curr[j] + 1;
            j++;
        }
        temp = prev;
        prev = curr;
        curr = temp;
        i++;
    }
    print_result(data->best, data->best_size, data->map, data->c_full);
}

int main(int ac, char **av)
{
    t_data  data;
    FILE    *input;

    data = (t_data){0};
    if (ac == 1)
    {
        if (parsing(stdin, &data))
            solve(&data, data.map);
        return (1);
    }

    int i = 1;
    while (i < ac)
    {
        data = (t_data){0};
        input = fopen(av[i], "r");
        if (input)
        {
            if (parsing(input, &data))
                solve(&data, data.map);
        }
        i++;
    }
}