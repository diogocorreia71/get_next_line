/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:47:20 by diodos-s          #+#    #+#             */
/*   Updated: 2023/05/10 16:01:46 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int *strchr(char *s, int line_break)
{
    int i;
    
    i = 0;
    if (!s)
        return (0);
    if (s[i] == '\0')
        return (NULL);
    return (i);
}