#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "git_commands.h"

int main() {
    Branch *branches = NULL;
    Branch *current_branch = NULL;    
    // Inicializando o branch master e criando o primeiro commit
    git_branch(&branches, "master");
    current_branch = branches;
    git_commit(current_branch, "First commit");
    int condition = 0;
    char* exit = "exit";
  
    while(condition == 0){
    char *comando = (char*) malloc(60 * sizeof(char));
    char *nome = (char*) malloc(strlen(comando) * sizeof(char));

//recebendo comando do usuario
    printf("$ ");
    gets(comando);  

int size = strlen(comando), i = 0, k = 0, p = 0, h = 0, aux = 0;
      if(comando[0] == '\0')
      {
      continue;
      }
// condicao de parada do while (digitar "exit")
  if(strcmp(comando, exit) == 0 ){
    printf("Saindo...\n\n");
    break;
  }
//funcao para verificar o comando
//retorna um valor inteiro pra identificar o tipo
  p = verifica_git (branches, current_branch, comando, nome,  size);
  if(p == 0){
  printf("Comando Invalido!\n");
  }
  if(p == 1){
  git_log(current_branch);
 }
  else if(p == 2){
  git_commit(current_branch, nome);
 }
  else if(p == 3){
  git_merge(current_branch, branches, nome);
 }
  else if(p == 4){
  git_branch(&branches, nome);
 }
 else if(p == 5){
  git_checkout(&current_branch, branches, nome);
    }
    else { 
      continue;
       }
    }
  free_branches(branches);
  return 0;
}