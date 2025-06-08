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
        L->data = 0;   // 通常为无效值
        L->next = nullptr;

        // LinkList node = new LNode;
        // node->data = 123;
        // node->next = nullptr;
        // L->next = node;
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
 * Todo 5 求表长操作
 */
/**
 * Todo 4 按序号查找结点
 */
/**
 * Todo 4 按值查找结点
 */
/**
 * Todo 2 插入结点
 */
/**
 * Todo 3 删除结点
 */
/**
 * Todo 1 采用头插法建立单链表
 */
/**
 * Todo 1 采用尾插法建立单链表
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    std::cout << "# 线性表-单链表 \n"
              << std::endl;

    LinkList head;
    bool withHeadNode = true;
    InitLinkList(head, withHeadNode);

    system("pause");
    return 0;
}
