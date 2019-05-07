#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n,i,j,k;
    scanf("%d", &n);
    double matriz[n][n],coeficiente,determinante=1,vetorN[n], vetorV[n];
    for(i=0; i<n; i++){
        vetorV[i] = i+1;                        //cria o vetor V
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf", &matriz[i][j]);        //Preenche a matriz
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(matriz[i][j]!=0){
                coeficiente = matriz[i][j] / matriz[j][j];
                vetorV[i] -= coeficiente * vetorV[j];
                for(k=0;k<n;k++){                                //Faz escalonamento
                    matriz[i][k] -= coeficiente * matriz[j][k];
                }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("   %.2lf", matriz[i][j]);          // Exibe matriz
        }
        printf("\n");
    }
    for(i=0; i<n; i++){
        determinante *= matriz[i][i];   // Calcula determinante
    }
    printf("Determinante: %.2lf\n", determinante);
    if(determinante){
        printf("Vetores Linearmente Independentes\n");
        for(i=(n-1); i>=0; i--){
            vetorN[i] = vetorV[i] / matriz[i][i];                                    // Acha os valores de A at� An
            if(i!=n-1){
                for(j=1; j<(n-i);j++){
                    vetorN[i] -= (matriz[i][i+j] * vetorN[i+j]) / matriz[i][i];
                }
            }
        }
        printf("Solucao: [ ");
        for(i=0; i<n; i++){
            printf("%.4lf ", vetorN[i]);
        }
        printf("]\n");
    }else{
        printf("Vetores Linearmente Dependentes\n");
    }
    printf("\n");
    return 0;
}
