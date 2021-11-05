// DECLARA��O DAS BIBLIOTECAS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
// FIM DA DECLARA��O DAS BIBLIOTECAS

#define qtd_ent        10
#define qtd_prox    10

struct neuronio 
{    
    float entrada[qtd_ent];    // Valor(es) recebido(s) do ambiente ou de outro neur�nio  
    float peso;                // Peso - atribu�do randomicamente - 0,0001 a 0,9999
    float valor;               // Sa�da - resultado
    int camada;                // 0=Entrada... 1=Camada Oculta 1... 2=Camada Oculta 2... 3 Sa�da
    int posicao;               // Posi��o que o neur�nio ocupa (no vetor e na rede) 
    struct neuronio *prox[qtd_prox]; // Endere�o do neur�nio que recebe o valor (resultado) - o pr�ximo na rede (para onde este aponta)
}RNA[12];

typedef struct neuronio Neuronio;

// PROT�TIPOS DAS FUN��ES
void Inicializa(void);         // Atribue um valor inicial aos campos dos Neur�nios
void Conexao(void);            // Faz as liga��es entre todos os Neur�nios
float Peso_vl(void);           // Gera randomicamente um valor para o campo Peso dos Neur�nios
void Gera_resultado(int);      // Cont�m a Fun��o de Ativa��o que a partir das entradas, gera o resultado como sa�da
void Atribue_entrada(int);     // Pega o valor do resultado e joga como entrada dos pr�ximos Neur�nios 
char checaop(void);
// FIM DOS PROT�TIPOS DAS FUN��ES

// INICIALIZA��O DAS VARI�VEIS GLOBAIS
int qtd_neu_entrada    = 2;    // Quantidade de Neur�nios da camada de entrada
int qtd_camada_Oc      = 2;    // Quantidade de Camadas Intermedi�rias (Ocultas) 
int qtd_neu_camada_Oc  = 4;    // Quantidade de Neur�nios por camada Oculta
int qtd_neu_saida      = 2;    // Quantidade de Neur�nios da camada de sa�da
int qtd_neu_total      =(qtd_neu_entrada+qtd_neu_saida+(qtd_camada_Oc*qtd_neu_camada_Oc)); // Quantidade Total de Neur�nios da Rede Neural
int neu_penult_camada  = qtd_neu_entrada + ((qtd_camada_Oc - 1)* qtd_neu_camada_Oc); // primeiro neur�nio da pen�ltima camada que vai apontar para a camada de sa�da
// FIM DA INICIALIZA��O DAS VARI�VEIS GLOBAIS

// FUN��O  QUE RETORNA O VALOR RAND�MICO DO PESO
float Peso_vl() 
{          
     float a = 0;
     a = rand()%9999+1; // gerando um valor randomico entre 1 a 9999
     a = a/10000;       // colocando o valor entre 0,0001 a 0,9999 - conforme especifica��o do projeto
     return (a);      
}    
// FIM DA FUN��O QUE RETORNA O VALOR RAND�MICO DO PESO

// INICIALIZANDO OS CAMPOS DOS NEUR�NIOS 
void Inicializa() 
{
     for(int x=0; x<qtd_neu_total; x++)  
     {
          RNA[x].peso = Peso_vl();
          RNA[x].valor = NULL;
          RNA[x].posicao = x;           // percorre os neur�nios e atribue sua posi��o, ex: RNA[0].posicao = 0, RNA[1].posicao = 1, etc at� o �ltimo
          for (int y=0;y<qtd_ent;y++)   // varre as 10 posi��es da "entrada" e atribue valor 'nulo'
               RNA[x].entrada[y] = NULL;
          for (int z=0;z<qtd_prox;z++)  // varre as 10 posi��es de "prox" e atribue valor 'nulo'
               RNA[x].prox[z] = NULL;
               
     }
     
     // Descobre a camada a qual o neur�nio vai pertencer e atribue esse valor ao campo RNA[a].camada
     int a, b; // a = �ndice no vetor de neur�nios; b = vari�vel que indica a qual camada o neur�nio vai pertencer
     for(a=0;a<qtd_neu_total;a++) // percorrendo todos (os 12) neur�nios do vetor
     {
          for(b=0;b<(qtd_camada_Oc+2);b++) // percorrendo todas (as 4) camadas >>> 2 camadas ocultas + 2 (1 da entrada e 1 da sa�da) 
          {
               if(a<(qtd_neu_entrada+(b*qtd_neu_camada_Oc))) // definindo as camdas para cada neur�nio
               {
                    RNA[a].camada = b;   // adiciona o valor da camada e...
                    b=(qtd_camada_Oc+2); // sai do segundo for
               }
          }      
     }
}
// FIM INICIALIZA��O DOS CAMPOS

// IMPLEMENTA��O DA FUN��O DE LIGA��O
void Conexao ()
{
          int i, j, cont_camada; // i = �ndice (posi��o) do neur�nio no vetor (transmissor); j = �ndice dos neur�nios receptores, cont_camada = captura a camada do neur�nio atual
          
          for(i=0; i<(qtd_neu_total-qtd_neu_saida); i++)  // percorre todos os neur�nios, exceto os da sa�da, pois n�o apontam para ningu�m
          {
               cont_camada = RNA[i].camada;  
               if(i<qtd_neu_entrada) // no nosso caso, se a posi��o do neur�nio for < 2, ou seja, 0 e 1
                   j=qtd_neu_entrada; // ent�o, j recebe 2 (e vai sendo incrementado no "do while" abaixo) - apontar� para a posi��o 2 at� 5
               else if (i<neu_penult_camada) // se a posi��o do neur�nio for < 6 e > 2
                        j = qtd_neu_entrada + (cont_camada*qtd_neu_camada_Oc); // ent�o, j recebe 6 (e vai sendo incrementado no "do while" abaixo) - apontar� para a posi��o 6 at� 9  
                    else 
                        j = qtd_neu_total-qtd_neu_saida; // se a posi��o do neur�nio < 10 e > 6, j recebe 10
               int k=-1;  // �ndice usado em "prox" para ordenar o armazenamento dos endere�os dos pr�ximos neur�nios
               do
               {      
                    k++;   
                    RNA[i].prox[k] = &RNA[j]; // Ex: o neur�nio RNA[3].prox[0] aponta para RNA[6]; RNA[3].prox[1] aponta para RNA[7]... 
                    j++;
               }while (RNA[i].prox[k]->camada == RNA[j].camada);
          }       
} 
// FIM DA FUN��O DE LIGA��O ...........................

// FUN��O DE ATIVA��O QUE GERA O RESULTADO DE UM NEUR�NIO
void Gera_resultado(int r)
{
     int cont = 0;
     float soma = 0;
     float media = 0;     
     for (int g=0; ((g<qtd_ent)&&(RNA[r].entrada[g]!=NULL)); g++) // varre as 10 entradas de um neur�nio - se encontrar valor, aplica a f(x)
     {
         soma = soma + (RNA[r].entrada[g] * log(RNA[r].entrada[g]) * RNA[r].peso); // Fun��o de Ativa��o dada em aula
         cont = cont + 1;
     }
     media = soma/cont;
     RNA[r].valor = media;
}
// FIM DA FUN��O DE ATIVA��O

// FUN��O COMPLEMENTAR PARA ATRIBUIR AS ENTRADAS AOS NEUR�NIOS DE SA�DA
void Atribue_entrada(int w)
{
     int pos = 0; // �ndice onde o Neur�nio recebedor guardar� o "valor" como entrada
     for (int k=0; ((k<qtd_prox)&&(RNA[w].prox[k]!=NULL)); k++)  // �ndice "k" percorre os campos "prox" 
     {
         if(w<qtd_neu_entrada) // Ex: o "valor" (resultado) do Neur�nio de posi��o "0" ser� guardado como entrada no �ndice "0" do Neur�nio de posi��o 2
             pos=w;
         else     
             pos =  RNA[w].posicao - ((RNA[w].camada-1)*qtd_neu_camada_Oc + qtd_neu_entrada);
    
         RNA[w].prox[k]->entrada[pos] = RNA[w].valor;
     }
}
// FIM DA FUN��O COMPLEMENTAR

char checaop()
{
    char op;
    printf("\n DESEJA CONTINUAR TREINANDO A REDE (S/N)?\n");
    op=toupper(getch());
    while ((op!='S')&&(op!='N'))
    {
        printf("\n OPCAO INVALIDA!!!\n");
        op=checaop();
    }    
    return(op);
}

int main()
{   
    srand(time(NULL)); 
    Inicializa();
    Conexao();       
    float vl_ent = 0;
    char opc;
    do
    {   
        system("cls");
        for(int w=0; w<qtd_neu_entrada; w++) // alimenta as entradas dos neur�nios da camada de entrada
        {
            printf("\n\n DIGITE UM VALOR PARA A ENTRADA DO NEURONIO DE POSICAO [%d]: ", w);
            scanf("%f", &vl_ent);
            RNA[w].entrada[0] = vl_ent;
        }   
        
        for(int x=0; x<(qtd_neu_total); x++) // varre todos os neur�nios e aplica a Fun��o de Ativa��o.
        {
            Gera_resultado(x);           
            if (x<(qtd_neu_total-qtd_neu_saida)) // os neur�nios 10 e 11 n�o atribuem seu resultado como entrada a nenhum outro neur�nio 
                 Atribue_entrada(x);  
        }    
        
        for(int y=(qtd_neu_total-qtd_neu_saida); y<qtd_neu_total; y++) // imprime os resultados dos neur�nios da sa�da           
            printf("\n\n RESULTADO FINAL DO NEURONIO RNA[%d].VALOR = %2.4f \n\n", (y), RNA[y].valor);       
        
        /*// IMPRESS�O DOS VALORES DE ENTRADA, PESO E SA�DA
        for(int b=0; b<(qtd_neu_total); b++)
        {
            for(int c=0; c<4; c++)
            {
                printf("\n\n RNA[%d].ENTRADA = %2.4f \n\n", b, RNA[b].entrada[c]);            
                if (b<2) c=4;
                else if ((b<6)&&(c==1)) c=4;
            }   
            printf("\n\n RNA[%d].PESO = %2.4f \n\n", b, RNA[b].peso);  
            printf("\n\n RNA[%d].VALOR = %2.4f \n\n", b, RNA[b].valor);  
            
        }  // FIM DA IMPRESS�O   */            
       
        opc=checaop();   
    }while ((opc=='s')||(opc=='S'));       
       
    getchar();    
    getchar();    
}
