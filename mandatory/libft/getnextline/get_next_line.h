/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:47:40 by rarobert          #+#    #+#             */
/*   Updated: 2023/08/21 14:48:31 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl {
	char			*str;
	struct s_gnl	*next;
}	t_gnl;

size_t	ft_strlen(const char *str);
char	get_next_char(int fd);
char	*get_next_line(int fd);
char	*get_string(t_gnl *lst, size_t len);
int		ft_dec_lst_size(t_gnl *lst);
void	ft_lstclear(t_gnl *lst);
void	fill_list(int fd, t_gnl *to_fill);
t_gnl	*ft_listnew(void);

#endif