#include <stdio.h>

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	int maior, meio, menor;
	
	switch(a>b && a>c)
	{
		case 1:
			maior=a;

		switch(b<c)
		{
		
			case 1:
				meio=b;
				menor=c;
				break;
		}
		switch(c>b)
			{
				case 1: 
					meio=c;
					menor=b;
				break;
			}
	break;
	}
	
	switch(b>a && b>c)
	{
		case 1:
			meio=a;
			menor=c;		
		
		switch(c<a)
		{
			case 1: 
				meio=a;
				menor=c;	
		break;
		}
		
		switch(c>a)
			{
				meio=c;
				menor=a;
				break;
			}
			
		break;
	}
	switch(c>a && c>b)
	{
		case 1:
			maior=c;

		switch(a>b)
		{
			meio=a;
			menor=b;	
		
		break;
		}
		switch(b>a)
		{
			meio=b;
			menor=a;
		}
	break;
	}
	
printf("%d\n%d\n%d\n\n%d\n%d\n%d\n",menor, meio, maior, a, b, c);
	return 0;
}
