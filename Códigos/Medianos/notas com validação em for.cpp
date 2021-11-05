#include <stdio.h>

int main()
{
	int x=1, aux1=1;
	float n1=0, n2=0, media;

	for(;;)	
	{
		for(;;)
		{
			scanf("%f", &n1);
			if(n1 >= 0.00 && n1 <= 10.00)
				break;
			printf("nota invalida\n");	
		}
		for(;;)
		{
			scanf("%f", &n2);
			if(n2 >= 0.00 && n2 <= 10.00)
				break;
			printf("nota invalida\n");	
		}
		
		media=(n1+n2)/2;
		printf("media = %.2f\n", media);
	
		
		
		for(;;)	
		{
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &x);
			if(x==1 || x==2)
				break;
		}
		if(x==2)
			break;
	}
	
	return 0;
}
