#include "chainhashtable.h"
#include <map>
#include <string.h>
#include <vector>

int main(int argc, char *argv[])
{
    map<uint, string> hash_map;

    vector<string> hash_vec = {"zhangsan", "lisi", "wangwu", "zhaoliu", "sunce", "lisanye"};

    auto iterator = hash_vec.cbegin();
    //使用向量初始化键值对
    // for (uint i = 0; i < 6; i++)
    //     hash_map.insert({i, *(iterator + i)});
    hash_map.insert({1, hash_vec[1]});
    hash_map.insert({11, hash_vec[2]});
    hash_map.insert({2, hash_vec[3]});
    hash_map.insert({3, hash_vec[4]});
    hash_map.insert({4, hash_vec[5]});
    hash_map.insert({14, hash_vec[6]});
    map<uint, string>::iterator iter = hash_map.begin();
    //创建哈希表
    HashTable hashTable_1;
    //为哈希表插入元素
    for (iter; iter != hash_map.end(); iter++)
        cout << hashTable_1.hashTableInsert(&(iter->first), &(iter->second)) << endl;
    //查询key=3的值
    uint key[] = {0, 1, 2, 3, 4, 5};

    cout << *hashTable_1.hashTableSearch((key + 0))->value << endl;
    cout << *hashTable_1.hashTableSearch((key + 1))->value << endl;
    cout << *hashTable_1.hashTableSearch((key + 2))->value << endl;
    cout << *hashTable_1.hashTableSearch((key + 3))->value << endl;
    cout << *hashTable_1.hashTableSearch((key + 4))->value << endl;
    cout << *hashTable_1.hashTableSearch((key + 5))->value << endl;
    return 0;
}
