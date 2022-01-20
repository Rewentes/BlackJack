#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
  char suit[20];
  char name[20];
  int value;
  struct Node *next;
} Node;

void push(Node **head, char suit_in[20], char name_in[20], int value_in) { // добавление в конец
    Node *tmp = (Node*) malloc(sizeof(Node));
    for (int i = 0; i < 20; i++) {
      tmp->suit[i] = suit_in[i];
      tmp->name[i] = name_in[i];
      tmp->value = value_in;
    }
    tmp->next = (*head);
    (*head) = tmp;
}

Node pop(Node **head) { // удаление с начала
    Node *prev = NULL;

    if (head == NULL) {
        exit(-1);
    }

    prev = (*head);
    (*head) = (*head)->next;

    return *prev;
}

Node* get_N(Node* head, int n) { // нахождение n-го элемента списка, перебором всех элементов.
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

Node delete_N(Node **head, int n) { //удаление по индексу
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = get_N(*head, n-1);
        Node *elm  = prev->next;
        prev->next = elm->next;
        return *elm;
    }
}

Node *LAST_element(Node *head) { // нахождение последнего элемента перебором друг за другом элементов до тех пор, пока указатель next одного из элементов != NULL
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
} 

void pushBack(Node *head, char suit_in[20], char name_in[20], int value_in) { // добавление в начало
    Node *last = LAST_element(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    for (int i = 0; i < 20; i++) {
        tmp->suit[i] = suit_in[i];
        tmp->name[i] = name_in[i];
        tmp->value = value_in;
    }

    tmp->next = NULL;
    last->next = tmp;
} 

//[new] -> [] -> [] -> NULL

void insert(Node *head, unsigned n, char suit_in[20], char name_in[20], int value_in) {
    unsigned i = 0;
    Node *tmp = NULL;
  
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));

    for (int i = 0; i < 20; i++) {
        tmp->suit[i] = suit_in[i];
        tmp->name[i] = name_in[i];
        tmp->value = value_in;
    }
    
    if (head->next) {
        tmp->next = head->next;
    
    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}
// [head] -> [2, next] -> [3, next] -> NULL

void tusov(Node **head){
    for (int i = 0; i < 100; i++) {
        Node del = delete_N(head, (rand()%52));
        //push(head, del.suit, del.name);
        insert(*head, rand()%52, del.suit, del.name, del.value);
    }
}

void printList(const Node *head) {
    while(head) {
        printf("%d ", head->value);
        printf("%s ", head->name);
        printf("%s ", head->suit);
        head = head->next;
        printf("\n");
  } 
  printf("\n");
}



