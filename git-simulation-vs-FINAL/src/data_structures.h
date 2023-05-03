#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H


typedef struct Commit {
    char *message;
    struct Commit *next;
} Commit;

typedef struct Branch {
    char *name;
    Commit *commits;
    struct Branch *next;
} Branch;

Commit *create_commit(char *message);
Branch *create_branch(char *name);
void add_commit(Branch *branch, char *message);
Branch *find_branch(Branch *branches, char *name);
void add_branch(Branch **branches, char *name);
void print_commits(Branch *branch);
void free_commits(Commit *commits);
void free_branches(Branch *branches);
void recebe_nome(char* vetor_comando, char* vetor_nome, int tamanho, int n);
int verifica_git ( Branch *branches, Branch *current_branch, char *message, char* nome, int tamanho);
int verfica_comando(Branch *branches, Branch *current_branch, char* message, char* nome, char* vetor, int tamanho, int i);
int ignora_espaco(char* vetor, int i);

#endif