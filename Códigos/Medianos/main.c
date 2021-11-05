	#include <stdio.h>
	
	int main()
	{
		
		float salario, salariolimpo, imposto, imposto2, imposto3;
		
		scanf("%f", &salario);
		
		if(salario >= 0.00 && salario <= 2000.00)
		{
			
			printf("Isento\n");
			
		}
		else if(salario >= 2000.01 && salario <= 3000.00)
		{
			salariolimpo= salario-2000;
			imposto= salariolimpo*0.08;
			printf("R$ %.2f\n", imposto);
			
		}
		else if(salario >= 3000.01 && salario <= 4500.00)
		{
			//salariolimpo= salario-2000;
			imposto= 1000*0.08;
			salariolimpo=salariolimpo-1000.00;
			imposto2=((salario-3000.00)*0.18)+imposto;
			printf("R$ %.2f\n", imposto2);
			
		}
		else if(salario > 4500.00)
		{
			//salariolimpo= salario-2500;
			imposto= 1000*0.08;
			salariolimpo=salariolimpo-1000.00;
			imposto2=(1500*0.18)+imposto;
			salariolimpo=salario-4500.00;
			imposto3=((salario-4500)*0.28)+imposto2;
			printf("R$ %.2f\n", imposto3);
			
		}
		

	return 0;
	
}	#include <stdio.h>
	
	int main()
	{
		
		float salario, salariolimpo, imposto, imposto2, imposto3;
		
		scanf("%f", &salario);
		
		if(salario >= 0.00 && salario <= 2000.00)
		{
			
			printf("Isento\n");
			
		}
		else if(salario >= 2000.01 && salario <= 3000.00)
		{
			salariolimpo= salario-2000;
			imposto= salariolimpo*0.08;
			printf("R$ %.2f\n", imposto);
			
		}
		else if(salario >= 3000.01 && salario <= 4500.00)
		{
			//salariolimpo= salario-2000;
			imposto= 1000*0.08;
			salariolimpo=salariolimpo-1000.00;
			imposto2=((salario-3000.00)*0.18)+imposto;
			printf("R$ %.2f\n", imposto2);
			
		}
		else if(salario > 4500.00)
		{
			//salariolimpo= salario-2500;
			imposto= 1000*0.08;
			salariolimpo=salariolimpo-1000.00;
			imposto2=(1500*0.18)+imposto;
			salariolimpo=salario-4500.00;
			imposto3=((salario-4500)*0.28)+imposto2;
			printf("R$ %.2f\n", imposto3);
			
		}
		

	return 0;
	
}