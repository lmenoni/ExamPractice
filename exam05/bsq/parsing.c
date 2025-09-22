#include "bsq.h"

bool    parse_n_rows(char *line, t_data *data, int *i)
{
    if ((line[*i] - 48) > 0 && (line[*i] - 48) <= 9)
    {
        while (line[*i] && (line[*i] - 48) >= 0 && (line[*i] - 48) <= 9)
        {
            data->rows = (data->rows * 10) + (line[*i] - 48);
            *i = *i + 1;
        }
    }
    else
        return (fprintf(stderr, "Invalid n rows\n"), false);
    if (line[*i] != ' ' || data->rows == 0)
        return (fprintf(stderr, "Invalid n rows\n"), false);
    return (true);
}

bool    parse_char(char *line, char *dst, int *i)
{
    while (line[*i] && line[*i] == ' ')
        ++*i;
    if (line[*i] == '\0' || line[*i] == '\n')
        return (fprintf(stderr, "Invalid Header.\n"), false);
    *dst = line[*i];
    if (line[*i + 1] != ' ' && line[*i + 1] != '\0' && line[*i + 1] != '\n')
        return (fprintf(stderr, "Invalid Char\n"), false);
    ++*i;
    return (true);
}

bool    parse_header(char *line, t_data *data)
{
    int i = 0;

    while (line[i] && line[i] == ' ')
        i++;
    if (line[i] == '\0' || line[i] == '\n')
        return (fprintf(stderr, "1st Line Empty.\n"), false);
    if (!parse_n_rows(line, data, &i))
        return (false);
    if (!parse_char(line, &data->c_empty, &i))
        return (false);
    if (!parse_char(line, &data->c_obst, &i))
        return (false);
    if (!parse_char(line, &data->c_full, &i))
        return (false);

    while (line[i] && line[i] == ' ')
        i++;
    if (line[i] != '\0' && line[i] != '\n')
        return (fprintf(stderr, "Invalid Header.\n"), false);
    if (data->c_empty == data->c_obst || data->c_empty == data->c_full || data->c_obst == data->c_full)
        return (fprintf(stderr, "Chars must be distinct.\n"), false);
    return (true);
}

bool    parse_file(FILE *in, t_data *data)
{
    char    *line = NULL;
    size_t  cap = 0;
    ssize_t len = 0;

    len = getline(&line, &cap, in);
    if (len == -1)
        return (fprintf(stderr, "GetLine Error.\n"), free(line), false);
    if (!parse_header(line, data))
        return (free(line), false);
    free(line);

    int i = 0;
    int j = 0;
    cap = 0;
    data->map = calloc((data->rows + 1), sizeof(char *));
    if (!data->map)
        return (fprintf(stderr, "Calloc Error.\n"), false);
    while (i < data->rows)
    {
        len = getline(&data->map[i], &cap, in);
        if (len == -1 || len == 0)
            return (fprintf(stderr, "GetLine Error.\n"), false);
        j = 0;
        while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
        {
            if (data->map[i][j] != data->c_empty && data->map[i][j] != data->c_obst)
                return (fprintf(stderr, "AAMap Error.\n"), false);
            j++;
        }
        if (data->col == 0)
            data->col = j;
        else if (j != data->col || j == 0)
            return (fprintf(stderr, "BBMap Error.\n"), false);
        data->map[i][j] = '\0';
        i++;
    }
    return (true);
}