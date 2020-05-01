

/***************************************************************/
/**                                                           **/
/**   William Abe Fukushima                                   **/
/**   Exerc�cio-Programa 01                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
    int i,n,cores,digitos,palpites,senha,pinos,tentativa,x; /*declara�ao das vari�veis*/
    pinos = 0;
    /* leitura das regras do jogo (digitos, cores, palpites e senha)*/
    printf("Entre com o numero de digitos:");
    scanf("%d",&digitos);
    printf("Entre com o numero de cores:");
    scanf("%d",&cores);
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
            printf("4 pretos \n");
            printf("Parabens! Voce descobriu a senha em %d tentativas.",i);
            return 0; /*fim do jogo (objetivo atingido)*/
        }
        else{
            x = senha; /*a vari�vel "x" mant�m o valor da senha enquanto opera��es s�o feitas*/
            for (n=0;n<digitos;n++) /*calculando quantos pinos pretos devem ser colocados*/{
                if (senha%10 == tentativa%10){
                    pinos++;
                    tentativa = tentativa/10;
                    senha = senha/10;
                }
                else {
                    tentativa = tentativa/10;
                    senha = senha/10;
                }
            }
            printf("%d pretos \n",pinos);
            pinos = 0; /*redefinindo o valor dos pinos para o pr�ximo palpite*/
            senha = x; /*redefinindo a senha para o pr�ximo palpite*/
        }
    }
    printf("Sinto muito, mas nenhum dos %d palpites acertaram a senha %d!",palpites,senha);
    return 0; /*fim do jogo (objetivo fracassado)*/
}
