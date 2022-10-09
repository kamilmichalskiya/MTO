#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int my_printf(char *format_string, char *param)
{
	for (int i = 0; i < strlen(format_string); i++)
	{
		if ((format_string[i] == '#') && (format_string[i + 1] == 'k'))
		{
			i++;
			for (int j = 0; j < strlen(param); j++)
			{
				char value = param[j];
				if (islower(value))
				{
					value = toupper(value);
				}
				else if (isupper(value))
				{
					value = tolower(value);
				}
				putchar(value);
			}
		}
		else if ((format_string[i] == '#') && (format_string[i + 1] == '.'))
		{
			int length = 0;
			for (int j = i + 2; j < strlen(format_string); ++j)
			{
				if (format_string[j] == 'k')
				{
					length = j - i;
				}
				else if (!isdigit(format_string[j]))
				{
					break;
				}
			}
			if (length == 0)
			{
				putchar(format_string[i]);
			}
			else
			{
				char number[length + 1];
				memcpy(number, &format_string[i + 2], length);
				number[length] = '\0';
				int num = atoi(number);
				for (int j = 0; j < strlen(param) && j < num; j++)
				{
					char value = param[j];
					if (islower(value))
					{
						value = toupper(value);
					}
					else if (isupper(value))
					{
						value = tolower(value);
					}
					putchar(value);
				}
				i += length;
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
