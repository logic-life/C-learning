#include "chaintable.h"

int main(int argc, char *argv[])
{
    ChainTable my_list;
    my_list.ListCreate();
    my_list.ListInsert(4);
    my_list.ListInsert(5);
    my_list.ListInsert(6);
    my_list.ListInsert(7);
    my_list.ListInsert(8);
    my_list.ListInsert(9);
    my_list.ShowChainTable();
    std::cout << "分隔符" << std::endl;
    std::cout << "查询data=6:" << my_list.ListSearch(6) <<"输出data=:"<< my_list.ListSearch(6)->data<<std::endl;
    std::cout << "分隔符" << std::endl;
    std::cout << my_list.ListDelete(7) << std::endl;
    std::cout << "分隔符" << std::endl;
    my_list.ShowChainTable();
    return 0;
}