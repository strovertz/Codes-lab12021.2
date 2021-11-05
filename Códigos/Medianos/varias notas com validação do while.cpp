#include <stdio.h>

int main()
{
	int x=1, aux1=1;
	float n1=0, n2=0, media;
	
	for(;;)
	{
		
		scanf("%f %f", &n1, &n2);
		
		while(n1 < 0.00 || n1 > 10.00)
		{
			printf("nota invalida\n");
			scanf("%f", &n1);
		
		}
		while(n2 < 0.00 || n2 > 10.00)
		{
			printf("nota invalida\n");
			scanf("%f", &n2);
		
		}
		
		media=(n1+n2)/2;
		printf("media = %.2f\n", media);
		printf("novo calculo (1-sim 2-nao)\n");
		scanf("%d", &x);
		
		if(x == 1)
			break;
		
		while(x != 1 && x != 2)
		{
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &x);
			if(x==1)
				break;
		}
		
	}
	
		
	
	return 0;
}
