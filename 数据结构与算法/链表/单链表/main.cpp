#define _LISTNODE_BYPOINTER_HPP_ //执行bypointer文件
#include "listnode_byreference.hpp"

int main(int argc, char *argv[])
{

    ListNode *p_head = nullptr;
    addTotail(p_head, 9);
    addTotail(p_head, 9);
    addTotail(p_head, 1);
    ListPrintf(p_head);
    ListNode *p_tail = nullptr;
    addTotail(p_tail, 1);
    ListPrintf(p_tail);
    ListNode *p = addTwoNumbers(p_head, p_tail);
    ListPrintf(p);
    return 0;
}
