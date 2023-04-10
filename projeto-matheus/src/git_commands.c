#include <stdio.h>
#include "git_commands.h"
#include "data_structures.h"

void git_commit(Branch *current_branch, char *message) {
    add_commit(current_branch, message);
    printf("Commit realizado com sucesso: \"%s\"\n", message);
}

void git_branch(Branch **branches, char *name) {
    add_branch(branches, name);
    printf("Branch criado: %s\n", name);
}

void git_checkout(Branch **current_branch, Branch *branches, char *name) {
    Branch *found_branch = find_branch(branches, name);
    if (found_branch) {
        *current_branch = found_branch;
        printf("Mudado para o branch: %s\n", name);
    } else {
        printf("Branch não encontrado: %s\n", name);
    }
}

void git_merge(Branch *current_branch, Branch *branches, char *name) {
    Branch *found_branch = find_branch(branches, name);
    if (found_branch) {
        // Implemente a lógica de merge conforme o requisito do trabalho
    } else {
        printf("Branch não encontrado: %s\n", name);
    }
}
