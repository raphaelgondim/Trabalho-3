#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 6
void exercicio6() 
{
    struct Paciente v[MAX], chave;
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        scanf(" %[^\n]", v[i].nome);
        scanf("%d", &v[i].idade);
        scanf("%f", &v[i].peso);
        scanf("%f", &v[i].altura);
    }

    for (i = 1; i < n; i++) 
    {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j].idade > chave.idade) 
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }

    for (i = 0; i < n; i++) 
    {
        float imc = v[i].peso / (v[i].altura * v[i].altura);
        printf("%s - IMC: %.2f\n", v[i].nome, imc);
    }
}

// 7
void exercicio7() 
{
    struct Pedido v[MAX], chave;
    int n, i, j;
    float soma = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &v[i].numeroPedido);
        scanf(" %[^\n]", v[i].nomeCliente);
        scanf("%d", &v[i].data);
        scanf("%f", &v[i].valorTotal);
        soma += v[i].valorTotal;
    }

    for (i = 1; i < n; i++) 
    {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j].data > chave.data) 
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }

    printf("Total: %.2f\n", soma);
}

// 8
void exercicio8() 
{
    struct Atleta v[MAX], chave;
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        scanf(" %[^\n]", v[i].nome);
        scanf(" %[^\n]", v[i].pais);
        scanf(" %[^\n]", v[i].modalidade);
        scanf("%f", &v[i].tempoSegundos);
    }

    for (i = 1; i < n; i++) 
    {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j].tempoSegundos > chave.tempoSegundos) 
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }

    for (i = 0; i < n; i++) 
    {
        printf("%dº %s (dif: %.2f)\n", i+1, v[i].nome,
               v[i].tempoSegundos - v[0].tempoSegundos);
    }
}

// 9 
void exercicio9() 
{
    struct Veiculo v[MAX], chave;
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        scanf("%s", v[i].placa);
        scanf(" %[^\n]", v[i].marca);
        scanf(" %[^\n]", v[i].modelo);
        scanf("%d", &v[i].ano);
        scanf("%f", &v[i].km);
    }

    for (i = 1; i < n; i++) 
    {
        chave = v[i];
        j = i - 1;

        while (j >= 0 &&
              (v[j].ano < chave.ano ||
              (v[j].ano == chave.ano && v[j].km > chave.km))) 
              {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}

//  10 
void exercicio10() 
{
    struct Candidato v[MAX], chave;
    int n = 0, i, j;

    while (1) 
    {
        printf("Nome (ou sair): ");
        scanf(" %[^\n]", chave.nome);

        if (strcmp(chave.nome, "sair") == 0)
            break;

        scanf("%f", &chave.pontuacao);
        scanf("%d", &chave.experienciaAnos);

        i = n - 1;

        while (i >= 0 && v[i].pontuacao < chave.pontuacao) 
        {
            v[i+1] = v[i];
            i--;
        }

        v[i+1] = chave;
        n++;

        printf("\nRanking:\n");
        for (j = 0; j < n; j++) 
        {
            printf("%s - %.2f\n", v[j].nome, v[j].pontuacao);
        }
    }
}

// MAIN
int main() 
{
    int op;

    printf("Escolha (1-10): ");
    scanf("%d", &op);

    switch(op) 
    {
        case 1: exercicio1(); break;
        case 2: exercicio2(); break;
        case 3: exercicio3(); break;
        case 4: exercicio4(); break;
        case 5: exercicio5(); break;
        case 6: exercicio6(); break;
        case 7: exercicio7(); break;
        case 8: exercicio8(); break;
        case 9: exercicio9(); break;
        case 10: exercicio10(); break;
    }

    return 0;
}

