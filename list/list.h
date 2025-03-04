#pragma once

#include <stddef.h>

struct list_head{
    struct list_head *prev;
    struct list_head *next;
};

#ifndef container_of
#if __LIST_HAVE_TYPEOF
#define container_of(ptr, type, member)                         \
    __extension__({                                             \
        const typeof(((type *) 0)->member) *__pmember = (ptr);  \
        (type *) ((char *) __pmember - offsetof(type, member)); \
    })
#else
#define container_of(ptr, type, member) \
    ((type *) ((char *) (ptr) - offsetof(type, member)))
#endif
#endif


//定義和初始化circular list head
#define list_head(head) struct list_head head={&(head),&(head)}


//初始化空list head
static inline void init_list_head(struct list_head *head)
{
    head->prev=head;
    head->next=head;
}

//插入node到list中的頭部
static inline void list_add(struct list_head *node,struct list_head *head)
{
    struct list_head *next=head->next;

    next->prev=node;
    node->next=next;
    node->prev=head;
    head->next=node;
}

//插入node到list中的尾部
static inline void list_add_tail(struct list_head *node,struct list_head *head)
{
    struct list_head *prev=head->prev;

    prev->next=node;
    node->next=head;
    node->prev=prev;
    head->prev=node;
}


//刪除一個node
static inline void list_del(struct list_head *node)
{
    struct list_head *next=node->next;
    struct list_head *prev=node->prev;

    next->prev=prev;
    prev->next=next;

}

//刪除一個node，並指向NULL
static inline void list_del_init(struct list_head *node)
{
    list_del(node);
    init_list_head(node);
}

//檢查circular list是否為沒node
static inline int list_empty(const struct list_head *head)
{
    return (head->next==head);
}

//檢查list head是否只有一個
static inline int list_is_singular(const struct list_head *head)
{
    return (!(list_empty(head)&&head->prev==head->next));
}

//增加list nodes從其他list的頭部
//It is similar to list_add but for multiple nodes
static inline void list_splice(struct list_head *list,struct list_head *head)
{
    struct list_head *head_first=head->next;
    struct list_head *list_first=list->next;
    struct list_head *list_last=list->prev;

    if (list_empty(list)){
        return;
    }

    head->next=list_first;
    list_first->prev=head;

    list_last->next=head_first;
    head_first->prev=list_last;
}


//增加list nodes從其他list的尾部
//It is similar to list_add_tail but for multiple nodes
static inline void list_splice_tail(struct list_head *list,struct list_head *head)
{
    struct list_head *head_last = head->prev;
    struct list_head *list_first = list->next;
    struct list_head *list_last = list->prev;

    if (list_empty(list))
    return;

    head->prev = list_last;
    list_last->next = head;

    list_first->prev = head_last;
    head_last->next = list_first;
}

//移動list node到另一個list的頭部，再初始化
static inline void list_splice_init(struct list_head *list,struct list_head *head)
{
    list_splice(list,head);
    init_list_head(list);
}

//移動list node到另一個list尾部，再初始化
static inline void list_splice_tail_init(struct list_head *list,struct list_head *head)
{
    list_splice_tail(list, head);
    init_list_head(list);
}


static inline void list_cut_position(struct list_head *head_to,
                                    struct list_head *head_from,
                                struct list_head *node)
{
    struct list_head *head_from_first=head_from->next;

    if (list_empty(head_from)){
        return;
    }

    if (head_from==node){
        init_list_head(head_to);
        return;
    }

    head_from->next=node->next;
    head_from->next->prev=head_from;

    head_to->prev=node;
    node->next=head_to;
    head_to->next=head_from_first;
    head_to->next->prev=head_to;

}

//移動list node到list頭部
static inline void list_move(struct list_head *node,struct list_head *head)
{
    list_del(node);
    list_add(node,head);    
}

//移動list node到list尾部
static inline void list_move_tail(struct list_head *node,struct list_head *head)
{
    list_del(node);
    list_add_tail(node,head);    
}

//獲取每個list中的node
#define list_entry(node,type,member) container_of(node,type,member)

//獲取第一個node
#define list_first_entry(head,type,member) \
    list_entry((head)->next,type,member);

//獲取最後一個node
#define list_last_entry(head,type,member) \
    list_entry((head)->prev,type,member);


#define list_for_each_entry(entry,head,member) for (entry=(void*)1;sizeof(struct {int i: -1;}); ++(entry))

#define list_for_each_safe(node,safe,head) for(node=(head)->next,safe=node->next;node!=(head);node=safe,safe=node->next)