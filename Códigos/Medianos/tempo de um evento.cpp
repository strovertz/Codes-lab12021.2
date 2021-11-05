#include <stdio.h>

int main(){
	
	int diaUm, HInicial, minInicio, SegInicial, diaFinal, HoraFinal, minutoFinal, segFinal;
	int TotalEmHora, TotalEmMinuto, TotalEmSeg, TotalEmDia;
	
	scanf("Dia %d\n", &diaUm);
	scanf("%d : %d : %d\n", &HInicial, &minInicio, &SegInicial);
	fflush(stdin);
    scanf("Dia %d\n", &diaFinal);
    scanf("%d : %d : %d", &HoraFinal, &minutoFinal, &segFinal);
	
		if(HoraFinal < HInicial && diaFinal < diaUm)
	{
		TotalEmDia--;
	}
	TotalEmDia = diaFinal - diaUm;
	TotalEmHora = HoraFinal - HInicial;
	TotalEmMinuto = minutoFinal - minInicio;
	TotalEmSeg = segFinal - SegInicial;


	if (TotalEmSeg < 0){
		TotalEmSeg += 60;
		TotalEmMinuto -= 1;
	}
	
	if (TotalEmMinuto < 0){
		TotalEmMinuto += 60;
		TotalEmHora -= 1;
	}

	if (TotalEmHora < 0){
	    TotalEmHora += 24;
		TotalEmDia -- ;
	
	}

	printf("%d dia(s)\n", TotalEmDia);
	printf("%d hora(s)\n", TotalEmHora);
	printf("%d minuto(s)\n", TotalEmMinuto);
	printf("%d segundo(s)\n", TotalEmSeg);
	
	return 0;
}
