#ifndef GIT_COMMANDS_H
#define GIT_COMMANDS_H

#include "data_structures.h"

void git_commit(Branch *current_branch, char *message);
void git_branch(Branch **branches, char *name);
void git_checkout(Branch **current_branch, Branch *branches, char *name);
void git_merge(Branch *current_branch, Branch *branches, char *name);
void git_log(Branch *current_branch);

#endif
