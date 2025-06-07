/**
 * Doxygen 风格注释
 * @file SequentialList/main.cpp
 * @brief 记录 线性表-顺序表
 * @author Cheney
 * @date 2025/06/07
 * @version 0.0.0
 * @copyright Cheney
 */

#include <iostream>
#include <cstdlib>
#include <windows.h>

/**
 * 静态分配 存储结构
 */
#define StaticMaxSize 50
typedef int ElemType;

/** typedef 写法 */
typedef struct
{
    ElemType data[StaticMaxSize];
    int length;
} StaticSqList;

/** 一般写法 */
struct StaticSqList_
{
    ElemType data[StaticMaxSize];
    int length;
};

/**
 * 动态分配 存储结构
 */
#define InitSize 10
typedef struct
{
    ElemType *data;
    int DynamicMaxSize, length; // 最大长度，当前长度
} DynamicSqList;
/**
 * 初始动态分配语句
 * @param DynamicSqList 结构体
 * @return void
 */
void InitList(DynamicSqList &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize); // C
    // L.data = new ElemType[InitSize]; // C++
    L.length = InitSize;
    L.DynamicMaxSize = InitSize;
    std::cout << "初始化链表成功\n"
              << std::endl;
    std::cout << L.data << std::endl;
    std::cout << L.length << std::endl;
}

/**
 * 插入元素
 * @param DynamicSqList 结构体
 * @param int 插入位置
 * @param ElemType 插入元素
 * @return void
 */
void ListInsert(DynamicSqList &L, int pos, ElemType e)
{
    // 插入位置有效性验证
    if (pos < 0 || pos > L.DynamicMaxSize || pos > L.length)
    {
        std::cout << "插入位置 {" << pos << "} 无效，请重新输入。\n"
                  << std::endl;
        return;
    }
    std::cout << "排序前"
              << std::endl;
    for (int i = 0; i < L.length; i++)
    {
        std::cout << L.data[i] << ", ";
    }
    for (int i = L.length; i >= pos; --i)
    {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos - 1] = e;
    L.length++;
    std::cout << "\n输出"
              << std::endl;
    for (int i = 0; i < L.length; i++)
    {
        std::cout << L.data[i] << ", ";
    }
    return;
}
/**
 * main function
 * @return int 0
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "# 线性表-顺序表 \n------------------------------------"
              << std::endl;
    DynamicSqList L;
    InitList(L);
    ListInsert(L, 2, 1109);
    system("pause");
    return 0;
}