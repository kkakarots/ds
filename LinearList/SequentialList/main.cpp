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
    std::cout << "✅初始化链表成功\n"
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
        std::cout << "❌插入位置 {" << pos << "} 无效，请重新输入。\n"
                  << std::endl;
        return;
    }
    std::cout << "✨排序前：";
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
    std::cout << "\n✨插入后输出："
              << std::endl;
    for (int i = 0; i < L.length; i++)
    {
        std::cout << L.data[i] << ", ";
    }
    std::cout << " " << std::endl;
    return;
}

/**
 * 删除指定位置的元素，并将删除的值赋值给e
 * @param DynamicSqList 结构体
 * @param int 删除位置
 * @param ElemType & 引用e赋值
 * @return bool==>true/false 成功/失败
 */
bool ListDel(DynamicSqList &L, int pos, ElemType &e)
{
    // 检测合法性
    if (pos < 0 || pos > L.DynamicMaxSize || pos > L.length)
    {
        std::cout << "❌删除位置不合法！" << std::endl;
        return false;
    }
    // 主功能
    e = L.data[pos - 1];
    for (int i = pos; i < L.length; ++i)
    {
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    std::cout << "\n✅删除成功，删除：" << e << std::endl;
    std::cout << "✨删除后输出："
              << std::endl;
    for (int i = 0; i < L.length; i++)
    {
        std::cout << L.data[i] << ", ";
    }
    return true;
}

/**
 * 查找元素
 * @param DynamicSqList 结构体
 * @param ElemType 要查找的元素
 * @return 元素位置，-1为未找到
 */
int LocateElem(DynamicSqList L, ElemType e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (e == L.data[i])
        {
            std::cout << "✅ 查找成功，位置：" << i + 1 << std::endl;

            return i + 1;
        }
    }
    std::cout << "❌ 查找失败!" << std::endl;
    return -1;
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
    int del_res = 0;
    // ListDel(L, 2, del_res);
    // std::cout << "\n✨del_res:" << del_res << std::endl;
    LocateElem(L, 1109);
    system("pause");
    return 0;
}