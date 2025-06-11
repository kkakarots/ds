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

    // if (L->data)
    if (false)
    {
        cout << L->data << endl;
        return L->data;
    }
    else
    {
        int length = 0;
        for (length; L->next == nullptr; length)
        {
        }
        cout << length << endl;
        return length;
    }
}
/**
 * Todo 4 按序号查找结点
 */
/**
 * Todo 4 按值查找结点
 */
/**
 * Todo 5 改变指定位置结点值
 */
/**
 * Todo 6 删除指定位置/值结点
 */
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
 * Todo 3 删除结点
 */
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
    GetLinkListLength(head);
    printLinkList(head);
    InsertLinkList(head);
    #if true
    {
        cout << "➡️ 插入结果" << endl;
        printLinkList(head);
    }
    #endif
    system("pause");
    return 0;
}
