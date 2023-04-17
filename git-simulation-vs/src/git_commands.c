#include <stdio.h>
#include "git_commands.h"

void git_commit(Branch *current_branch, char *message) {
    add_commit(current_branch, message);
}

void git_branch(Branch **branches, char *name) {
    add_branch(branches, name);
}

void git_checkout(Branch **current_branch, Branch *branches, char *name) {
    Branch *found_branch = find_branch(branches, name);
    if (found_branch) {
        *current_branch = found_branch;
    } else {
        printf("Branch not found.\n");
    }
}

void git_merge(Branch *current_branch, Branch *branches, char *name) {
    Branch *found_branch = find_branch(branches, name);
    if (found_branch) {
        printf("Merging branch %s into %s\n", found_branch->name, current_branch->name);
        // Implement the logic for merging branches here
    } else {
        printf("Branch not found.\n");
    }
}
