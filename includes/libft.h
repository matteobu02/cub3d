/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:11:14 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/16 13:16:37 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	*ft_free_tab(void **tab);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putendl_fd(char const *str, int const fd);
char	*ft_strchr(char const *s, int c);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
char	*ft_strrstr(char const *haystack, char const *needle);
char	*ft_strnstr(char const *haystack, char const *needle, size_t len);

/** GET_NEXT_LINE  **/
# define BUFFER_SIZE	100
char	*get_next_line(int fd);

#endif
