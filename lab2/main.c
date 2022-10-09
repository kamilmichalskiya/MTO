#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char swap_case_sesnsitivity(char ch)
{
	if (islower(ch))
	{
		return toupper(ch);
	}
	else if (isupper(ch))
	{
		return tolower(ch);
	}
	else
	{
		return ch;
	}
}

int my_printf(char *format_string, char *param)
{
	for (int i = 0; i < strlen(format_string); i++)
	{
		if ((format_string[i] == '#') && (format_string[i + 1] == 'k'))
		{
			i++;
			for (int j = 0; j < strlen(param); j++)
			{
				putchar(swap_case_sesnsitivity(param[j]));
			}
		}
		else if ((format_string[i] == '#') && (format_string[i + 1] == '.'))
		{
			int length = 0;
			for (int j = i + 2; j < strlen(format_string); ++j)
			{
				if (j > i + 2 && format_string[j] == 'k')
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
					putchar(swap_case_sesnsitivity(param[j]));
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
