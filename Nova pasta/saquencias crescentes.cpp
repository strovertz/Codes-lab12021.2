#include <stdio.h>

int main() 
{
	 
    int x=1, y=1, z;
    
   
    
    for(;;)
    {
    	scanf("%d", &x);
    	while(y < x)
    	{
			
	    	printf("%d ", y);
	    	y++;
   		}
   		if(y=x)
   		{
   			printf("%d\n", x);
		}	
   		//printf("\n");
   		y=1;
   		
		if(x == 0)
			break;
	}
    
    return 0;
}
