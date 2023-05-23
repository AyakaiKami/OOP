#include <iostream>

void sort(int v[101], int n, int(*cmp)(int, int))
{
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for(int i=0;i<n-1;i++)
			if (cmp(v[i], v[i + 1]))
			{
				int cop = v[i];
				v[i] = v[i + 1];
				v[i + 1] = cop;
				sorted = false;
			}
	}
}
int Cresc(int a, int b)
{
	if (a < b)
		return 1;
	return 0;
}
int Desc(int a, int b)
{
	if (a > b)
		return 1;
	return 0;
}
void main()
{
	int v[101], n = 4;
	v[0] = 5;
	v[1] = 4;
	v[2] = 9;
	v[3] = 8;
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	sort(v, n, Desc);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
}
