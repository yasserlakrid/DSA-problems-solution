#include <stdio.h>
#include "linkedList.h"

int main() {
    cell *node;

    allocate(&node);
    assignVal(node, 10);

    printf("%d\n", node->val);

    return 0;
}
