#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int my_printf(char *format_string, char *param)
{
	for (int i = 0; i < strlen(format_string); i++)
	{
		if ((format_string[i] == '#') && (format_string[i + 1] == 'X') && (format_string[i + 2] == 'g'))
		{
			i += 2;
			int j;
			for (j = 0; j < strlen(param); j++)
			{
				char c = param[j];
				if (!isdigit(c))
				{
					break;
				}
				else
				{
					switch (c)
					{
					case '0':
						param[j] = '9';
						break;
					case '1':
						param[j] = '0';
						break;
					case '2':
						param[j] = '1';
						break;
					case '3':
						param[j] = '2';
						break;
					case '4':
						param[j] = '3';
						break;
					case '5':
						param[j] = '4';
						break;
					case '6':
						param[j] = '5';
						break;
					case '7':
						param[j] = '6';
						break;
					case '8':
						param[j] = '7';
						break;
					case '9':
						param[j] = '8';
						break;
					default:
						break;
					}
				}
			}

			if (j < strlen(param))
			{
				puts("");
				return -1;
			}
			else
			{
				printf("%s", param);
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
