#include <iostream>
#include <cstring>
using namespace std;

// 王道程序员求职宝典数组刷题
int main()
{
    int b[] = {1, 2, 3, 4, 5, 6};
    int(&p)[6] = b;
    int *m = b;
    char s[] = {'c', '+', '+', '\0', 's', 'a'};
    cout << "输出字符串长度：" << strlen(s) << endl; //虽然数组长度不为3，但是字符串处理函数是以'\0'作为结束的标志的，因此输出长度为3
    cout << "输出数组首地址:" << b << endl;          //m的内容为数组a的首地址
    cout << "查询a的类型:" << typeid(b).name() << endl;
    cout << p << endl; //依然是对数组a的引用,内容为数组的地址
    cout << "查询p的类型:" << typeid(p).name() << endl;
    cout << "指向数组的指针:" << &b << endl; //&a类型为int(*)[6]
    cout << "查询&a的类型:" << typeid(&b).name() << endl;
    cout << "输出(int *)((char *)&p + sizeof(int))的地址：" << (int *)((char *)&b + sizeof(int)) << endl; //首先讲&b类型强制转换为char*,由于char每个内存空间占据1，所以加4再强制转换为b+1的地址
    cout << "查询(int *)((char *)&b + sizeof(int))的类型：" << typeid((int *)((char *)&b + sizeof(int))).name() << endl;
    // for (auto i = b; i < b + 6; i++)
    //     cout << i << " ";
    // cout << endl;

    // 数组初始化
    int v[4][2] = {0, 1, 2, 3, 4, 5};
    int *i = v[0];
    cout << "输出数组的第一个元素" << endl;
    cout << i[0] << endl;
    // for (int i = 0; i < 3; i++)
    //     for (int j = 0; j < 2; j++)
    //         cout << v[i][j] << " ";
    cout << "打印数组中的元素" << endl;
    for (auto k : v)
        cout << *k << endl;
    return 1;
}