#include <iostream>
#include <string.h>
#define HASHSIZE 10

using namespace std;
typedef unsigned int uint;
typedef struct Node
{
    const uint *key;
    const string *value;
    Node *next;

} Node;

class HashTable
{
private:
    /* data */
    Node *node[HASHSIZE];

public:
    HashTable(/* args */);
    uint hashFunction(const uint *key);
    bool hashTableInsert(const uint *key, const string *value);
    Node *hashTableSearch(const uint *key);
    bool hashTableDelete(const uint *key);
    //~HashTable();
};

//生成一个HASHSIZE大小的哈希表
HashTable::HashTable()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        node[i] = nullptr;
    }
}
//定义哈希函数：Time33定义方式
uint HashTable::hashFunction(const uint *key)
{
    uint hash_value = *key % HASHSIZE;
    // for (; *key; key++)
    // {
    //     hash_value = hash_value * 33 + *key;
    // }

    return hash_value;
}
//哈希表查询操作
Node *HashTable::hashTableSearch(const uint *key)
{
    Node *np;
    uint index = hashFunction(key);
    for (np = node[index]; np; np=np->next)
    {
        if (*key == *(np->key))
            return np;
    }
    return NULL;
}
//哈希表插入操作????????链表法插入有问题
bool HashTable::hashTableInsert(const uint *key, const string *value)
{
    uint index;
    Node *np;
    //判断np对应节点的哈希值槽是否为空，空就插入一个新值
    if (!(np = hashTableSearch(key)))
    {
        index = hashFunction(key);
        np = (Node *)malloc(sizeof(Node));
        if (!np)
            return false;
         np->key = key;
         np->value = value;
         np->next = node[index];                  
         node[index] = np;

    }
    np->value = value;
    return true;
}


//哈希表删除操作
bool hashTableDelete(const uint *key)
{
    return false;
}
// HashTable::~HashTable()
// {
//     delete[] node;
// }
