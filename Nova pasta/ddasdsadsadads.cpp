#include <stdio.h>

int main()
{
    int x, y=1, a=0,b=1, g=0;
    scanf("%d", &x);
    
    
    do
    {
        if(y%2==1)
        {
            printf("%d ", g);
            g=a+b;
            a=g;
        }
        else if(y==2)
            printf("%d ", g);
        else if(y%2==0)
        {
            printf("%d ",g);
            g=a+b;
            b=g;
        }
		y++;
   }while(y<x);
    printf("%d\n",g);
    return 0;
}
