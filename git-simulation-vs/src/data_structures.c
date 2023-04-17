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
