#include <stdio.h>
#include <math.h>
int main()
{
	
	int r1, r2, l, c;
	int dc1, dc2, sr;
	int pontoC1_x, pontoC1_y;
	int pontoC2_x, pontoC2_y, maiorDiametro;
	double dist = 0.0;
	
	scanf("%d %d %d %d", &l, &c, &r1, &r2);
	
	for(;;)
	{
		
		dc1 = r1*2;
		dc2 = r2*2;
		pontoC1_x = r1;
		pontoC1_y = r1;
		pontoC2_x = l -r2;
		pontoC2_y = c - r2;
		dist = sqrt(pow(pontoC2_x - pontoC1_x,2)+pow(pontoC2_y - pontoC1_y,2));
		sr = r1+r2;
		if(dc1 > dc2)
			maiorDiametro = dc1;	
		else 
			maiorDiametro = dc2;
		if(dist >= sr && maiorDiametro <= c && maiorDiametro <= l)
		{
			printf("S\n");
		}else{
			printf("N\n");
		}
		
	scanf("%d %d %d %d", &l, &c, &r1, &r2);
	
	if(l == 0 && c == 0 && r1 == 0 && r2 == 0)
		break;
	}

	return 0;
}
