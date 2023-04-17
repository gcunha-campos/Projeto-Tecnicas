#include <stdlib.h>
#include <string.h>
#include "git_commands.h"

int main() {
    Branch *branches = NULL;
    Branch *current_branch = NULL;

    // Inicializando o branch master
    git_branch(&branches, "master");
    current_branch = branches;

    // Simulando alguns comandos git
    git_commit(current_branch, "Initial commit");
    git_branch(&branches, "feature1");
    git_checkout(&current_branch, branches, "feature1");
    git_commit(current_branch, "Add feature 1");
    git_checkout(&current_branch, branches, "master");
    git_merge(current_branch, branches, "feature1");

    // Adicione mais comandos aqui para testar a simulação

    // Lembre-se de liberar a memória alocada para branches e commits antes de sair do programa

    return 0;
}
