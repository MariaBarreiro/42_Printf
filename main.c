#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>


int main(){
{
	printf("===========================\n");
	printf("TEST THE %%c\n");
	printf("===========================\n");
	printf("%c%c%c%c\n", 'D', 'A', 'M', 'N');
	ft_printf("%c%c%c%c\n", 'D', 'A', 'M', 'N');
	char c = ' ';
	printf("This right here is EMPTY -> %c <- See EMPTY\n", c);
	ft_printf("This right here is EMPTY -> %c <- See EMPTY\n", c);
	char *s = "ENCARNACAO";
	printf("%c%c%c%c%c%c%c%c%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9]);
	ft_printf("%c%c%c%c%c%c%c%c%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8], s[9]);
}
{
	printf("===========================\n");
	printf("TESTE THE %%s\n");
	printf("===========================\n");
	char *str_null = NULL;
	printf("This right here is NULL -> %s <- See NULL\n", str_null);
	ft_printf("This right here is NULL -> %s <- See NULL\n", str_null);
	char *str = "Gaspar and Encarnacao";
	printf("Who is the person with weird kinks?\nR: %s\n", str);
	ft_printf("Who is the person with weird kinks?\nR: %s\n", str);
	printf("===========================\n");
	printf("TESTE THE %%p\n");
	printf("===========================\n");
	printf("This right here is NULL -> %p <- See NULL\n", &str_null);
	ft_printf("This right here is NULL -> %p <- See NULL\n", &str_null);
	printf("But where are the kinkers?\nR: %p\n", &str);
	ft_printf("But where are the kinkers?\nR: %p\n", &str);
}
{
	printf("===========================\n");
	printf("TESTE THE %%d\n");
	printf("===========================\n");
	printf("%d\n", INT_MAX);
	ft_printf("%d\n", INT_MAX);

	printf("%i\n", INT_MAX);
	ft_printf("%i\n", INT_MAX);

	printf("%d\n", INT_MIN);
	ft_printf("%d\n", INT_MIN);

	printf("%i\n", INT_MIN);
	ft_printf("%i\n", INT_MIN);



	
}
	
}
