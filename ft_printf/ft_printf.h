#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char			*ft_strcpy(char *dest, char *src);
char			*ft_rev_str(char *str);
char			*ft_itoa(long nbr, int padding);
int				ft_getlen(long nbr);
int				ft_atoi(char *str);
char			*ft_uitoa(unsigned int nbr, int padding);
unsigned int	ft_atoui(char *str);
int				ft_strlen(char *str);

#endif
