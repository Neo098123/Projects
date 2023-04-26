

/***************************************************************/
/**                                                           **/
/**   William Abe Fukushima                                   **/
/**   Exerc�cio-Programa 01                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    int i,n,cores,digitos,palpites,senha,pinosPretos,pinosBrancos,tentativa,x,y,algarismoVerificado,algarismosVerificados,algarismosVerificadosTemp,modo; /*declara�ao das vari�veis*/
    pinosBrancos = 0;
    pinosPretos = 0;
    /* leitura das regras do jogo (digitos, cores, palpites e senha)*/
    printf("Entre com o numero de digitos:");
    scanf("%d",&digitos);
    printf("Entre com o numero de cores:");
    scanf("%d",&cores);
    printf("Entre com o modo (0 = apenas com pinos pretos, 1 = pinos brancos e pretos):");
    scanf("%d",&modo);
    printf("Entre com o numero maximo de palpites:");
    scanf("%d",&palpites);

    printf("Entre com a senha de %d digitos (0 para valor aleatorio):",digitos);
    scanf("%d",&senha);
    if (senha==0) /*sorteio de uma senha aleat�ria*/{
        srand(time(NULL));
        for (i=0;i<digitos;i++){
                senha = senha*10 + (rand()%cores + 1);};
    }
    for (i = 1;i<=palpites;i++) {
        printf("Digite o seu palpite:");
        scanf("%d",&tentativa);
        if (tentativa == senha){
            printf("%d pretos \n", &digitos);
            printf("Parabens! Voce descobriu a senha em %d tentativas.",i);
            return 0; /*fim do jogo (objetivo atingido)*/
        }
        else{
            x = senha; /*a vari�vel "x" mant�m o valor da senha enquanto opera��es s�o feitas*/
            y = tentativa;
            algarismosVerificados = 0;
            for (int counter=0;counter<digitos;counter++) /*calculando quantos pinos brancos devem ser colocados*/{
                senha = x;
                algarismoVerificado = 0;
                algarismosVerificadosTemp = algarismosVerificados;
                for (n=0;n<digitos;n++) /*calculando quantos pinos brancos devem ser colocados*/{
                    if ((senha%10 == tentativa%10 && algarismoVerificado == 0) && algarismosVerificadosTemp%10 == 0){
                        algarismoVerificado = 1;
                        pinosBrancos++;
                        int exp10N = 1;
                        for(int count=0; count < n;count++){
                            exp10N *= 10;
                        }
                        algarismosVerificados += exp10N;
                    }
                    senha = senha/10;
                    algarismosVerificadosTemp /= 10;
                }
                tentativa = tentativa/10;
            }

            senha = x;
            tentativa = y;
            for (n=0;n<digitos;n++) /*calculando quantos pinos pretos devem ser colocados*/{
                if (senha%10 == tentativa%10){
                    pinosPretos++;
                    tentativa = tentativa/10;
                    senha = senha/10;
                }
                else {
                    tentativa = tentativa/10;
                    senha = senha/10;
                }
            }
            if(modo == 1){
                printf("%d brancos \n",pinosBrancos - pinosPretos);
            }
            printf("%d pretos \n",pinosPretos);
            pinosBrancos = 0; /*redefinindo o valor dos pinos para o pr�ximo palpite*/
            pinosPretos = 0; /*redefinindo o valor dos pinos para o pr�ximo palpite*/
            senha = x; /*redefinindo a senha para o pr�ximo palpite*/
        }
    }
    printf("Sinto muito, mas nenhum dos %d palpites acertaram a senha %d!",palpites,senha);
    getch();
    return 0; /*fim do jogo (objetivo fracassado)*/
}
