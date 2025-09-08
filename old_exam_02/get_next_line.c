/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenoni <lmenoni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:08:34 by lmenoni           #+#    #+#             */
/*   Updated: 2025/04/18 16:57:04 by lmenoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10000
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *get_line(char *arc)
{
    int i = 0;
    int len = 0;
    char *r = NULL;
    while (arc && arc[i] != '\n' && arc[i] != '\0')
        i++;
    if (arc[i] == '\n')
        i++;
    len = i + 1;
    r = malloc(len * sizeof(char));
    r[i] = '\0';
    i = 0;
    while (i < (len - 1))
    {
        r[i] = arc[i];
        i++;
    }
    return (r);
}

char *ft_join(char *archive, char *buffer)
{
    int len = 0;
    int i = 0;
    int j = 0;
    char *r = NULL;
    while (archive && archive[i] != '\0')
        i++;
    while (buffer && buffer[j] != '\0')
        j++;
    len = i + j;
    i = 0;
    j = 0;
    r = malloc((len + 1) * sizeof(char));
    while (archive != NULL && archive[i] != '\0')
    {
        r[i] = archive[i];
        i++;
    }
    while (buffer && buffer[j] != '\0')
    {
        r[i + j] = buffer[j];
        j++;
    }
    r[i + j] = '\0';
    return (free(archive), r);
}

char *get_next_line(int fd)
{
    char *buffer = NULL;
    static char *archive;
    static char *init;
    char *line = NULL;
    int byte = -1;
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    while (byte != 0 && archive == NULL)
    {
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte < 0)
            return(free(buffer), free(archive), NULL);
        buffer[byte] = '\0';
        archive = ft_join(archive, buffer);
        if (byte == 0 && archive[0] == '\0')
            return (free(archive), free(buffer), NULL);
    }
    free(buffer);
    if (init == NULL)
        init = archive;
    line = get_line(archive);
    while (*archive != '\n' && *archive != '\0')
        archive++;
    if (*archive == '\n')
        archive++;
    if (*archive == '\0')
    {
        free(init);
        archive = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    char *buffer = NULL;
    char *line = NULL;
    int byte = -1;

    if (fd < 0 || BUFFER_SIZE < 1)
         return (NULL);
    buffer = malloc(2 * sizeof(char));
    while (byte != 0)
    {
        byte = read(fd, buffer, 1);
        if (byte < 0)
            return (free(buffer), NULL);
        buffer[byte] = '\0';
        line = ft_join(line, buffer);
        if (byte == 0 && line[0] == '\0')
            return (free(line), free(buffer), NULL);
    }
    free(buffer);
    return (line);
}

int main()
{
    int fd = open("infile", O_RDONLY);
    char *line = "sess";
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {
            printf("%s", line);
            free(line);
        }
    }
    close(fd);
    return (0);
}
