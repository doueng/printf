#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
#        include <stdio.h>

# define BASE_16_U	"0123456789ABCDEF"
# define BASE_16	"0123456789abcdef"
# define BASE_10	"0123456789"
# define BASE_8		"01234567"
# define FREE		1

/*	SPECIFIERS
-%%	== %
-s	== NULL terminated string
S	==wide-character string
p	== pointer address
-d,i	== integer
D	==
-u	== unsigned int decimal
U	==
-o	== unsigned int octal
-O	== uppercase octal
-x	== unsigned int hexidecimal
-X	== uppercase hex
-c	== char
C	==

DOU The long int argument is converted to signed decimal, unsigned
     octal, or unsigned decimal, 
	 as if the format had been ld, lo, or lu
     respectively.  
	 These conversion characters are deprecated, and will
     eventually disappear.

You must manage the flags
#	= Used with o, x or X specifiers 
		the value is preceeded with 0, 0x or 0X 
		respectively for values different than zero.
0	= 	Left-pads the number with zeroes (0) instead of 
		spaces when padding is specified 
		(see width sub-specifier).
-	=	Left-justify within the given field width; 
		Right justification is the default 
		(see width sub-specifier).
+	=	Forces to preceed the result with a 
		plus or minus sign (+ or -) 
		even for positive numbers. 
		By default, only negative numbers are 
		preceded with a - sign.

specifiers
hh	= 
h	=
l	=
ll	=
j	=
z	=

• You must manage the minimum field-width

Minimum number of characters to be printed.
If the value to be printed is shorter than
this number, the result is padded with blank spaces. 
The value is not truncated even if the result is larger.


• You must manage the precision

For integer specifiers (d, i, o, u, x, X): precision 
specifies the minimum number of digits to be written. 
If the value to be written is shorter than this number, 
the result is padded with leading zeros. 
The value is not truncated even if the result is longer. 
A precision of 0 means that no character is written for the value 0.
For s: this is the maximum number of characters to be printed. 
By default all characters are printed until the ending null character is encountered.
If the period is specified without an explicit value for precision, 0 is assumed.
*/

typedef union u_types
{
	char	c;
	char	*s;
	int		d;
	double	dd;
	long	l;
}			t_types;

typedef struct		s_id
{
	char			f_hash;
	char			f_zero;
	char			f_plus;
	char			f_minus;
	char			f_space;
	size_t			width;
	size_t			precision;
	int				has_precision;
	char			specifier;
	struct	s_id	*next;
	enum {
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				length;
}					t_id;

typedef struct	s_list
{
	t_id			*id;
	struct s_list	*next;
}				t_list;

t_id		*ft_get_flags(char *format);
int			ft_printf(const char* format, ...);
int			ft_printer(char *format, t_id *id, va_list ap);
int			ft_base(size_t n, char c, t_id *id);
char		ft_is_specifier(char c);
int			ft_padding(size_t n_len, t_id *id);
int			ft_print_nbr(char *nbr, t_id *id);
int			ft_printstr(char *str, t_id *id);
size_t		length_converter(va_list ap, int len);
size_t		ft_putwstr(wchar_t *str, t_id *id);
char		*ft_putwchar(wchar_t c, t_id *id);
size_t		ft_putbinary(char c);
size_t		ulength_converter(va_list ap, int len);
char		*padding(char *str, t_id *id, size_t sign_len);
int			ft_putzerochar(t_id *id);
int			input_checker(t_id *id);

char	*ft_strjoinfree(int free1, char *s1, int free2, char *s2);
int				ft_putstrfree(char *str);
char	*ft_strndup(const char *src, size_t len);
int		ft_isdigit(char c);
char	*ft_strcat(char *dest, char *src);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_arrayrev(void *array, size_t size, size_t len);
char	*ft_strdup(const char *src);
void	*ft_memalloc(size_t size);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strrev(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(long long n);
char	*ft_itoa_base(size_t value, char *base);
char	**ft_strsplit(char const *s, char c);
t_list	*ft_lstnew(void const *content, size_t content_size);
char	*ft_strchr(const char *s, int c);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
int		ft_putstr(const char *str);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif
