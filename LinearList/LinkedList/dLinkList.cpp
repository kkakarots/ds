#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <typeinfo>

using namespace std;

typedef int ElemType; // 类型定义
/**
 * 双链表结点类型定义
 */
typedef struct DLNode
{
    ElemType data;
    struct DLNode *prior, *next;
} DLNode, *DLinkList;

/**
 * 双链表初始化
 */
void InitDLinkList(DLinkList &L)
{
    L = new DLNode;
    L->data = 0;
    L->prior = nullptr;
    L->next = nullptr;
    cout << "✅ 双链表初始化完成！头结点地址：" << L << endl;
}

/**
 * Todo 双链表的插入
 */
bool InsertDLinkList(DLinkList &L)
{}
/**
 * Todo 双链表的删除
 */
bool DeleteDLinkListByValue(DLinkList &L)
{}
/**
 * Todo 双链表的遍历
 */
bool LogDLinkList(DLinkList &L)
{}
/**
 * MAIN
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    std::cout << "🏔️ 线性表-双链表 \n"
              << std::endl;
    DLinkList head;
    InitDLinkList(head);
#if false
    {
        cout << "➡️ 最终链表结果：" << endl;
        // printLinkList(head);
    }
#endif
    system("pause");
    return 0;
}