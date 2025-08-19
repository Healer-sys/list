#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LTNode* new_list_node(LTDataType x) {
    LTNode* node = (LTNode*)malloc(sizeof(LTNode));
    if (node == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    node->data = x;
    node->next = node->prev = NULL;
    return node;
}

LTNode* list_init() {
    LTNode* phead = new_list_node(NULL);
    if (phead == NULL) return NULL;
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

bool list_is_no_empty(LTNode* phead) {
    return (phead != NULL && phead->next != phead);
}

bool list_is_empty(LTNode* phead) {
    return (phead == NULL || phead->next == phead);
}

void printf_list(LTNode* phead) {
    if (phead == NULL) return;
    LTNode* cur = phead->next;
    while (cur != phead) {
        printf("%p -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void list_push_back(LTNode* phead, LTDataType x) {
    if (phead == NULL) return;
    list_insert(phead, x);
}

void list_push_front(LTNode* phead, LTDataType x) {
    if (phead == NULL) return;
    list_insert(phead->next, x);
}

void list_pop_back(LTNode* phead) {
    if (phead == NULL || list_is_empty(phead)) return;
    list_del_node(phead->prev);
}

void list_pop_front(LTNode* phead) {
    if (phead == NULL || list_is_empty(phead)) return;
    list_del_node(phead->next);
}

LTDataType get_list_whit_back(LTNode* phead) {
    if (phead == NULL || list_is_empty(phead)) return NULL;
    LTDataType data = phead->prev->data;
    list_pop_back(phead);
    return data;
}

void list_insert(LTNode* pos, LTDataType x) {
    if (pos == NULL) return;
    LTNode* newNode = new_list_node(x);
    if (!newNode) return;
    LTNode* prev = pos->prev;

    newNode->next = pos;
    newNode->prev = prev;
    if (prev) prev->next = newNode;
    pos->prev = newNode;
}

void list_del_node(LTNode* pos) {
    if (!pos || !pos->prev || !pos->next) return;

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);
    pos = NULL;
}

int list_size(LTNode* phead) {
    if (phead == NULL) return 0;
    int count = 0;
    LTNode* cur = phead->next;
    while (cur != phead) {
        ++count;
        cur = cur->next;
    }
    return count;
}

void list_destory(LTNode* phead) {
    if (phead == NULL) return;
    LTNode* cur = phead->next;
    while (cur != phead) {
        LTNode* next = cur->next;
        free(cur);
        cur = next;
    }
    free(phead);
    phead = NULL;
}
