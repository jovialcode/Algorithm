#include <stdio.h>
#include <math.h>

int main()
{
	int x1, y1, r1;
	int x2, y2, r2;
	double xr = 0, yr = 0;
	double distance = 0;

	int T = 0;
	int i;

	scanf("%d" ,&T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		xr = pow(x1 - x2,2);
		yr = pow(y1 - y2,2);
		distance = sqrt(xr + yr);

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			printf("-1\n");
		}
		else if ((distance > r1 + r2) || (x1 == x2 && y1 == y2 && r1 != r2) || (distance < abs(r1-r2)))
		{
			printf("0\n");
		}
		else if ((distance == r1 + r2) || (distance == abs(r1-r2))) //외접, 내접
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}

	return 0;
}
