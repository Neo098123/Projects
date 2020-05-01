

/***************************************************************/
/**                                                           **/
/**   William Abe Fukushima                                   **/
/**   Exerc�cio-Programa 03                                   **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main(){
    int inicio, m, n, z, seed, numero, i, j, count, chutem, chuten, bomban, bombam, perdeu,
     vitoria, noeffect, propaga, propagant, stop, marcadas, livres, primeirochute;
    char modo;
    int A[90][90];
    int B[90][90];

/* Entrada das regras do jogo */

    inicio = 0;
    while (inicio == 0){
        printf("De o numero de linhas do tabuleiro do jogo: ");
        scanf("%d",&m);
        printf("De o numero de colunas do tabuleiro do jogo: ");
        scanf("%d",&n);
        printf("De o numero de minas: ");
        scanf("%d",&z);
        printf("De a semente: ");
        scanf("%d",&seed);
        printf("Numero de linhas (3 <= m <= 90): %d \nNumero de colunas (3 <= n <= 90): %d \nNumero de minas (1 <= z <= %d): %d \nSemente (1 <= s <= 12345): %d \n",m , n, ((m*n)-1), z, seed);
        if (3 <= m && m <= 90 && 3 <= n && n <= 90 && 1 <= z && z <= ((m*n)-1) && 1 <= seed && seed <=12345)
            inicio = 1;
        else
            printf("Digite um valor valido para linhas, colunas e minas \n");
    }

//* Gera��o do tabuleiro *//

    /* Minas: */

    srand(seed);
    for (i=0;i < z; i++) {
        j = -1;
        while(j == -1){

            /* Como o sorteio das posi��es i e j s�o dados por:
            i = numero%m + 1;
            j = (numero/m)%n + 1;
            e a posi��o de (i,j) na matriz � dada por (i-1; j-1), ficamos com: */

            numero = rand();
            bombam = numero%m;
            bomban = (numero/m)%n;
            j = A[bombam][bomban];
            if(j != -1)
                A[bombam][bomban] = -1;
        }
    }

    /* Resto do tabuleiro a partir da posi��o das minas */

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            count = 0;
            if (A[i][j] != -1){
                if (A[i-1][j] == -1) count++;
                if (A[i+1][j] == -1) count++;
                if (A[i][j-1] == -1) count++;
                if (A[i][j+1] == -1) count++;
                if (A[i-1][j-1] == -1) count++;
                if (A[i-1][j+1] == -1) count++;
                if (A[i+1][j-1] == -1) count++;
                if (A[i+1][j+1] == -1) count++;
                A[i][j] = count;
            }
        }
    }

    /* Gera��o da matriz de refer�ncia B que n�o ser� alterada ao longo do jogo e inicalmente � igual a A */

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            B[i][j] = A[i][j];
        }
    }

    /* In�cio do jogo */

    printf("Bem vindo ao caca-minas! \n");
    perdeu = 0;
    noeffect = 0;
    primeirochute = 0;
    while (perdeu != 1 && vitoria != 1){

        /* Verifica��o da condi��o de vit�ria (Todos os espa�os abertos). */
        /* Neste programa, o valor de uma casa [i][j], 0 <= i <= m, 0 < = j <= n, da matriz A pode ser : */
        /* -1 se for uma mina,0 <= k <= 8 se for um espa�o livre, 9 se for uma casa j� aberta e 10 se estiver marcada pelo jogador. */

        vitoria = 1;
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                if((A[i][j] == 9 && (B[i][j] <= 8 && B[i][j] >= 0)) || ((A[i][j] == 10) && (B[i][j] == -1))){
                }
                else
                    vitoria = 0;
            }
        }

        /* C�lculo do n�mero de casas livres e casas marcadas: */

        if(noeffect == 0){
            marcadas = 0;
            livres = 0;
            for(i = 0; i < m; i++){
                for(j = 0; j < n; j++){
                    if (A[i][j] <= 8){
                        livres++;
                    }
                    else if (A[i][j] == 10 ){
                        marcadas++;
                    }
                }
            }

            /* Se for a primeira rodada do jogador, o n�mero de casas livres e marcadas n�o deve ser impresso. */

            if (primeirochute == 1)
                    printf("Por enquanto: %d/%d marcadas, %d livres. \n",marcadas, z, livres);

            /* A situa��o atual do tabuleiro, no entando, deve ser impressa sempre. */

            printf("    ");
            for(j = 0; j < n; j++){
                printf(" %2d", j+1);
            }
            printf("\n");
            printf ("   +-");
            for(j = 0; j < n; j++){
                printf("---");
            }
            printf("+ \n");
            for(i = 0; i < m; i++){
                printf("%2d | ", i+1);
                for(j = 0; j < n; j++){
                    if (A[i][j] <= 8){
                        printf(" . ");
                    }
                    else if (A[i][j] == 10 ){
                        printf(" * ");
                    }
                    else
                        printf(" %d ", B[i][j]);
                }
                printf("|%2d \n", i+1);
            }
            printf ("   +-");
            for(j = 0; j < n; j++){
                printf("---");
            }
            printf("+ \n");
            printf("    ");
            for(j = 0; j < n; j++){
                printf(" %2d", j+1);
            }

            /* Se o jogador tiver vencido, n�o far� outro chute */

            if (vitoria != 1)
                printf("\nProximo chute: ");
        }

        /* Se a jogada feita n�o executar altera��oes no tabuleiro, n�o � necess�rio a impress�o do tabuleiro. */
        else {
            noeffect = 0;
            printf("Proximo chute: ");
        }
        /* Vit�ria!!! */

        if(vitoria == 1)
            printf("\nVoce venceu!");

        /* Se o jogador n�o tiver vencido, far� um novo chute */

        else{
            scanf(" %c %d %d", &modo, &chutem, &chuten);
            primeirochute = 1;

            /* O chute feito pode ser: A (abertura de uma posi��o); M (marca��o de uma provavel bomba); D (desmarca��o). */

            if (modo == 'a' || modo == 'A'){

                /* Abrindo-se uma mina (derrota): */

                if ( A[chutem - 1][chuten - 1] == -1){
                    printf("BOOOOM!  Voce acaba de pisar numa mina! \n");
                    printf("    ");

                    /* impress�o do tabuleiro-resposta. */

                    for(j = 0; j < n; j++){
                        printf(" %2d", j+1);
                    }
                    printf("\n");
                    printf ("   +-");
                    for(j = 0; j < n; j++){
                        printf("---");
                    }
                    printf("+ \n");
                    for(i = 0; i < m; i++){
                        printf("%2d | ", i+1);
                        for(j = 0; j < n; j++){
                            if (B[i][j] > -1)
                                printf(" %d ",B[i][j]);
                            else
                                printf(" @ ");
                        }
                        printf("|%2d \n", i+1);
                    }
                    printf ("   +-");
                    for(j = 0; j < n; j++){
                        printf("---");
                    }
                    printf("+ \n");
                    printf("    ");
                    for(j = 0; j < n; j++){
                        printf(" %2d", j+1);
                    }
                    printf("\n");
                    perdeu = 1;
                }

                /* Caso o jogador tente abrir uma casa marcada ou j� aberta, n�o far� altera��o nenhuma. */

                else if (A[chutem - 1][chuten - 1] == 9 || A[chutem - 1][chuten - 1] == 10){
                    printf("Sem efeito \n");
                    noeffect = 1;
                }

                /* Se a casa for um espa�o de valor 0 <= k <= 8, esta casa ser� aberta. */
                else
                    A[chutem - 1][chuten - 1] = 9;
            }
            else if (modo == 'm' || modo == 'M'){

                /* A casa em quest�o s� sera marcada se esta n�o tiver sido aberta e nem j� marcada.
                Do contr�rio, a tentativa de marca��o n�o far� efeito algum sobre o tabuleiro. */

                if(A[chutem - 1][chuten - 1] < 9 )
                    A[chutem - 1][chuten - 1] = 10;
                else{
                    printf("Sem efeito \n");
                    noeffect = 1;
                }
            }
            else if (modo == 'd' || modo == 'D'){

                /* A casa em quest�o s� poder� ser desmarcada se esta estiver marcada.
                Do contr�rio, a tentativa de desmarca��o n�o far� efeito algum sobre o tabuleiro. */

                if (A[chutem - 1][chuten - 1] == 10)
                    A[chutem - 1][chuten - 1] = B[chutem - 1][chuten - 1];
                else{
                    printf("Sem efeito \n");
                    noeffect = 1;
                }
            }

            /* Ao final das altera��es feitas pelo jogador, o tabuleiro ser� verificado e quaisquer casas que
            tenham o valor original como 0 e estiverem abertas devem abrir seus vizinhos tamb�m. */

            propagant = 0;
            stop = 1;

            /* � aberto um la�o que s� se encerra quando a quantidade de vezes que as casas s�o abertas
            � igual � da itera��o anterior. */

            while(stop != 0){
                propaga = 0;
                for (i=0; i<m; i++){
                    for (j=0; j<n; j++){
                        if(A[i][j] == 9 && B[i][j] == 0){
                            A[i-1][j] = 9;
                            A[i+1][j] = 9;
                            A[i][j-1] = 9;
                            A[i][j+1] = 9;
                            A[i-1][j-1] = 9;
                            A[i-1][j+1] = 9;
                            A[i+1][j-1] = 9;
                            A[i+1][j+1] = 9;
                            propaga++;
                        }
                    }
                }
                stop = propaga - propagant;
                propagant = propaga;
            }
        }
    }
    return 0;
}
