#include <stdio.h>

int main()
{

    int A, N, i, x=0;
    
    scanf("%d %d", &A, &N);
    
    for(;;)
    {
	
    
        scanf("%d", &N);
        if(N>0)
        	break;
	}
	
    for(i=1; i<=N; i++)
    {
        x+=A;
        A++;
    }
    printf("%d\n",x);
    return 0;

}
