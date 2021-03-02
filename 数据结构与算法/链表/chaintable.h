#include <iostream>
#define NIL NULL
typedef struct Node
{
    int data;
    Node *next;
    Node *prev;
} Node;

class ChainTable
{
private:
    /* data */
    Node *nil;

public:
    ChainTable(/* args */);
    ~ChainTable();
    bool ListCreate();
    Node *ListSearch(int data) const;
    bool ListInsert(int data);
    bool ListDelete(int data);
    void ShowChainTable();
};
//生成一个双向链表
ChainTable::ChainTable(/* args */)
{
    nil = nullptr;
    std::cout << "生成一个双向链表！" << std::endl;
}
//双向链表初始化
bool ChainTable::ListCreate()
{
    nil = new Node;
    //判断是否初始化成功
    if (nil == nullptr)
        return false;
    std::cout << "初始化链表成功" << std::endl;
    //哨兵初始化，next和prev均指向自身
    nil->next = nil;
    nil->prev = nil;
    nil->data = NIL;
    return true;
}
//链表查询
Node *ChainTable::ListSearch(int data) const
{ //将一个指针指向链表中的元素
    Node *pointer = nil->next;
    //遍历访问链表中的元素
    while (pointer != nil && pointer->data != data)
    {
        /* code */
        pointer = pointer->next;
    }
    return pointer; //结束后会造成内存泄露，怎么解决
}
//向链表中插入一个元素
bool ChainTable::ListInsert(int data)
{
    Node *node = new Node;
    if (node == nullptr)
        return false;
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
    //node的next指向链表的下一个元素
    node->next = nil->next;
    //待插入元素的后一个元素的next指向带插入元素
    nil->next->prev = node;
    //哨兵的next指向待插入元素
    nil->next = node;
    //待插入元素的prev指向哨兵
    node->prev = nil;
    return true;
}

bool ChainTable::ListDelete(int data)
{
    Node *pointer = ListSearch(data);
    if (pointer->data == NIL)
        return false;
    else
    {
        pointer->prev->next = pointer->next;
        pointer->next->prev = pointer->prev;
        return true;
    }
}
void ChainTable::ShowChainTable()
{
    Node *pointer = nil->next;
    while (pointer != nil)
    {
        /* code */
        std::cout << "data:" << pointer->data << std::endl;
        pointer = pointer->next;
    }
}
ChainTable::~ChainTable()
{
    delete nil;
}
