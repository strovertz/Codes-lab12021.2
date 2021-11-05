#include <stdio.h>

int main()
{
	int diaUm, HInicial, minInicio, SegInicial, diaFinal, HoraFinal, minutoFinal, segFinal;
	int TotalEmHora, TotalEmMinuto, TotalEmSeg, TotalEmDia;
	
	scanf("Dia %d\n", &diaUm);
	scanf("%d : %d : %d\n", &HInicial, &minInicio, &SegInicial);
	fflush(stdin);
    scanf("Dia %d\n", &diaFinal);
    scanf("%d : %d : %d", &HoraFinal, &minutoFinal, &segFinal);
    
    switch(HoraFinal < HInicial && diaFinal < diaUm)
    {
    	case 1:
    		TotalEmDia--;
		break;
	}
	TotalEmDia = diaFinal - diaUm;
	TotalEmHora = HoraFinal - HInicial;
	TotalEmMinuto = minutoFinal - minInicio;
	TotalEmSeg = segFinal - SegInicial;

	switch(TotalEmSeg < 0)
	{
		case 1:
			TotalEmSeg += 60;
			TotalEmMinuto -= 1;	
		break;
	}
	switch(TotalEmMinuto < 0)
	{
		case 1:
			TotalEmMinuto += 60;
			TotalEmHora -= 1;	
		break;
	}
	switch(TotalEmHora < 0)
	
	{
		case 1:
			TotalEmHora += 24;
			TotalEmDia -- ;
		break;
	}
	
	printf("%d dia(s)\n", TotalEmDia);
	printf("%d hora(s)\n", TotalEmHora);
	printf("%d minuto(s)\n", TotalEmMinuto);
	printf("%d segundo(s)\n", TotalEmSeg);
	
	
	
	return 0;
}
