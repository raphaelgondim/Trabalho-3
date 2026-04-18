#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct Aluno 
{
    char nome[50];
    int matricula;
    float nota;
};

struct Produto 
{
    int codigo;
    char descricao[50];
    float preco;
    int estoque;
};

struct Funcionario 
{
    char nome[50];
    char cargo[50];
    float salario;
};

struct Livro 
{
    char titulo[50];
    char autor[50];
    int ano;
    int paginas;
};

struct Cidade 
{
    char nome[50];
    char estado[3];
    long populacao;
    float area;
};

struct Paciente 
{
    char nome[50];
    int idade;
    float peso;
    float altura;
};

struct Pedido 
{
    int numeroPedido;
    char nomeCliente[50];
    int data;
    float valorTotal;
};

struct Atleta 
{
    char nome[50];
    char pais[50];
    char modalidade[50];
    float tempoSegundos;
};

struct Veiculo 
{
    char placa[20];
    char marca[50];
    char modelo[50];
    int ano;
    float km;
};

struct Candidato 
{
    char nome[50];
    float pontuacao;
    int experienciaAnos;
};


void exercicio1() 
{
    struct Aluno v[MAX], temp;
    int n, i, j;

    scanf("%d", &n);

    for(i=0;i<n;i++) 
    
    {
        scanf(" %[^\n]", v[i].nome);
        scanf("%d", &v[i].matricula);
        scanf("%f", &v[i].nota);
    }

    for(i=0;i<n-1;i++) 
    {
        for(j=0;j<n-i-1;j++) 
        {
            if(v[j].nota < v[j+1].nota) 
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++) 
    {
        printf("%s - %.2f\n", v[i].nome, v[i].nota);
    }
}

void exercicio2() 
{
    struct Produto v[MAX], temp;
    int n, i, j;
    float max;

    scanf("%d", &n);

    for(i=0;i<n;i++) 
    {
        scanf("%d", &v[i].codigo);
        scanf(" %[^\n]", v[i].descricao);
        scanf("%f", &v[i].preco);
        scanf("%d", &v[i].estoque);
    }

    for(i=0;i<n-1;i++) 
    {
        for(j=0;j<n-i-1;j++) 
        {
            if(v[j].preco > v[j+1].preco) 
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    scanf("%f", &max);

    for(i=0;i<n;i++) 
    {
        if(v[i].preco <= max) 
        {
            printf("%s - %.2f\n", v[i].descricao, v[i].preco);
        }
    }
}

void exercicio3() 
{
    struct Funcionario v[MAX], temp;
    int n = 5, i, j;
    float soma = 0, media;

    for(i=0;i<n;i++) 
    {
        scanf(" %[^\n]", v[i].nome);
        scanf(" %[^\n]", v[i].cargo);
        scanf("%f", &v[i].salario);
        soma += v[i].salario;
    }

    media = soma / n;

    for(i=0;i<n-1;i++) 
    {
        for(j=0;j<n-i-1;j++) 
        {
            if(strcmp(v[j].nome, v[j+1].nome) > 0) 
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++) 
    {
        printf("%s - ", v[i].nome);
        if(v[i].salario > media)
            printf("Acima\n");
        else
            printf("Abaixo\n");
    }
}

void exercicio4() 
{
    struct Livro v[MAX], temp;
    int n, i, j, swaps = 0;

    scanf("%d", &n);

    for(i=0;i<n;i++) 
    {
        scanf(" %[^\n]", v[i].titulo);
        scanf(" %[^\n]", v[i].autor);
        scanf("%d", &v[i].ano);
        scanf("%d", &v[i].paginas);
    }

    for(i=0;i<n-1;i++) 
    {
        for(j=0;j<n-i-1;j++) 
        {
            if(v[j].ano > v[j+1].ano) 
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                swaps++;
            }
        }
    }

    for(i=0;i<n;i++) 
    {
        printf("%s - %d\n", v[i].titulo, v[i].ano);
    }

    printf("Trocas: %d\n", swaps);
}

void exercicio5() 
{
    struct Cidade v[MAX], temp;
    int n, i, j, trocou, parada = 0;

    scanf("%d", &n);

    for(i=0;i<n;i++) 
    {
        scanf(" %[^\n]", v[i].nome);
        scanf("%s", v[i].estado);
        scanf("%ld", &v[i].populacao);
        scanf("%f", &v[i].area);
    }

    for(i=0;i<n-1;i++) 
    {
        trocou = 0;

        for(j=0;j<n-i-1;j++) 
        {
            if(v[j].populacao > v[j+1].populacao) 
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                trocou = 1;
            }
        }

        if(trocou == 0) 
        {
            parada = i+1;
            break;
        }
    }

    for(i=0;i<n;i++) 
    {
        printf("%s - %ld\n", v[i].nome, v[i].populacao);
    }

    printf("Parou na passada: %d\n", parada);
}

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

