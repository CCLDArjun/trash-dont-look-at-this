#include <printf.h>
#include "TreeMap.h"

int main() {
    TreeMap *map = malloc(sizeof(Node));
    map->key_type = LONG;
    map->value_type = LONG;
    map->comp = NULL;
    map->head = NULL;

    Node *n = TM_set(map, 6, 7);
    Node *e = TM_set(map, 10, 9);
    printf("");
}

