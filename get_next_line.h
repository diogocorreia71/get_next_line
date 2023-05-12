/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diodos-s <diodos-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:23:38 by diodos-s          #+#    #+#             */
/*   Updated: 2023/05/12 12:00:16 by diodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	read_and_stash(int fd, char *stash);
char	*add_to_stash(char *stash, char *buf);
int		*found_new_line(char *s);
size_t	ft_strlen(char *s);
char	extract_line(char *stash);
char	*new_stash(char *stash);

#endif