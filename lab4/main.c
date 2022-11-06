#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void revers_string(char *string)
{
	int len = strlen(string);
	for (int i = 0; i < len / 2; i++)
	{
		char temp = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = temp;
	}
}

int my_printf(char *format_string, char *param)
{
	for (int i = 0; i < strlen(format_string); i++)
	{
		if ((format_string[i] == '#') && (format_string[i + 1] == 'g'))
		{
			i++;
			int j;
			for (j = 0; j < strlen(param); j++)
				if (!isdigit(param[j]))
					break;

			if (j < strlen(param))
			{
				puts("");
				return -1;
			}
			else
			{
				revers_string(param);
				printf("%d", atoi(param));
			}
		}
		else
			putchar(format_string[i]);
	}
	puts("");
	return 0;
}

int main(int argc, char *argv[])
{
	char buf[1024], buf2[1024];
	while (gets(buf))
	{
		gets(buf2);
		my_printf(buf, buf2);
	}
	return 0;
}
