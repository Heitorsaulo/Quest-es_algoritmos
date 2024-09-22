#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<unistd.h>

void gerarCasos(){
    srand((unsigned) time(NULL));
    int qtndSementes = rand()%60;  
    int tempoTotal = rand()%60;  
    int dinheiroDisponivel = rand()%1000;
    
    int custo[60];
    int valorVenda[60];
    int tempoPlantarColher[60];
    for(int c = 0; c<qtndSementes; c++){
        custo[c] = (rand()%69)+1;
    }
    for(int c = 0; c<qtndSementes; c++){
        valorVenda[c] = (rand()%139)+1;
        if(custo[c] > valorVenda[c]){
            int aux = valorVenda[c];
            valorVenda[c] = custo[c];
            custo[c] = valorVenda[c];
        }
    }
    for(int c = 0; c<qtndSementes; c++){
        tempoPlantarColher[c] = (rand()%14)+1;
    }

    printf("%d %d %d", qtndSementes, tempoTotal, dinheiroDisponivel);
    printf("\n");
    for(int caso = 0; caso<3; caso++){
        for(int c = 0; c<qtndSementes; c++){
            if(caso == 0){
                printf("%d ", custo[c]);
            }
            else if(caso == 1){
                printf("%d ", valorVenda[c]);
            }
            else{
                printf("%d ", tempoPlantarColher[c]);
            }
        }
        printf("\n");
    }
    sleep(1);
}



int main(){
    srand((unsigned) time(NULL));
    int casos = (rand()%20)+1;
    printf("%d\n", casos);
    for(int i = 0; i<casos;i++){
        gerarCasos();
    }
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SEMENTES 60

typedef struct {
    int qtndSementes;
    int tempoTotal;
    int dinheiroDisponivel;
    int custo[MAX_SEMENTES];
    int valorVenda[MAX_SEMENTES];
    int tempoPlantarColher[MAX_SEMENTES];
} CasoTeste;

bool casoExistente(CasoTeste casos[], int numCasos, CasoTeste novoCaso) {
    for (int i = 0; i < numCasos; i++) {
        if (memcmp(&casos[i], &novoCaso, sizeof(CasoTeste)) == 0) {
            return true; // Caso já existe
        }
    }
    return false; // Caso não existe
}

void gerarCasos(CasoTeste casos[], int numCasos) {
    CasoTeste novoCaso;
    do {
        srand((unsigned)time(NULL));

        novoCaso.qtndSementes = rand() % MAX_SEMENTES;
        novoCaso.tempoTotal = rand() % 60;
        novoCaso.dinheiroDisponivel = rand() % 1000;

        for (int c = 0; c < novoCaso.qtndSementes; c++) {
            novoCaso.custo[c] = (rand() % 69) + 1;
            novoCaso.valorVenda[c] = (rand() % 139) + 1;
            if (novoCaso.custo[c] > novoCaso.valorVenda[c]) {
                int aux = novoCaso.valorVenda[c];
                novoCaso.valorVenda[c] = novoCaso.custo[c];
                novoCaso.custo[c] = aux;
            }
            novoCaso.tempoPlantarColher[c] = (rand() % 14) + 1;
        }
    } while (casoExistente(casos, numCasos, novoCaso));

    // Adiciona o novo caso à lista
    memcpy(&casos[numCasos], &novoCaso, sizeof(CasoTeste));
}

int main() {
    srand((unsigned)time(NULL));
    int numCasos = (rand() % 20) + 1;
    printf("%d\n", numCasos);

    CasoTeste casos[20];
    for (int i = 0; i < numCasos; i++) {
        gerarCasos(casos, i);
        printf("%d %d %d\n", casos[i].qtndSementes, casos[i].tempoTotal, casos[i].dinheiroDisponivel);
        for (int caso = 0; caso < 3; caso++) {
            for (int c = 0; c < casos[i].qtndSementes; c++) {
                if (caso == 0) {
                    printf("%d ", casos[i].custo[c]);
                } else if (caso == 1) {
                    printf("%d ", casos[i].valorVenda[c]);
                } else {
                    printf("%d ", casos[i].tempoPlantarColher[c]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
*/