#include <stdio.h>


int main()
{
	int x=0, y=0, z=0;
	
	scanf("%d", &x);
	
	y = x;
	
	for(;;)
	{
		
		if(x%y == 0)
		{
			z=x/y;
			printf("%d\n", z);
			
			
		}
	
	y--;
	
	if(z == x )
		break;
	}
	
	return 0;
}
