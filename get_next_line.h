/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:21 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 20:29:39 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_params {
	int		state;
	int		i;
	char	*buf;
	size_t	last_sz;
}				t_params;

char	*get_next_line(int fd);
ssize_t	ft_index_of(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *s);
char	*ft_roll_left(char **s, size_t i);
char	*ft_strndup(char *s, size_t n);

#endif