#include <stdio.h>
int triMin(int n1, int n2, int n3);

int main()
{
	int color[1001][3];
	int minBuffer[3] = { 0, };
	int tempBuffer[3] = { 0, };
	int i,j,houseN;

	scanf("%d", &houseN);
	for (i = 0; i < houseN; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &color[i][j]);
		}
	}

	minBuffer[0] = color[0][0];
	minBuffer[1] = color[0][1];
	minBuffer[2] = color[0][2];

	if (houseN == 1){;}
	else {
		for (i = 1; i < houseN; i++)
		{
			tempBuffer[0] = ((minBuffer[1] + color[i][0] < minBuffer[2] + color[i][0]) ? minBuffer[1] + color[i][0] : minBuffer[2] + color[i][0]);
			tempBuffer[1] = ((minBuffer[0] + color[i][1] < minBuffer[2] + color[i][1]) ? minBuffer[0] + color[i][1] : minBuffer[2] + color[i][1]);
			tempBuffer[2] = ((minBuffer[0] + color[i][2] < minBuffer[1] + color[i][2]) ? minBuffer[0] + color[i][2] : minBuffer[1] + color[i][2]);
			minBuffer[0] = tempBuffer[0];
			minBuffer[1] = tempBuffer[1];
			minBuffer[2] = tempBuffer[2];
		}
	}

	printf("%d", triMin(minBuffer[0], minBuffer[1], minBuffer[2]));
	return 0;
}

int triMin(int n1, int n2, int n3)
{
	return (n1 < n2 ? n1 : n2) < (n2 < n3 ? n2 : n3) ? (n1 < n2 ? n1 : n2) : (n2 < n3 ? n2 : n3);
}
