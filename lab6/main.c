#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int my_printf(char *format_string, char *param)
{
	for (int i = 0; i < strlen(format_string); i++)
	{
		if ((format_string[i] == '#') && (format_string[i + 1] == '.'))
		{
			int number_of_chars = 0;
			for (int j = i + 2; j < strlen(format_string); ++j)
			{
				if (j > i + 2 && format_string[j] == 'g')
				{
					number_of_chars = j - (i + 2);
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
				for (int j = 0; j < strlen(param); j++)
				{
					if (!isdigit(param[j]))
					{
						puts("");

						return -1;
					}
				}
				i += 2;
				char number_in_chars[number_of_chars + 1];
				memcpy(number_in_chars, &format_string[i], number_of_chars);
				number_in_chars[number_of_chars] = '\0';
				int num = atoi(number_in_chars);
				for (int j = 0; j < strlen(param) && j < num; j++)
				{
					putchar(param[j]);
					
				}
				i += number_of_chars;
			}
		}
		else
			putchar(format_string[i]);
	}
	puts("");
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
