#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"

Commit *create_commit(char *message) {
    Commit *new_commit = (Commit *)malloc(sizeof(Commit));
    new_commit->message = strdup(message);
    new_commit->next = NULL;
    return new_commit;
}

Branch *create_branch(char *name) {
    Branch *new_branch = (Branch *)malloc(sizeof(Branch));
    new_branch->name = strdup(name);
    new_branch->commits = NULL;
    new_branch->next = NULL;
    return new_branch;
}

void add_commit(Branch *branch, char *message) {
    Commit *new_commit = create_commit(message);
    new_commit->next = branch->commits;
    branch->commits = new_commit;
}

Branch *find_branch(Branch *branches, char *name) {
    Branch *current = branches;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_branch(Branch **branches, char *name) {
    Branch *new_branch = create_branch(name);
    new_branch->next = *branches;
    *branches = new_branch;
}

void print_commits(Branch *branch) {
    Commit *current = branch->commits;
  printf("Branch: %s\n", branch->name);
    while (current) {
        printf("%p %s\n", &current->message, current->message);
        current = current->next;
    }   
}

void free_commits(Commit *commits) {
    Commit *current = commits;
    while (current) {
        Commit *next = current->next;
        free(current->message);
        free(current);
        current = next;
    }
}

void free_branches(Branch *branches) {
    Branch *current = branches;
    while (current) {
        Branch *next = current->next;
        free_commits(current->commits);
        free(current->name);
        free(current);
        current = next;
    }
}

void recebe_nome(char* vetor_comando, char* vetor_nome, int tamanho, int n){

        for(int j = 0; n < tamanho; j++, n++){
        vetor_nome[j] = vetor_comando[n];
        }    
}

int ignora_espaco(char* vetor, int i){

while(vetor[i] == ' ' && vetor[i] != '\0')
  {
      i++;  
  }
  return i;
}

int verifica_git (Branch *branches,  Branch *current_branch, char *message, char* nome, int tamanho){

char *vetor = (char*)malloc(tamanho * sizeof(char));
char *vetor2 = (char*)malloc(tamanho * sizeof(char));
int k = 0, i = 0, aux = 0, size;

//ignora espaco (antes de git:      git), retorna indice apos os espacos
k = ignora_espaco(message,  k);

if(message[k] == '\0'){
    return 6;
}
//recebe a primeira palavra do comando (deve ser "git ")
for( i = 0 ; i < 4; i++, k++)
    {
     vetor[i] = message[k];
    }
    if(tamanho < 4 ){
        return 0;
    }
//verifica se digitou de forma correta: 
    if(strcmp(vetor, "git ") == 0){
      
//ignora espaco (depois de git: git       ), retorna indice apos os espacos
        k = ignora_espaco(message,  k);
        i = 0;

//recebe a segunda palavra do comando
while(message[k] != ' ' && message[k] != '\0'){
    vetor2[i] = message[k];  
    i++, k++;
}
//verifica se digitou de forma correta : 
 return verfica_comando(branches, current_branch, message, nome, vetor2,  tamanho, k);
//se digitou errado:
    }else{
      return 0;
    }
}

int verfica_comando(Branch *branches, Branch *current_branch, char* message, char* nome, char* vetor, int tamanho, int i){

  int k = 0;
  char *vetor_aux = (char*)malloc(tamanho * sizeof(char));

  if(strcmp(vetor, "log") == 0 )
      {
      i = ignora_espaco(message,  i);
      if(vetor[i] == '\0'){
      return 1;
      } else {
        return 0;
        }
      }
  else if(strcmp(vetor, "merge") == 0 )  
      { 
      i = ignora_espaco(message,  i);
      recebe_nome (message, nome, tamanho, i);
      return 3;
      }
  else if(strcmp(vetor, "branch") == 0 )  
      { 
      i = ignora_espaco(message,  i);
      recebe_nome (message, nome, tamanho, i);
      if(nome[0] == '\0')
      {
      return 0;
      }
      return 4;
      }
  else if(strcmp(vetor, "checkout") == 0 )
      {
      i = ignora_espaco(message,  i);
      recebe_nome (message, nome, tamanho, i);
      if(nome[0] == '\0')
      {
      return 0;
      }
      return 5;
      }
  else if(strcmp(vetor, "commit") == 0 )  
      { 
      i = ignora_espaco(message,  i);
      while(message[i] != ' ' && message[i] != '\0')
      {
        vetor_aux[k] = message[i];  
        i++, k++;
      } 
      if(strcmp(vetor_aux, "-m") == 0 )
      { 
        i = ignora_espaco(message,  i);
        recebe_nome (message, nome, tamanho, i);
          if(nome[0] == '\0')
      { 
           return 0;
      }
      return 2;
      } else {
     return 0;
      } 
    } 
    else {
    return 0;
  }
}