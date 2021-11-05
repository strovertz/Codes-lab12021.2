#include <stdio.h>
#include <math.h>

int main()
{
	int x=1, y=1, z=1, w=1, AreaEl=0, AreaCil1, AreaCil2, AreaCilTotal, pi=3.14;
	
	// x e y = largura e comprimento do elevador; z e w = raios de cada cilindro 
	// comprimento cil é a soma de 2x cada raio para verificar se os cilindros podem ser dispostos 1 ao lado do outro
	// largura cil vai verificar se 2x o raio de cada cilindo cabem no elevador, ou seja, se a largura dos cilindos é menor q a do elevador
	
	int comprimentocil=0, larguracil=0, larguracil2=0;
	float hipotenusa;
		
	while(z != 0 && y!=0 && x != 0 && w != 0)
	{
		
		scanf("%d %d %d %d", &x, &y, &z, &w);
		

		
		comprimentocil =(2*z) + (2*w);
		
		larguracil = (2*z);
		
		larguracil2 = (2*w);
		
		hipotenusa = sqrt(pow(y, 2) + pow(x, 2));
		
		//remover o metro de cada canto q sobra:
		hipotenusa = hipotenusa - 2;
		
		if (comprimentocil > hipotenusa)
		{
		if(comprimentocil > x && comprimentocil > y)
		{
			printf("N\n");
		}
		}
		else if(comprimentocil < x || comprimentocil < y || comprimentocil < hipotenusa) 
		{
			if(larguracil < x && larguracil2 < x || larguracil < y && larguracil2 < y)
			{
				printf("S\n");
			}
		
		}
		
	}
	
	
	
	
	return 0;
}
