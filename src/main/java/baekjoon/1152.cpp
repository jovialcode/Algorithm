#include <stdio.h>

int main(void)
{
	char ch;
	int count=0, sw =0;

	while ((ch = getchar()) != '\n' && ch != EOF && ch != '\r')
	{
		if (ch >= 'A')
			sw = 1;
	
		if (sw == 1)
		{
			if (ch == ' ')
			{
				count++;
				sw = 0;
			}
		}
	}
	if (sw == 1)
		count++;
	printf("%d \n", count);

	return 0;
}