

/***************************************************************/
/**                                                           **/
/**   William Abe Fukushima                                   **/
/**   Exerc�cio-Programa 02                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>

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
    int seed, carta, contadora, contadorb, asteriscos, h, i;
    double caixa, pontosa, pontosb, teto, derrotas;

    /* A vari�vel seed representa a semente utilizada para se rodar o progragama; contadora e contadorb
    s�o respectivamente o n�mero de cartas compradas pelo apostador e pela banca; pontosa e pontosb s�o
    o n�mero de pontos feitos respectivamente pelo apostador e pela banca; h e i s�o contadores utilizados em la�os;
    derrotas � o n�mero de vezes que a banca perde */

    /* Colocando o ponto na frente do n�mero escolhido como semente: */

    printf("Entre com uma semente para o programa:");
    scanf("%d", &seed);
    caixa = seed;
    while (seed != 0){
        seed = seed/10;
        caixa = caixa/10;
    }

    teto = 0.5;

    /* Iniciando o la�o para cada valor de teto: */

    while (teto <= 7.5){
        derrotas = 0;

        /* Iniciando o la�o das 10000 partidas: */

        for(i = 0; i < 10000; i++){

            /* Zerando as pontua��es e marcadores: */

            contadora = 0;
            contadorb = 0;
            pontosa = 0;
            pontosb = 0;

            /* vez do apostador: */

            while (pontosa < teto){

                /* Compra de cartas (apostador) : */

                carta = chao(caixa*10 + 1);
                if (carta > 7)
                    pontosa = pontosa + 0.5;
                else
                    pontosa = pontosa + carta;
                caixa = novaCaixa(caixa);
                contadora++;
            }

            /* Vez da banca */

            if (pontosa <= 7.5){
                while (pontosb < pontosa){

                    /* Compra de cartas: */

                    carta = chao(caixa*10 + 1);
                    if (carta > 7)
                        pontosb = pontosb + 0.5;
                    else
                        pontosb = pontosb + carta;
                    caixa = novaCaixa(caixa);
                    contadorb++;

                }

                /* Casos de derrota da banca: */

                /* "Estourou":*/

                if (pontosb > 7.5)
                    derrotas++;

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

                        /* "Estourou": */

                        if ( pontosb > 7.5){
                            derrotas++;
                        }

                    /* N�o existe possibilidade de vit�ria: */

                    else if (pontosb == 7.5)
                        derrotas++;
                    }
                }
            }
        }

        /* Fim das 10000 partidas */

        printf("%.1lf %.0lf ", teto, derrotas);
        asteriscos = chao(100*(derrotas/10000) + 0.5);
        for (h = 0; h < asteriscos; h++){
            printf("*");
        }
        printf("\n");

        /* Pr�ximo teto: */

        teto = teto + 0.5;
    }
    /* Fim da simula��o */
    return 0;
}

