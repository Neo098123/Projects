

/***************************************************************/
/**                                                           **/
/**   William Abe Fukushima                                   **/
/**   Exerc�cio-Programa 02                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <time.h>

/* Função de delay */

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds);

} 


/* Definindo a fun��o raiz c�bica: */

double raizCubica(double d) {
    double b, a, erro;
    a = d;
    erro = 0.00000001;
    while (erro >= 0.00000001){
        a = (2*a + d/(a*a))/3;
        erro = a - b;
        if (erro < 0)
            erro = -erro;
        b = a;
    }
    return a;
}

/* Definindo a fun��o floor (ch�o): */

int chao(double m){
    int p;
    p = 0;
    while (p < m) {
        p = p + 1;
    }
    if (p > m)
        p = p - 1;
    return p;
}

/* Definindo a fun��o de Nova Caixa: */

double novaCaixa(double c){
    double r;
    r = 9821.0 * raizCubica(c) + 0.211327;
    c = r - chao(r);
    return c;
}

/* Programa principal: */

int main(){
    int seed, carta, contadora, contadorb, vitoria, h, i;
    double caixa, pontosa, pontosb, aposta, ganho, dinheiro;
    char hit, end;
    int stop = 0;

    /* A vari�vel seed representa a semente utilizada para se rodar o progragama; contadora e contadorb
    s�o respectivamente o n�mero de cartas compradas pelo apostador e pela banca; pontosa e pontosb s�o
    o n�mero de pontos feitos respectivamente pelo apostador e pela banca; h e i s�o contadores utilizados em la�os;
    derrotas � o n�mero de vezes que a banca perde */

    /* Colocando o ponto na frente do n�mero escolhido como semente: */

    printf("Entre com uma semente para o programa:");
    scanf("%d", &seed);
    printf("\n");

    caixa = seed;
    while (seed != 0){
        seed = seed/10;
        caixa = caixa/10;
    }
         dinheiro = 200;

         while(dinheiro > 0){
            
            printf("Saldo: %lf \n", dinheiro);
            printf("Entre com um valor de aposta:");
            scanf("%lf", &aposta);
            printf("\nSeu Turno:\n");


            while(aposta > dinheiro){
                printf("Valor de aposta inválido.\n");
                printf("Entre com um valor de aposta:");
                scanf("%lf", &aposta);
                printf("\n");
            }
            /* Zerando as pontua��es e marcadores: */

            vitoria = 0;
            contadora = 0;
            contadorb = 0;
            pontosa = 0;
            pontosb = 0;
            ganho = -(aposta);

            /* vez do apostador: */

            /* Compra de cartas (apostador) : */


            hit = 'a';
            carta = chao(caixa*10 + 1);
            if (carta > 7)
            pontosa = pontosa + 0.5;
            else
                pontosa = pontosa + carta;
            caixa = novaCaixa(caixa);
            contadora++;
            printf("pontos: %2f \n", pontosa);

            while(hit != 's' && pontosa <= 7.5){
                printf("Mais uma carta? h (hit) / s (stop) :");
                scanf(" %c", &hit);
                if(hit == 'h'){
                    carta = chao(caixa*10 + 1);
                    if (carta > 7)
                        pontosa = pontosa + 0.5;
                    else
                        pontosa = pontosa + carta;
                    caixa = novaCaixa(caixa);
                    contadora++;
                    printf("total: %2f \n", pontosa);
                }
            }

            if(pontosa > 7.5){
                delay(700);
                printf("Estourou!! \n");
                delay(700);
            }
            
            /* Vez da banca */

            if (pontosa <= 7.5){
                printf("\nTurno da banca:\n");

                while (pontosb < pontosa){

                    /* Compra de cartas: */

                    carta = chao(caixa*10 + 1);
                    if (carta > 7)
                        pontosb = pontosb + 0.5;
                    else
                        pontosb = pontosb + carta;
                    caixa = novaCaixa(caixa);
                    contadorb++;
                    
                    printf("pontos (banca): %2f\n", pontosb);
                    delay(700);

                }

                /* Casos de derrota da banca: */

                /* "Estourou":*/

                if (pontosb > 7.5){
                    ganho = aposta;
                    printf("Voce Venceu!");
                    vitoria = 1;
                }

                /* Fez tantos pontos quanto o apostador, mas comprou mais cartas: */

                if ((pontosb == pontosa)&&(contadora < contadorb)){
                    if(pontosb < 7.5){

                        /* Compra de cartas (�ltima tentativa de ultrapassar a pontua��o): */

                        carta = chao(caixa*10 + 1);
                        if (carta > 7)
                            pontosb = pontosb + 0.5;
                        else
                            pontosb = pontosb + carta;
                        caixa = novaCaixa(caixa);
                        contadorb++;
                        printf("pontos (banca): %2f\n", pontosb);
                        delay(700);

                        /* "Estourou": */
                        if ( pontosb > 7.5){
                            ganho = aposta;
                            printf("Voce Venceu!");
                            vitoria = 1;
                        }
                    }  
                    /* N�o existe possibilidade de vit�ria: */

                    else if (pontosb == 7.5){
                        ganho = aposta;
                        printf("Voce Venceu!");
                        vitoria = 1;

                    }
                }
            }
            dinheiro += ganho;
            if(vitoria==0){
                printf("Voce Perdeu.");
            }
            printf("\n");

        }
    printf("Não há mais saldo disponível.\n");
    delay(2000);
    return 0;
}

