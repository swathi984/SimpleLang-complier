#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    char op;
    struct Node * left, *right;
    char value[1000]
}Node;
void generateAssembly(Node * node){
    if(! node) return;
    if(node -> left) generateAssembly(node->left);
    if(node ->right) generateAssembly(node->right);
    if (node ->op == '=') {
        printf("LOAD %s\n", node -> right -> value);
        printf("STORE %s\n",node -> left -> value);

    }else if(node -> op == '+'){
        printf("ADD %s, %s\n", node -> left -> value , node -> right -> value);

    }else if (node -> op == '-'){
        printf("SUB %s, %s\n",node->left->value, node->right->value);

    }

}