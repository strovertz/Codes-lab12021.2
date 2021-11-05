#include <stdio.h>
int main(){
    
    int k, n, m, x, y, i;
    int z=1;
    
    for(;;)
	{
    	scanf("%d", &k);
        if(k == 0) break;
             
        scanf("%d %d", &n, &m);
             
        for(i = 0; i < k; i++){
        	
        	scanf("%d %d", &x, &y);
        	
            if(x == n || y == m) 
			{
				printf("divisa\n");
			}
                   else if(x > n && y > m) 
				   {
				  	 printf("NE\n");
					}
					
                   else if(x > n && y < m) 
				   {
				  	 printf("SE\n");
				   }

                   else if(x < n && y > m)
					{
						printf("NO\n");
					}
                   else if(x < n && y < m) 
                   {
				   printf("SO\n");
				   
					}
				
			
             }
            if(z!=1)
				break; 
    }
    return 0;
}
