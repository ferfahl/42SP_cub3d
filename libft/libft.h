/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   libft.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: feralves < feralves@student.42sp.org.br	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/16 18:19:58 by feralves		  #+#	#+#			 */
/*   Updated: 2022/10/13 23:17:15 by feralves		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//Libraries
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "getnextline/get_next_line.h"
# include "printf/ft_printf.h"

//Struct

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//Functions

int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

//Bonus functions

void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

//Other functions

char		*ft_hex_itoa(unsigned int n);
char		*ft_pointer_itoa(unsigned long int n);
char		*ft_uitoa(unsigned int n);
size_t		ft_strlen_char(const char *str, char a);
void		ft_printf_array(char **array);
void		ft_free_array(char **array);
char		*ft_strtrim_mod(char *s1, char const *set);
void		ft_free_int(int **array);
long int	ft_atoi_mod(char *nptr);
int			ft_isdigit_mod(char *string);
char		*ft_strjoin_free(char *s1, char *s2);

#endif
