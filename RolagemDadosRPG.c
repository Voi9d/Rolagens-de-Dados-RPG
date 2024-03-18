#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
// Fun��o para rolar um dado de 10 lados
int rolarDado() {
    return rand() % 10 + 1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int numDados, dificuldade;
    int *resultados;
    int numResultadosMaiores = 0;

    // Obter a quantidade de dados e a dificuldade do usu�rio
    printf("Quantos dados de 10 lados voc� quer rolar? ");
    scanf("%d", &numDados);
    printf("Qual � a dificuldade (entre 3 e 10)? ");
    scanf("%d", &dificuldade);

    // Alocar mem�ria para armazenar os resultados
    resultados = (int *)malloc(numDados * sizeof(int));

    // Inicializar a semente para gerar n�meros aleat�rios
    srand(time(NULL));

    // Rolar os dados e armazenar os resultados
    printf("\nResultados dos dados:\n");
    for (int i = 0; i < numDados; i++) {
        resultados[i] = rolarDado();
        printf("Dado %d: %d\n", i + 1, resultados[i]);
        if (resultados[i] >= dificuldade) {
            numResultadosMaiores++;
        } else if (resultados[i] == 1) {
            numResultadosMaiores--;
        }
    }

    // Mostrar os resultados maiores ou iguais � dificuldade (descontando os resultados igual a 1)
    printf("\nResultados maiores ou iguais � dificuldade (%d):\n", dificuldade);
    for (int i = 0; i < numDados; i++) {
        if (resultados[i] >= dificuldade) {
            printf("%d ", resultados[i]);
        }
    }
    printf("\n");

    // Mostrar o resultado final
    printf("\nResultado: %d\n", numResultadosMaiores);

    // Liberar a mem�ria alocada
    free(resultados);

    return 0;
}
