#include <stdio.h>

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	int maior, meio, menor;
	
	if(a<b)
	{
		maior=a;
		printf("%d\n", maior);
		
		if(b<c)
		{
			menor=b;
			meio=c;
			printf("%d", meio);
			printf("%d", menor);
		}
	} 
	else if(b<a)
	{
		maior=b;
		printf("%d\n", maior);
		
		if(a<c)
		{
			menor=c;
			meio=a;
			printf("%d", meio);
			printf("%d", menor);
		}
		else
		{
			menor=a;
			meio=c;
			printf("%d", meio);
			printf("%d", menor);
		}
	} 
	else if(c<b)
	{
		maior=c;
		printf("%d\n", maior);
		
		if(a<c)
		{
			menor=;
			meio=b;
			printf("%d", meio);
			printf("%d", menor);
		}
	} 
	
	
	
	return 0;
}
