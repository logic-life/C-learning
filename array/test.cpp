#include <iostream>

using namespace std;

void sum(int *a)
{
    a[0] = a[1]; //把a[1]理解为*(a+1)
}
int main()
{
    int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 2; i >= 0; i--)
        sum(&aa[i]);
    cout << aa[0] << endl;
    return 1;
}