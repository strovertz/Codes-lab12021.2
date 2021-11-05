#include <stdio.h>

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	int maior, menor, medio;
	
	
	if(a>b && a>c)
	{
		maior=a;
		if(b>c)
		{
				medio=b;
				menor=c;
		} else if(c>b)
		{
				medio=c;
				menor=b;
		}
	}
	
	if(b>a && b>c)
	{
		maior=b;
		if(a>c)
		{
			medio=a;
			menor=c;
		} else if(c>a)
		{
			medio=c;
			menor=a;
		}
	}
	if(c>a && c>b)
	{
		maior=c;
		if(a>b)
		{
			medio=a;
			menor=b;
		} else if(b>a)
		{
			medio=b;
			menor=a;
		}
		
	}
	
	printf("%d\n%d\n%d\n\n%d\n%d\n%d\n",menor, medio, maior, a, b, c);
	/*printf("%d\n %d\n %d\n", menor, medio, maior, );
	printf("\n %d\n %d\n %d\n", a, b, c);*/
}
