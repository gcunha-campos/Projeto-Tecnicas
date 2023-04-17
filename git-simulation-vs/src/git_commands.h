#ifndef GIT_COMMANDS_H
#define GIT_COMMANDS_H

typedef struct Branch {
    char *name;
    struct Commit *commits;
    struct Branch *next;
} Branch;

void git_commit(Branch *current_branch, char *message);
void git_branch(Branch **branches, char *name);
void git_checkout(Branch **current_branch, Branch *branches, char *name);
void git_merge(Branch *current_branch, Branch *branches, char *name);

#endif // GIT_COMMANDS_H