#include <iostream>
#include "listnode_byreference.hpp"

bool hasCycle(ListNode *head);

int main(int argc, char *argv[])
{
    ListNode *p_head = new ListNode(4, nullptr);
    ListNode node1(4);
    ListNode node2(5);
    ListNode node3(6);
    ListNode node4(7);
    p_head->next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node1;
    std::cout << hasCycle(p_head) << std::endl;
    return 0;
}

bool hasCycle(ListNode *head) // 链表判断环

{ //初始化两个快慢指针
    ListNode *fast = head;
    ListNode *slow = head;
    //不使用慢指针，会造成判断条件重复
    while (fast != nullptr && fast->next != nullptr)
    { //慢指针前进一步，快指针前进两步
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            //快指针追上慢指针，有环
            return true;
    }
    //退出循环表明有环
    return false;
}