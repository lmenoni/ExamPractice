#include "bsq.h"

bool    parse_char(char *line, char *dst, int *i)
{
    if (line[*i] == '\0' || line[*i] == '\n')
        return (false);
    *dst = line[*i];
    ++*i;
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
    if (data->rows == 0 || !parse_char(line, &data->c_empty, &i) // parse_char controlla che non siamo in fondo, salva il carattere e scorre i
        || !parse_char(line, &data->c_obst, &i)
        || !parse_char(line, &data->c_full, &i)
        || (line[i] != '\n' && line[i] != '\0') // controlla che dopo i 3 parse char siamo in fondo
        || data->c_empty == data->c_obst || data->c_empty == data->c_full // controllo che non siano uguali
        || data->c_full == data->c_obst)
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
        return (fprintf(stderr, "ERROR: invalid map\n"), free(line), false);
    if (!parse_header(line, data))
        return (fprintf(stderr, "ERROR: invalid map\n"), free(line), false);
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
            return (fprintf(stderr, "ERROR: invalid map\n"), false);
        j = 0;
        while (data->map[i][j] != '\0' && data->map[i][j] != '\n')
        {
            if (data->map[i][j] != data->c_empty && data->map[i][j] != data->c_obst)
                return (fprintf(stderr, "ERROR: invalid map\n"), false);
            j++;
        }
        if (j == 0)
            return (fprintf(stderr, "ERROR: invalid map\n"), false);
        if (data->cols == 0)
            data->cols = j;
        else if (j != data->cols)
            return (fprintf(stderr, "ERROR: invalid map\n"), false);
        data->map[i][j] = '\0';
        i++;
    }
    if (data->cols == 0)
        return (fprintf(stderr, "ERROR: invalid map\n"), false);
    return (true);
}