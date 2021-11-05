#include <stdio.h>
//#include <math.h>

int main()
{
	
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	int maior, meio, menor;
	
	switch(a > b && b > c)
	{
		case 1:
			maior = a;
			meio = b;
			menor = c;
		break;	
	}
	switch(a > c && c > b)
	{
		case 1:
			maior = a;
			meio = c;
			menor = b;
		break;	
	}
	switch(b > a && a > c)
	{
		case 1:
			maior = b;
			meio = a;
			menor = c;
		break;	
	}
	switch(b > c && c > a)
	{
		case 1:
			maior = b;
			meio = c;
			menor = a;
		break;	
	}
	switch(c > a && a > b)
	{
		case 1:
			maior = c;
			meio = a;
			menor = b;
		break;
	}
	switch(c > b && b > a)
	{
		case 1:	
			maior = c;
			meio = b;
			menor = a;
		break;	
	}

	printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", menor, meio, maior, a, b, c);
	return 0;

}
