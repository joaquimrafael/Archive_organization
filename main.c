//Trabalho 1: Organizando as turmas do professor Charles.

/*
* Faculdade de Computação e Informática
* Ciência da Computação
* Projeto e Analise de Algoritmos – 3ª etapa – 2023.2
* Professor Leonardo Massayuki Takuno
*
* Lucas Trebacchetti Eiras - 32236905
* Joaquim Rafael Mariano Prieto Pereira - 42201731
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  float nota;
  char semestre[2];
  char nome[100];
  char disciplina[100];
  char periodo[2];
  char turma[2];
} Aluno;

void ordenaAlunosString(int min, int max, Aluno alunos[], char opc[]);
void printarMenu();

int main(void) {
  FILE *entrada;
  FILE *saida;
  entrada = fopen("entrada.csv","r");
  saida = fopen("saida.csv","w");

  if(entrada == NULL){
    printf("Erro ao abrir o arquivo!");
    return(1);
  }

  Aluno estudantes[1000];
  int count = 0;

  while(fscanf(entrada, "%3[^,],%2[^,],%2[^,],%99[^,],%99[^,],%f\n", estudantes[count].semestre, estudantes[count].turma, estudantes[count].periodo, estudantes[count].nome, estudantes[count].disciplina, &estudantes[count].nota) != EOF) {
    count++;
  }

  printarMenu(); // Chama o menu para permitir que o usuário escolha a opção de ordenação.

  int escolha;
  scanf("%d", &escolha);

  int min=0;
  int max=0;
  switch (escolha) {
    case 1:
      ordenaAlunosString(0, count, estudantes, "nome");
      printf("\nO arquivo foi ordenado por nome...\n");
      break;
    
    case 2:
      ordenaAlunosString(0, count, estudantes, "semestre");
      printf("\nO arquivo foi ordenado por semestre...\n");
      break;

    case 3:
      ordenaAlunosString(0, count, estudantes, "nome");
      ordenaAlunosString(0, count, estudantes, "disciplina");
      ordenaAlunosString(0, count, estudantes, "periodo");
      ordenaAlunosString(0, count, estudantes, "turma");
      ordenaAlunosString(0, count, estudantes, "semestre");
      printf("\nO arquivo foi ordenado por semestre, turma, período, disciplina e nome \n");
    break;


    case 4:
      ordenaAlunosString(0, count, estudantes, "nota");
      ordenaAlunosString(0, count, estudantes, "disciplina");
      printf("\nO arquivo foi ordenado por disciplina e media final(decrescente) \n");
      break;

    case 5:
      ordenaAlunosString(0, count, estudantes, "nome");
      ordenaAlunosString(0, count, estudantes, "disciplina");
      ordenaAlunosString(0, count, estudantes, "turma");
      ordenaAlunosString(0, count, estudantes, "semestre");
      ordenaAlunosString(0, count, estudantes, "periodo");

      printf("\nO arquivo foi ordenado por período,semestre, turma, disciplina e nome \n");
      break;
    case 6:
      printf("\nSaindo...\n");
      return 0;
    default:
      printf("Opção inválida!\n");
      return 1;
  }
	
	int i;
  for (i=0;i<count;i++) {
  
 fprintf(saida,"%s,%s,%s,%s,%s,%.2f\n",estudantes[i].semestre,estudantes[i].turma,estudantes[i].periodo,estudantes[i].nome,estudantes[i].disciplina,estudantes[i].nota);
}

  fclose(entrada);
  fclose(saida);

  return 0;
}

void ordenaAlunosString(int min, int max, Aluno alunos[], char opc[]) {
	int i, j;
    for(i=min; i<max-1; i++) {
        for(j=min; j<max-i-1; j++) {
          if(strcmp(opc, "nome")==0){
            if(strcmp(alunos[j].nome, alunos[j+1].nome)>0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
          }
          if(strcmp(opc, "nota")==0){
            if(alunos[j].nota <= alunos[j+1].nota) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
          }
          if(strcmp(opc, "semestre")==0){
            if(strcmp(alunos[j].semestre, alunos[j+1].semestre)>0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
          }
          if(strcmp(opc, "disciplina")==0){
            if(strcmp(alunos[j].disciplina, alunos[j+1].disciplina)>0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
          }
          if(strcmp(opc, "periodo")==0){
            if(strcmp(alunos[j].periodo, alunos[j+1].periodo)>0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
          }
          if(strcmp(opc, "turma")==0){
            if(strcmp(alunos[j].turma, alunos[j+1].turma)>0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
          }
        }
    }
}




void printarMenu() {
  printf("--Programa de Organização de turmas!--\n");
  printf("Escolha o método de ordenação e digite o número correspondente:\n");
  printf("1. Ordenar por nome\n");
  printf("2. Ordenar por semestre\n");
  printf("3. Ordenar por semestre, turma, período, disciplina e nome\n");
  printf("4. Ordenar por disciplina e média final (decrescente)\n");
  printf("5. Ordenar por período, semestre, turma, disciplina e nome\n");
  printf("6. Sair\n");
}
