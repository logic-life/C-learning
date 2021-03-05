#ifdef _LISTNODE_BYPOINTER_HPP_
#include <iostream>

struct ListNode
{
    int value;
    ListNode *next;
};
//添加节点
void addTotail(ListNode *&p_head, int value)
{ //申请一个节点内存
    ListNode *new_node = new ListNode();
    new_node->next = nullptr;
    new_node->value = value;
    //如果没有头结点就创建一个
    if (p_head == nullptr)
        p_head = new_node;
    else
    { //在头结点后添加节点
        ListNode *p_node = p_head;
        for (; p_node->next != nullptr; p_node = p_node->next)
            ;
        p_node->next = new_node;
    }
}
//删除节点
void RemoveNode(ListNode *&p_head, int value)
{ //头结点为空，无需删除
    if (p_head == nullptr)
        return;
    //将待释放指针置为空
    ListNode *p_to_be_deleted = nullptr;
    //判断头结点是否为要删除的节点
    if (p_head->value == value)
    {
        p_to_be_deleted = p_head;
        p_head = p_head->next;
    }
    else
    { //遍历寻找待删除的节点
        ListNode *p_node = p_head;
        while (p_node->next != nullptr && p_node->next->value != value)
        {
            p_node = p_node->next;
        }
        if (p_node->next != nullptr && p_node->next->value == value)
        {
            p_to_be_deleted = p_node->next;
            p_node->next = p_node->next->next;
        }
    }
    if (p_to_be_deleted != nullptr)
    {
        delete p_to_be_deleted;
        p_to_be_deleted = nullptr;
    }
}
//打印节点
void ListPrintf(ListNode *&p_head)
{
    ListNode *p_node = p_head;
    std::cout << "打印链表：" << std::endl;
    for (; p_node->next != nullptr; p_node = p_node->next)
        std::cout << p_node->value << " ";
    std::cout << std::endl;
}
#endif // _LISTNODE_BYPOINTER_HPP_