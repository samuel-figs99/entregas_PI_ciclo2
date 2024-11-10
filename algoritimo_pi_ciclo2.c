#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 20
#define MAX_NOME 50

int main() {
    char nomes[MAX_ALUNOS][MAX_NOME];
    int idades[MAX_ALUNOS];
    char turmas[MAX_ALUNOS][MAX_NOME];
    
    int numAlunos = 0;
    int opcao;

    while(1) {
        printf("\n--- Menu da Agenda Escolar ---\n");
        printf("1. Adicionar aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar aluno por nome\n");
        printf("4. Remover aluno\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (numAlunos < MAX_ALUNOS) {
                printf("Digite o nome do aluno: ");
                fgets(nomes[numAlunos], MAX_NOME, stdin);
                nomes[numAlunos][strcspn(nomes[numAlunos], "\n")] = '\0';

                printf("Digite a idade do aluno: ");
                scanf("%d", &idades[numAlunos]);
                getchar();

                printf("Digite a turma do aluno: ");
                fgets(turmas[numAlunos], MAX_NOME, stdin);
                turmas[numAlunos][strcspn(turmas[numAlunos], "\n")] = '\0';

                numAlunos++;
                printf("Aluno adicionado com sucesso!\n");
            } else {
                printf("Agenda cheia! Não é possível adicionar mais alunos.\n");
            }
        } else if (opcao == 2) {
            if (numAlunos == 0) {
                printf("Não há alunos cadastrados.\n");
            } else {
                for (int i = 0; i < numAlunos; i++) {
                    printf("Nome: %s, Idade: %d, Turma: %s\n", nomes[i], idades[i], turmas[i]);
                }
            }
        } else if (opcao == 3) {
            char nomeBusca[MAX_NOME];
            int encontrado = 0;

            printf("Digite o nome do aluno a ser buscado: ");
            fgets(nomeBusca, MAX_NOME, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

            for (int i = 0; i < numAlunos; i++) {
                if (strcmp(nomes[i], nomeBusca) == 0) {
                    printf("Aluno encontrado! Nome: %s, Idade: %d, Turma: %s\n", nomes[i], idades[i], turmas[i]);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) {
                printf("Aluno não encontrado.\n");
            }
        } else if (opcao == 4) {
            char nomeRemover[MAX_NOME];
            int indiceRemover = -1;

            printf("Digite o nome do aluno a ser removido: ");
            fgets(nomeRemover, MAX_NOME, stdin);
            nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

            for (int i = 0; i < numAlunos; i++) {
                if (strcmp(nomes[i], nomeRemover) == 0) {
                    indiceRemover = i;
                    break;
                }
            }

            if (indiceRemover != -1) {
                for (int i = indiceRemover; i < numAlunos - 1; i++) {
                    strcpy(nomes[i], nomes[i + 1]);
                    idades[i] = idades[i + 1];
                    strcpy(turmas[i], turmas[i + 1]);
                }
                numAlunos--;
                printf("Aluno removido com sucesso!\n");
            } else {
                printf("Aluno não encontrado.\n");
            }
        } else if (opcao == 5) {
            printf("Saindo do programa...\n");
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
