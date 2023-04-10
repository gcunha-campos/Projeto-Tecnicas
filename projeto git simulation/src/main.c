#include <stdio.h>
#include <string.h>
#include "git_commands.h"
#include "data_structures.h"

int main() {
    char input[100];
    Branch *branches = NULL;
    Branch *current_branch = NULL;

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Remover a quebra de linha

        if (strncmp(input, "git commit -m ", 14) == 0) {
            git_commit(current_branch, input + 14);
        } else if (strncmp(input, "git branch ", 11) == 0) {
            git_branch(&branches, input + 11);
        } else if (strncmp(input, "git checkout ", 13) == 0) {
            git_checkout(&current_branch, branches, input + 13);
        } else if (strncmp(input, "git merge ", 10) == 0) {
            git_merge(current_branch, branches, input + 10);
        } else {
            printf("Comando não reconhecido: %s\n", input);
        }
    }

    return 0;
}
