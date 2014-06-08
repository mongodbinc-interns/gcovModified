#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    struct Node *next;
    struct Node *last;
    struct Node *first;

    char *key;
    void *value;
    char *type;
};

struct List {
    struct Node *front;
};

void deleteList(struct List *);
void initList (struct List *list) {
    list->front = NULL;
}

int isEmptyList (struct List *list) {
    return list->front == NULL;
}

void addToList (struct List *list, char *key, void *value, char *type) {
    struct Node *newNode = malloc(sizeof(struct Node));
   
    if (isEmptyList(list)) {
        list->front = newNode; 
        list->front->first = list->front;
        list->front->last = list->front;
        list->front->next = NULL;
    }

    else {
        struct Node *last = list->front->last;
        last->next = newNode;
        list->front->last = newNode;
    }

    newNode->key = key;
    newNode->value = value;
    newNode->type = type;
}
static void deleteNode (struct Node *node) {
    int proceed = 1;
    struct Node *next = node->next;
    printf("%s\n", node->type);
    
    if (node == node->last) {
        proceed = 0;
    }

    if (strcmp(node->type, "list") == 0) {
        deleteList((struct List *) node->value);
    }

    else {
        printf("about to delete %s\n", node->type);
        free(node);
        printf("deleted from list\n");
    }

    if (proceed) {
        deleteNode(next);
    }
}
        
void deleteList (struct List *list) {
    deleteNode (list->front);
}


int main() {
     struct List list;
    initList(&list);
    addToList(&list, "h", "1", "int");
    struct List sublist;
    initList(&sublist);
    addToList(&sublist, "hello", "lala", "string");
    addToList(&list, "yo", &sublist, "list");
    addToList(&list, "well", "huh?", "string");
    printf("%s\n", (char *) list.front->value);
    struct Node *next = (list.front)->next;
    printf("%s\n", next->type);
    printf("%s\n", (char *) next->next->value);
    printf("%s\n", (char *) (list).front->last->value);

    deleteList(&list);
  return 0;
} 


