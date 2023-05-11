/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:21:36 by diodos-s          #+#    #+#             */
/*   Updated: 2023/05/11 17:05:31 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    read_and_stash(int fd, char *stash)
{
    char    *buf;
    int     bytes_read;

    buf = malloc(sizeof (char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    bytes_read = 1;
    while (!found_new_line(*stash) && bytes_read != 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read = -1)
        {
            free(buf);
            return (NULL);
        }
        buf[bytes_read] = '\0';
        stash = add_to_stash(stash, buf);
    }
    free(buf);
    return (stash);
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
    extract_line(stash, &line);
    return (line);
}
