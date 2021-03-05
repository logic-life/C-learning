# 单链表的两种创建方式
[单链表的创建](./listnode_bypoint.hpp)
**函数形参为什么要使用指向指针的指针，或者指针引用？**
```
//如果函数体形参调用是值传递，那么对应头节点的指针传递进去，被复制一份copy后，此后所有的修改都是在copy中进行的，与原指针无关，并不会对传入的头结点的指针进行修改。而指针引用和指向指针的指针才会更改head节点指向的内容！

void addTotail(ListNode *&p_head, int value)
{
    ListNode *new_node = new ListNode();
    new_node->next = nullptr;
    new_node->value = value;
    if (p_head == nullptr)
        p_head = new_node;
    else
    {
        ListNode *p_node = p_head;
        for (; p_node->next != nullptr; p_node = p_node->next)
            ;
        p_node->next = new_node;
    }
}

```
************
