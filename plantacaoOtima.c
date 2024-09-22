#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max_profit(int qtndSementes, int *precos, int *valoresVendas, int *tempoPlantarColher, int tempoTotal, int dinheiroDisponivel)
{
    
    int dp[61][1000];


    for (int i = 0; i <= tempoTotal; i++)
    {
        for (int j = 0; j <= dinheiroDisponivel; j++)
        {
            dp[i][j] = 0;
        }
    }

    
    for (int tipoSemente = 1; tipoSemente <= qtndSementes; tipoSemente++)
    {
        int preco = precos[tipoSemente];
        int valorVenda = valoresVendas[tipoSemente];
        int tempo = tempoPlantarColher[tipoSemente];

        
        if (preco <= dinheiroDisponivel)
        {
            
            for (int day = tempoTotal; day >= tempo; day--)
            {
                
                int potential_profit = dp[day - tempo][dinheiroDisponivel - preco] + valorVenda;
                
                dp[day][dinheiroDisponivel] = fmax(dp[day][dinheiroDisponivel], potential_profit);
            }
        }
    }

    return dp[tempoTotal][dinheiroDisponivel];
}

int main()
{
    int casosTeste;
    scanf("%d", &casosTeste);

    for (int casos = 0; casos < casosTeste; casos++)
    {
        int qtndSementes;       
        int tempoTotal;         
        int dinheiroDisponivel; 

        scanf("%d %d %d", &qtndSementes, &tempoTotal, &dinheiroDisponivel);

        
        int *precos = (int *)malloc(sizeof(int) * (qtndSementes + 1));
        
        int *valorVenda = (int *)malloc(sizeof(int) * (qtndSementes + 1));
        
        
        int *tempoPlantarColher = (int *)malloc(sizeof(int) * (qtndSementes + 1));
        
        for (int listas = 0; listas < 3; listas++)
        {
            for (int i = 0; i < qtndSementes; i++)
            {
                if (listas == 0)
                {
                    scanf("%d", &precos[i]);
                }
                else if (listas == 1)
                {
                    scanf("%d", &valorVenda[i]);
                }
                else
                {
                    scanf("%d", &tempoPlantarColher[i]);
                }
            }
        }

        printf("Lucro máximo possível: %d\n", max_profit(qtndSementes, precos, valorVenda, tempoPlantarColher, tempoTotal, dinheiroDisponivel));
    }

    return 0;
}
