#pragma once

#include "treenode.h"
#include "vector.h"
#include<limits.h>

#define EMPTY INT_MAX

TreeNode* createTreeFromVector(Vector<int> nums);
void freeTree(TreeNode* root);
bool treeEqual(TreeNode* a, TreeNode *b);
void printTree(TreeNode *root);

