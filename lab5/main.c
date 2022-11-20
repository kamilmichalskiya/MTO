#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int my_printf(char *format_string, char *param)
{
	for (int i = 0; i < strlen(format_string); i++)
	{
		if (format_string[i] == '#')
		{
			int number_of_chars = 0;
			for (int j = i + 1; j < strlen(format_string); ++j)
			{
				if (j > i + 1 && format_string[j] == 'g')
				{
					number_of_chars = j - (i + 1);
				}
				else if (!isdigit(format_string[j]))
				{
					break;
				}
			}
			if (number_of_chars == 0)
			{
				putchar(format_string[i]);
			}
			else
			{
				i += 1;
				char number_in_chars[number_of_chars + 1];
				memcpy(number_in_chars, &format_string[i], number_of_chars);
				number_in_chars[number_of_chars] = '\0';
				int num = atoi(number_in_chars);

				for (int j = strlen(param); j < num; j++)
				{
					if (format_string[i] == '0')
					{
						putchar('9');
					}
					else
					{
					}
					putchar(' ');
				}
				int k;
				for (k = 0; k < strlen(param); k++)
				{
					char c = param[k];
					if (!isdigit(c))
					{
						break;
					}
					else
					{
						switch (c)
						{
						case '0':
							param[k] = '9';
							break;
						case '1':
							param[k] = '0';
							break;
						case '2':
							param[k] = '1';
							break;
						case '3':
							param[k] = '2';
							break;
						case '4':
							param[k] = '3';
							break;
						case '5':
							param[k] = '4';
							break;
						case '6':
							param[k] = '5';
							break;
						case '7':
							param[k] = '6';
							break;
						case '8':
							param[k] = '7';
							break;
						case '9':
							param[k] = '8';
							break;
						default:
							break;
						}
					}
				}

				if (k < strlen(param))
				{
					puts("");
					return -1;
				}
				else
				{
					printf("%s", param);
				}
			}
			i += number_of_chars;
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
