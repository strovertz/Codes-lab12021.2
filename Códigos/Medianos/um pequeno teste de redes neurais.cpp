// DECLARAÇÃO DAS BIBLIOTECAS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
// FIM DA DECLARAÇÃO DAS BIBLIOTECAS

#define qtd_ent        10
#define qtd_prox    10

struct neuronio 
{    
    float entrada[qtd_ent];    // Valor(es) recebido(s) do ambiente ou de outro neurônio  
    float peso;                // Peso - atribuído randomicamente - 0,0001 a 0,9999
    float valor;               // Saída - resultado
    int camada;                // 0=Entrada... 1=Camada Oculta 1... 2=Camada Oculta 2... 3 Saída
    int posicao;               // Posição que o neurônio ocupa (no vetor e na rede) 
    struct neuronio *prox[qtd_prox]; // Endereço do neurônio que recebe o valor (resultado) - o próximo na rede (para onde este aponta)
}RNA[12];

typedef struct neuronio Neuronio;

// PROTÓTIPOS DAS FUNÇÕES
void Inicializa(void);         // Atribue um valor inicial aos campos dos Neurônios
void Conexao(void);            // Faz as ligações entre todos os Neurônios
float Peso_vl(void);           // Gera randomicamente um valor para o campo Peso dos Neurônios
void Gera_resultado(int);      // Contém a Função de Ativação que a partir das entradas, gera o resultado como saída
void Atribue_entrada(int);     // Pega o valor do resultado e joga como entrada dos próximos Neurônios 
char checaop(void);
// FIM DOS PROTÓTIPOS DAS FUNÇÕES

// INICIALIZAÇÃO DAS VARIÁVEIS GLOBAIS
int qtd_neu_entrada    = 2;    // Quantidade de Neurônios da camada de entrada
int qtd_camada_Oc      = 2;    // Quantidade de Camadas Intermediárias (Ocultas) 
int qtd_neu_camada_Oc  = 4;    // Quantidade de Neurônios por camada Oculta
int qtd_neu_saida      = 2;    // Quantidade de Neurônios da camada de saída
int qtd_neu_total      =(qtd_neu_entrada+qtd_neu_saida+(qtd_camada_Oc*qtd_neu_camada_Oc)); // Quantidade Total de Neurônios da Rede Neural
int neu_penult_camada  = qtd_neu_entrada + ((qtd_camada_Oc - 1)* qtd_neu_camada_Oc); // primeiro neurônio da penúltima camada que vai apontar para a camada de saída
// FIM DA INICIALIZAÇÃO DAS VARIÁVEIS GLOBAIS

// FUNÇÃO  QUE RETORNA O VALOR RANDÔMICO DO PESO
float Peso_vl() 
{          
     float a = 0;
     a = rand()%9999+1; // gerando um valor randomico entre 1 a 9999
     a = a/10000;       // colocando o valor entre 0,0001 a 0,9999 - conforme especificação do projeto
     return (a);      
}    
// FIM DA FUNÇÃO QUE RETORNA O VALOR RANDÔMICO DO PESO

// INICIALIZANDO OS CAMPOS DOS NEURÔNIOS 
void Inicializa() 
{
     for(int x=0; x<qtd_neu_total; x++)  
     {
          RNA[x].peso = Peso_vl();
          RNA[x].valor = NULL;
          RNA[x].posicao = x;           // percorre os neurônios e atribue sua posição, ex: RNA[0].posicao = 0, RNA[1].posicao = 1, etc até o último
          for (int y=0;y<qtd_ent;y++)   // varre as 10 posições da "entrada" e atribue valor 'nulo'
               RNA[x].entrada[y] = NULL;
          for (int z=0;z<qtd_prox;z++)  // varre as 10 posições de "prox" e atribue valor 'nulo'
               RNA[x].prox[z] = NULL;
               
     }
     
     // Descobre a camada a qual o neurônio vai pertencer e atribue esse valor ao campo RNA[a].camada
     int a, b; // a = índice no vetor de neurônios; b = variável que indica a qual camada o neurônio vai pertencer
     for(a=0;a<qtd_neu_total;a++) // percorrendo todos (os 12) neurônios do vetor
     {
          for(b=0;b<(qtd_camada_Oc+2);b++) // percorrendo todas (as 4) camadas >>> 2 camadas ocultas + 2 (1 da entrada e 1 da saída) 
          {
               if(a<(qtd_neu_entrada+(b*qtd_neu_camada_Oc))) // definindo as camdas para cada neurônio
               {
                    RNA[a].camada = b;   // adiciona o valor da camada e...
                    b=(qtd_camada_Oc+2); // sai do segundo for
               }
          }      
     }
}
// FIM INICIALIZAÇÃO DOS CAMPOS

// IMPLEMENTAÇÃO DA FUNÇÃO DE LIGAÇÃO
void Conexao ()
{
          int i, j, cont_camada; // i = índice (posição) do neurônio no vetor (transmissor); j = índice dos neurônios receptores, cont_camada = captura a camada do neurônio atual
          
          for(i=0; i<(qtd_neu_total-qtd_neu_saida); i++)  // percorre todos os neurônios, exceto os da saída, pois não apontam para ninguém
          {
               cont_camada = RNA[i].camada;  
               if(i<qtd_neu_entrada) // no nosso caso, se a posição do neurônio for < 2, ou seja, 0 e 1
                   j=qtd_neu_entrada; // então, j recebe 2 (e vai sendo incrementado no "do while" abaixo) - apontará para a posição 2 até 5
               else if (i<neu_penult_camada) // se a posição do neurônio for < 6 e > 2
                        j = qtd_neu_entrada + (cont_camada*qtd_neu_camada_Oc); // então, j recebe 6 (e vai sendo incrementado no "do while" abaixo) - apontará para a posição 6 até 9  
                    else 
                        j = qtd_neu_total-qtd_neu_saida; // se a posição do neurônio < 10 e > 6, j recebe 10
               int k=-1;  // índice usado em "prox" para ordenar o armazenamento dos endereços dos próximos neurônios
               do
               {      
                    k++;   
                    RNA[i].prox[k] = &RNA[j]; // Ex: o neurônio RNA[3].prox[0] aponta para RNA[6]; RNA[3].prox[1] aponta para RNA[7]... 
                    j++;
               }while (RNA[i].prox[k]->camada == RNA[j].camada);
          }       
} 
// FIM DA FUNÇÃO DE LIGAÇÃO ...........................

// FUNÇÃO DE ATIVAÇÃO QUE GERA O RESULTADO DE UM NEURÔNIO
void Gera_resultado(int r)
{
     int cont = 0;
     float soma = 0;
     float media = 0;     
     for (int g=0; ((g<qtd_ent)&&(RNA[r].entrada[g]!=NULL)); g++) // varre as 10 entradas de um neurônio - se encontrar valor, aplica a f(x)
     {
         soma = soma + (RNA[r].entrada[g] * log(RNA[r].entrada[g]) * RNA[r].peso); // Função de Ativação dada em aula
         cont = cont + 1;
     }
     media = soma/cont;
     RNA[r].valor = media;
}
// FIM DA FUNÇÃO DE ATIVAÇÃO

// FUNÇÃO COMPLEMENTAR PARA ATRIBUIR AS ENTRADAS AOS NEURÔNIOS DE SAÍDA
void Atribue_entrada(int w)
{
     int pos = 0; // índice onde o Neurônio recebedor guardará o "valor" como entrada
     for (int k=0; ((k<qtd_prox)&&(RNA[w].prox[k]!=NULL)); k++)  // índice "k" percorre os campos "prox" 
     {
         if(w<qtd_neu_entrada) // Ex: o "valor" (resultado) do Neurônio de posição "0" será guardado como entrada no índice "0" do Neurônio de posição 2
             pos=w;
         else     
             pos =  RNA[w].posicao - ((RNA[w].camada-1)*qtd_neu_camada_Oc + qtd_neu_entrada);
    
         RNA[w].prox[k]->entrada[pos] = RNA[w].valor;
     }
}
// FIM DA FUNÇÃO COMPLEMENTAR

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
        for(int w=0; w<qtd_neu_entrada; w++) // alimenta as entradas dos neurônios da camada de entrada
        {
            printf("\n\n DIGITE UM VALOR PARA A ENTRADA DO NEURONIO DE POSICAO [%d]: ", w);
            scanf("%f", &vl_ent);
            RNA[w].entrada[0] = vl_ent;
        }   
        
        for(int x=0; x<(qtd_neu_total); x++) // varre todos os neurônios e aplica a Função de Ativação.
        {
            Gera_resultado(x);           
            if (x<(qtd_neu_total-qtd_neu_saida)) // os neurônios 10 e 11 não atribuem seu resultado como entrada a nenhum outro neurônio 
                 Atribue_entrada(x);  
        }    
        
        for(int y=(qtd_neu_total-qtd_neu_saida); y<qtd_neu_total; y++) // imprime os resultados dos neurônios da saída           
            printf("\n\n RESULTADO FINAL DO NEURONIO RNA[%d].VALOR = %2.4f \n\n", (y), RNA[y].valor);       
        
        /*// IMPRESSÃO DOS VALORES DE ENTRADA, PESO E SAÍDA
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
            
        }  // FIM DA IMPRESSÃO   */            
       
        opc=checaop();   
    }while ((opc=='s')||(opc=='S'));       
       
    getchar();    
    getchar();    
}
