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

#endif