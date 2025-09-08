#include "argo.h"

// Estrae un intero, niente di che :).
int     parse_integer(FILE *stream)
{
    int r = 0;

    while (peek(stream) != EOF && isdigit(peek(stream)))
        r = r * 10 + (getc(stream) - '0');
    return (r);
}

// Estrae una stringa e la ritorna.
// Fa il controllo della sintassi, ritorna NULL in caso di errore.
char    *parse_string(FILE *stream)
{
    int len = 10;
    int size = 0;
    char *r;
    char *temp;
    int c = 0;

    // Ridondante, fa saltare la ", tutto qua :).
    if (!expect(stream, '"'))
        return (NULL);
    r = malloc(len * sizeof(char));
    if (!r)
        return (NULL);
    // Cicla funo EOF o " e copia da stream in r.
    while (peek(stream) != EOF && peek(stream) != '"')
    {
        // Se stiamo prendendo piu' di len caratteri(10 di default) viene fatto un realloc.
        if (size >= len - 1)
        {
            len *= 2;
            temp = realloc(r, len);
            if (!temp)
                return (NULL);
            r = temp;
        }
        // Prendiamo il carattere e controlliamo se e' un escape.
        // Se lo e' il carttere successivo deve essere " o \\ (gli unici da gestire).
        // Nel caso scrive quel carattere e va avanti.
        c = getc(stream);
        if (c == '\\')
        {
            c = getc(stream);
            if (c != '"' && c != '\\')
            {
                free(r);
                return (NULL);
            }
        }
        r[size] = c;
        size++;
    }
    // Controllo che siano state chiuse le quote e che quindi non ci sia un unexpected EOF.
    if (!expect(stream, '"'))
    {
        free(r);
        return (NULL);
    }
    r[size] = '\0';
    return (r);
}
// Riempe i dati di una map creando json r di ritorno.
// Setta la size della mappa a INT_MAX in caso di errore.
json    parse_map(FILE *stream)
{
    json    r;
    json    value;
    char    *key;

    r.type = MAP;
    r.map.data = NULL;
    r.map.size = 0;
    if (!expect(stream, '{'))
        return (r);
    while (peek(stream) != EOF && peek(stream) != '}')
    {
        // Prendi il nome della variabile e controlla errore di sintassi.
        key = parse_string(stream);
        if (!key)
        {
            r.map.size = INT_MAX;
            return (r);
        }
        // Controlla e skippa i :, ci devono essere dopo il nome della variabile, senno' e' errore di sintassi.
        if (!expect(stream, ':'))
        {
            free(key);
            r.map.size = INT_MAX;
            return (r);
        }
        // Riempe la struttura json temporanea value con quello che c'e' dopo i :.
        // E' ricorsiva, se value e' un'altra map continuera' vino a trovare variabili string o integer.
        if (argo(&value, stream) == 0)
        {
            free(key);
            r.map.size = INT_MAX;
            return (r);
        }
        // Alloca e assegna una struct pair all'array data.
        r.map.data = realloc(r.map.data, sizeof(pair) * (r.map.size + 1));
        if (!r.map.data)
        {
            free(key);
            r.map.size = INT_MAX;
            return (r);
        }
        r.map.data[r.map.size].key = key;
        r.map.data[r.map.size].value = value;
        r.map.size++;
        // Se viene trovata la , skippa il carattere e continua il loop.
        // Altrimenti controlla che venga chiusa la graffa della mappa attuale, senno' e' errore di sintassi.
        if (peek(stream) == ',')
            getc(stream);
        else if (!expect(stream, '}'))
        {
            free(key);
            free(r.map.data);
            r.map.size = INT_MAX;
            return (r);
        }
    }
    return (r);
}
// Argo riempe una struttura di tipo json con il tipo di dato attuale(rispetto a dove e' arrivato stream).
int argo(json *dst, FILE *stream)
{
    int c = peek(stream);
    
    if (c == '{')
    {
        *dst = parse_map(stream);
        if (dst->map.size == INT_MAX)
            return (0);
    }
    else if (c == '"')
    {
        dst->type = STRING;
        dst->string = parse_string(stream);
        if (!dst->string)
            return (0);
    }
    else if (isdigit(c))
    {
        dst->type = INTEGER;
        dst->integer = parse_integer(stream);
    }
    else
    {
        unexpected(stream);
        return (0);
    }
    return (1);
    
}
