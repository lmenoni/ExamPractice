#include "bsq.h"

bool    parse_char(char *line, char *dst, int *i)
{
    while (line[*i] && line[*i] != '\n' && line[*i] == ' ')
        ++*i;
    if (line[*i] == '\0' || line[*i] == '\n')
        return (false);
    *dst = line[*i];
    ++*i;
    if (line[*i] != '\0' && line[*i] != '\n' && line[*i] != ' ')
        return (false);
    return (true);
}

bool    parse_header(char *line, t_data *data)
{
    int i = 0;

    while (line[i] && line[i] != '\n' && line[i] == ' ')
        i++;
    if (line[i] == '\n' || line[i] == '\0' || !(line[i] >= '0' && line[i] <= '9'))
        return (false);
    while (line[i] && line[i] != '\n' && line[i] >= '0' && line[i] <= '9')
    {
        data->rows = data->rows * 10 + (line[i] - 48);
        i++;
    }
    if (line[i] != ' ' || data->rows == 0)
        return (false);
    if (!parse_char(line, &data->c_empty, &i))
        return (false);
    if (!parse_char(line, &data->c_obst, &i))
        return (false);
    if (!parse_char(line, &data->c_full, &i))
        return (false);
    while (line[i] && line[i] != '\n' && line[i] == ' ')
        i++;
    if (line[i] != '\n' && line[i] != '\0')
        return (false);
    if (data->c_empty == data->c_obst || data->c_empty == data->c_full || data->c_full == data->c_obst)
        return (false);
    return (true);
}

bool    parsing(FILE *input, t_data *data)
{
    char    *line = NULL;
    int     byte = 0;
    size_t     cap = 0;

    byte = getline(&line, &cap, input);
    if (byte == -1 || byte == 0)
        return (fprintf(stderr, "1 MAP ERROR.\n"), free(line), false);
    if (!parse_header(line, data))
        return (fprintf(stderr, "2 MAP ERROR.\n"), free(line), false);
    free(line);

    int i = 0;
    int j = 0;
    line = NULL;
    cap = 0;
    data->map = calloc(data->rows + 1, sizeof(char *));
    while (i < data->rows)
    {
        byte = getline(&data->map[i], &cap, input);
        if (byte == 0 || byte == -1)
            return (fprintf(stderr, "3 MAP ERROR.\n"), false);
        j = 0;
        while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
        {
            if (data->map[i][j] != data->c_empty && data->map[i][j] != data->c_obst)
                return (fprintf(stderr, "4 MAP ERROR.\n"), false);
            j++;
        }
        if (data->cols == 0)
            data->cols = j;
        else if (j != data->cols)
            return (fprintf(stderr, "5 MAP ERROR.\n"), false);
        data->map[i][j] = '\0';
        i++;
    }
    if (data->cols == 0)
        return (fprintf(stderr, "6 MAP ERROR.\n"), false);
    return (true);
}