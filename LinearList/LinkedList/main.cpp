#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <typeinfo>

using namespace std;

typedef int ElemType; // 类型定义

/**
 * 单链表结点类型定义
 *
 * 本质上，typedef 语句给 struct LNode 起了两个别名：
 *  - LNode       等价于 struct LNode
 *  - LinkList    等价于 struct LNode*
 *
 * 所以：
 *  - LNode node;         等价于 struct LNode node;
 *  - LinkList head;      等价于 struct LNode* head;
 *
 * 注意：LinkList 是一个“指针类型”的别名，定义变量时不需要再加 *
 */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/* 相当于下面两个 typedef 分开写 */
/* typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode;
typedef struct LNode *LinkList; */

/** 输出链表 */
void printLinkList(LinkList &L)
{
    cout << "链表长度：" << L->data << endl;
    cout << "数据：" << endl;
    LinkList temp = L->next;
    while (temp != nullptr)
    {
        cout << temp->data << ", ";
        // cout << temp->next << ", "; // 输出下一个结点地址
        temp = temp->next;
    }
    cout << endl;
    return;
}

/**
 * 单链表初始化，不推荐写法，因为函数不负责分配内存，容易在调用时出错
 */
// void InitLinkList(LinkList &L, bool with_head_node)
// {
//     if (with_head_node)
//     {
//         LinkList node = new LNode;
//         L->next = node;
//         node->data = 0; // 通常存储链表长度
//         node->next = NULL;
//     }
//     else
//     {
//         L->next = NULL;
//     }
//     cout << "头指针地址：" << L << endl;
//     if (L->next != NULL)
//         cout << "头结点值：" << L->next->data << endl;
//     cout << typeid(L).name() << endl;
// }
void InitLinkList(LinkList &L, bool with_head_node)
{
    if (with_head_node)
    {
        L = new LNode; // ✅ 在函数内 new 出头结点
        L->data = 0;   // 通常为无效值/链表长度
        L->next = nullptr;
    }
    else
    {
        L = nullptr; // 空链表，无头结点
    }

    std::cout << "头指针地址：" << L << std::endl;
    if (L && L->next)
        std::cout << "首元节点值：" << L->next->data << std::endl;
}

/**
 * 求表长操作
 * 头结点已/未存储
 */
int GetLinkListLength(LinkList L)
{
    cout << "表长：";
    LinkList temp = L;
    // if (L->data)
    if (false)
    {
        cout << L->data << endl;
        return L->data;
    }
    else
    {
        int length = 0;
        for (; temp->next != nullptr; length++)
        {
            temp = temp->next;
        }
        cout << length << endl;
        return length;
    }
}

/**
 * 按序号查找结点
 * ! 重点是头结点之后的结点才是首元结点
 */
ElemType GetNodeByIndex(LinkList &L)
{
    cout << "✨ 按序号查找结点" << endl;
    int pos = -1;
    cout << "🍍 请输入要查找的结点序号：" << endl;
    cin >> pos;
    int i = 0;
    LinkList temp = L;
    while (i < pos && temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }
    if (i != pos)
    {
        cout << "❌ 查找超出范围" << endl;
        return -1;
    }
    else
    {
        cout << "✅ 成功(值)" << temp->data << endl;
        cout << "✅ 成功(索引/地址)" << temp << endl;
        return temp->data;
    }
}

/**
 * 按值查找结点
 * ! 重点是头结点之后的结点才是首元结点
 */
ElemType GetNodeByValue(LinkList &L)
{
    cout << "✨ 按值查找结点" << endl;
    int pos = -1;
    cout << "🍍 请输入要查找的结点值：" << endl;
    cin >> pos;
    // int i = 0;
    LinkList temp = L->next;
    while (temp->next != nullptr && temp->data != pos)
    {
        temp = temp->next;
    }
    if (temp->data != pos)
    {
        cout << "❌ 查无结果" << endl;
        return -1;
    }
    else
    {
        cout << "✅ 成功(值)" << temp->data << endl;
        cout << "✅ 成功(索引/地址)" << temp << endl;
        return temp->data;
    }
}

/**
 * 改变指定位置结点值
 * * 查找后修改 temp->data 即可
 */

/**
 * 删除指定位置/值结点
 * * 1.查找 2.断链
 */
ElemType DeleteNodeByIndex(LinkList &L)
{
    cout << "✨ 按序号删除结点" << endl;
    int pos = -1;
    cout << "🍍 请输入要删除的结点序号：" << endl;
    cin >> pos;
    int i = 0;
    LinkList temp = L;
    if (pos < 1 || pos > L->data)
    {
        cout << "❌ 查找超出范围" << endl;
        return -1;
    }
    while (i < pos - 1 && temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }

    // 此时temp指向的是要删除元素的上一个元素
    temp->next = temp->next->next;
    L->data--;

    cout << "✅ 删除成功" << endl;
    return 1;
}

/**
 * 插入结点
 * ! 注意位置有效性判断
 */
void InsertLinkList(LinkList &L)
{
    cout << "✨ 向单链表指定位置插入结点" << endl;

    ElemType val; // 值
    int pos = -1;
    cout << "🍍 请输入要插入的值： " << endl;
    cin >> val;
    cout << "🍍 请输入要插入的位置： " << endl;
    cin >> pos;
    // 边界检查
    if (pos <= 0)
    {
        cout << "❌ 位置必须大于0！" << endl;
        return;
    }
    LinkList temp = L;
    int i = 0;
    while (temp->next != nullptr && i < pos - 1)
    {
        i++;
        temp = temp->next;
    }
    // 允许往链表末尾添加，但是不可超出 比如：链表长度：5 插入位置6 ✅ / 插入位置7 ❌
    if (i != pos - 1)
    {
        cout << "❌ 插入位置超出链表长度！" << endl;
        return;
    }

    LinkList node = new LNode;
    node->data = val;
    node->next = temp->next;
    temp->next = node;
    L->data++;
    cout << "✅ 插入成功！" << endl;
}

/**
 * 采用头插法建立单链表
 * ! 重点在于头结点的next始终指向最新插入的结点
 */
void CreateLinkListHead(LinkList &L)
{
    cout << "✨ 头插法创建单链表" << endl;
    ElemType val;

    cout << "🍍 请输入要插入的值，以-1结尾。" << endl;

    while (cin >> val && val != -1)
    {
        LinkList temp = new LNode;
        temp->data = val;
        temp->next = L->next; // 插入到头结点之后
        L->next = temp;       // 更新头结点指针
        L->data++;            // 有效节点数加 1
    }
    cout << "✅ 创建完成！" << endl;
}
/**
 * 采用尾插法建立单链表
 * ! 重点在于使用尾指针，避免每次插入都从头开始找最后一个结点
 * @param LinkList 头指针
 */
void CreateLinkListTail(LinkList &L)
{
    cout << "✨ 尾插法创建单链表" << endl;
    ElemType val;

    LinkList tail = L;

    cout << "🍍 请输入要插入的值，以-1结尾。" << endl;

    while (cin >> val && val != -1)
    {
        LinkList temp = new LNode;
        temp->data = val;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp; // 更新尾指针
        L->data++;
    }
    cout << "✅ 创建完成！" << endl;
}

/**
 * MAIN
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    std::cout << "🏔️ 线性表-单链表 \n"
              << std::endl;

    LinkList head;
    bool withHeadNode = true;
    InitLinkList(head, withHeadNode);
    // CreateLinkListTail(head);
    CreateLinkListHead(head);
    // GetLinkListLength(head);
    printLinkList(head);
    // GetNodeByIndex(head);
    // GetNodeByValue(head);
    // InsertLinkList(head);
    DeleteNodeByIndex(head);
#if true
    {
        cout << "➡️ 最终链表结果：";
        printLinkList(head);
    }
#endif
    system("pause");
    return 0;
}
