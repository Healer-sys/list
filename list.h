#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef void* LTDataType;

typedef struct ListNode {
    struct ListNode* next;
    struct ListNode* prev;
    LTDataType data;
} LTNode;

LTNode* new_list_node(LTDataType x);
LTNode* list_init();
bool list_is_no_empty(LTNode* phead);
bool list_is_empty(LTNode* phead);
void printf_list(LTNode* phead);
void list_push_back(LTNode* phead, LTDataType x);
void list_push_front(LTNode* phead, LTDataType x);
void list_pop_back(LTNode* phead);
void list_pop_front(LTNode* phead);
LTDataType get_list_whit_back(LTNode* phead);
void list_insert(LTNode* pos, LTDataType x);
void list_del_node(LTNode* pos);
int list_size(LTNode* phead);
void list_destory(LTNode* phead);

#endif /* _LIST_H_ */
