/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:21:36 by diodos-s          #+#    #+#             */
/*   Updated: 2023/05/10 15:58:59 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    read_and_stash(int fd, char *stash)
{
    char    *buff;
    int     bytes_read;

    buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    bytes_read = 1;
    while (!found_new_line(*stash) && bytes_read != 0)
    {
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read = -1)
        {
            free(buff);
            return (NULL);
        }
        buff[bytes_read] = '\0';
    }
}

char    *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
        return (NULL);

    line = NULL;
    read_and_stash(fd, &stash);
    if (!stash)
        return (NULL);
    return (line);
}
