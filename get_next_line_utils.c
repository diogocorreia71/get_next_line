/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:47:20 by diodos-s          #+#    #+#             */
/*   Updated: 2023/05/11 17:04:38 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    extract_line(char *stash, char **line)
{
    int i;
    int j;

    if (!stash)
        return (NULL);
    generate_line(line, stash);
}

size_t  ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int *found_new_line(char *s)
{
    int i;
    
    i = 0;
    if (!s)
        return (0);
    if (s[i] == '\0')
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
            return ((char *)&s[i]);
        i++;
    }
    return (0);
}

char    *add_to_stash(char *stash, char *buf)
{
    size_t  i;
    size_t  j;
    char    *add;

    if (!stash)
    {
        stash = (char *)malloc(1 * sizeof(char));
        stash[0] = '\0';
    }
    if (!stash || !buf)
        return (NULL);
    add = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
    if (!add)
        return (NULL);
    while (stash[++i] != '\0')
        add[i] = stash[i];
    while (buf[j] != '\0')
        add[i++] = buf[j++];
    add[ft_strlen(stash) + ft_strlen(buf)] = '\0';
    free(stash);
    return (add);
}