#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	int pares;
	
	scanf("%d\n %d\n %d\n %d\n %d", &a, &b, &c, &d, &e);
	
	int aux=0, aux2=0, aux3=0, aux4=0, aux5=0;
	
	aux = (a%2);
	aux2= (b%2);
	aux3= (c%2);
	aux4= (d%2);
	aux5= (e%2);
	
	switch(aux)
	{
		case 0: pares++;

	}	
		switch(aux2)
	{
		case 0: pares++;

	}
	switch(aux3)
	{
		case 0: pares++;

	}
	
	switch(aux4)
	{
		case 0: pares++;

	}
	switch(aux5)
	{
		case 0: pares++;

	}
	printf("%d valores pares\n", pares);
	return 0;
}
