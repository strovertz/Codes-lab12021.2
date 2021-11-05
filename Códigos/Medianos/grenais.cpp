#include <stdio.h> 


int main()
{
	//x=gols do inter y=gols do gremio.
	
	int gremio=0, inter=0, x=0, y=0, empate=0, jogo=0;
	int vax=1;
	
	for(;;)
	{
		printf("digite os gols do inter e depois do gremio: ");
		scanf("%d %d", &x, &y);
		if(x > y)
		{
			inter++;	
		}
		else if(y > x)
		{
			gremio++;	
		}
		else if(x == y)
		{
			empate++;
		}
		
		jogo++;
		
		
	    do
		{
			printf("Novo grenal (1-sim 2-nao)\n");
			scanf("%d", &vax);
		}while(vax != 1 && vax != 2);
		
		if(vax!=1)
			break;
	}
	
	printf("%d grenais\n", jogo);
	printf("Vitorias doInter:%d\nVitorias doGremio:%d\nEmpates:%d\n", inter, gremio, empate);
	
	if(inter > gremio)
	{
		printf("Inter venceu mais\n");
	}
	else if(gremio > inter)
	{
		printf("Gremio venceu mais\n");
	}
	else if(inter == gremio)
	{
		printf("Nao houve vencedor\n");
	}
	
	return 0;
	
}
