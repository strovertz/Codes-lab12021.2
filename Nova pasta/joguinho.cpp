#include <stdio.h>

int main()
{

    char name[50]="null";
    int  dano=0, defesa=0, sorte=0, classe=0; 


    printf("Voz turva: Olá caro desconhecido\n vejo que caiu neste poço de esquecimento profundo\n... \nantes que eu pareça rude, poderia me dizer seu nome? \n");

    printf("\nDesconhecido: ...\n");

    printf("\nDigite um nome de ateh 50 caracteres\n\n");
    
    scanf("%c", &name);

    printf("Voz turva: Muito bem, de qualquer modo, vou te chamar de Carlos, deixe eu me aproximar de voceh...\n");

    printf("Bem, selecione uma classe: \n(1)clerigo \n(2)atirador \n(3)tanque \n(4)armagedon\n");
 
    scanf("%d", &classe);

    if(classe == 1)
    {
            printf("Voz turva: Então temos um mago viad... digo, um clehrigo, que beeluza, belas perna... ops, digo cajado... Bem, vamos prosseguir...\n\n");
            printf("Carlos(Voceh): hm... esta bem...\n\n");
            printf("Voz turva: hm... Rsrsrsrsrsrs. heheheheh.... HAHAHAHAHAHAH.... hhihihihihiHIhIHi\n\n");
            printf("NARRADOR: derrepente, UM TUBARAÃO COM ASAS PULA DE UMA MASSEGA\n\n CARLOS(VOCE): TUBARAO COM ASAS???? POR FAVOR ME COMA\n\n NARRADOR: E ENTAO TUBARAO COM ASAS COMESSA A PENETRAR SUAS GUELRRAS EM CARLOS! ");

    }    
    else {
        printf("Desculpe, nao aturamos brutamontes por aqui... selecione novamente...");
    }






    return 0;
}
