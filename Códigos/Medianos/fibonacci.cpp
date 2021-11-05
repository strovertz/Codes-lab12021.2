#include <stdio.h>

int main() 
{
	 
    int x=1, y=1, z;
    
   
    
    do
    {
    	scanf("%d", &x);
    	while(y <= x)
    	{
			
	    	printf("%d", y);
	    	y++;
   		}
   		printf("\n");
   		y=1;
		   
	}while(x != 0)
    
    return 0;
}
