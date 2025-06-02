#include <iostream>
#include <cstdlib>
#include <windows.h>

void printDerivedType();

/**
 * 文件说明：基础类型的输入输出说明
 * 基础类型
 *  数组
 *  指针
 *  引用
 *  结构体
 *  类
 *  联合体
 *  枚举
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    printDerivedType();
    system("pause");
    return 0;
}
/**
 * 输入输出派生类型
 * @param void
 * @returns void
 */
void printDerivedType()
{
    // 数组
    int arr_a[5] = {1, 2, 3, 4, 5};
    // 指针
    int *ptr_null = nullptr;
    int *ptr;
    // 引用
    int ref_o = 1;
    int &ref_t = ref_o;
    // 结构体
    struct Point
    {
        int x;
        int y;
    };
    // 类
    class Position
    {
    public:
        int x;
        int y;
    };
    // 联合体
    union Data
    {
        int i;
        float f;
    };
    // 枚举
    enum Color
    {
        RED,
        GREEN,
        BLUE,
    };

    // 选择输出
    int select = -1;
    while (select != 0)
    {

        std::cout << "Please select the info you want print:\n"
                  << std::endl;
        std::cout << "1 -> Array\n"
                  << std::endl;
        std::cout << "2 -> Pointer\n"
                  << std::endl;
        std::cout << "3 -> Reference\n"
                  << std::endl;
        std::cout << "4 -> Struct\n"
                  << std::endl;
        std::cout << "5 -> Class\n"
                  << std::endl;
        std::cout << "0 -> Exit\n"
                  << std::endl;
        std::cin >> select;
        std::cout << "-----------------------------\n"
                  << std::endl;

        if (select == 0)
        {
            std::cout << "Program Exited!" << std::endl;
        }
        // 输出数组
        if (select == 1)
        {
            // 1.for循环
            std::cout << "1.for循环输出: \n"
                      << std::endl;
            for (int i = 0; i < 5; i++)
            {
                std::cout << arr_a[i] << "\n"
                          << std::endl;
            }
            // 2.for循环 && 指针
            std::cout << "2.for循环 && 指针输出: \n"
                      << std::endl;
            int *ptr_a = arr_a;
            for (int i = 0; i < 5; i++)
            {
                std::cout << "指针：" << ptr_a << "\n"
                          << std::endl;
                std::cout << "I：" << i << "\n"
                          << std::endl;
                std::cout << "指针+I：" << ptr_a + i << "\n"
                          << std::endl;
                std::cout << *(ptr_a + i) << "\n"
                          << std::endl;
            }
        }

        // 指针
        if (select == 2)
        {
            int a = 1;
            ptr = &a;
            ptr_null = &a;
            // ptr解引用
            std::cout << "ptr value: " << *ptr << "\n"
                      << std::endl;
            std::cout << "ptr_null value: " << *ptr_null << "\n"
                      << std::endl;

            // 重新赋值ptr这个内存地址的值
            // 同时也改变了a的值，因为a也是这个内存地址

            *ptr = 10;
            std::cout << "ptr value update: " << *ptr << "\n"
                      << std::endl;

            std::cout << "///POINTER/// \n"
                      << std::endl;
            std::cout << "ptr adress: " << ptr << std::endl;
            std::cout << "ptr adress + 1" << ptr + 1 << std::endl;
            std::cout << "a value" << a << std::endl;
        }

        // 引用
        if (select == 3)
        {
            std::cout << "引用:" << &ref_t << std::endl;
        }

        // 结构体
        if (select == 4)
        {
            Point p;  // 创建结构体实例
            p.x = 10; // 设置成员值
            p.y = 20;

            std::cout << "Point x: " << p.x << std::endl;
            std::cout << "Point y: " << p.y << std::endl;
        }

        // 类
        if (select == 5)
        {
            Position pos;
            pos.x = 1;
            pos.y = -1;
            std::cout << "# Class" << std::endl;
            std::cout << "x:" << pos.x << "\n"
                      << std::endl;
            std::cout << "x:" << pos.y << "\n"
                      << std::endl;
        }

        std::cout << "-----------------------------\n"
                  << std::endl;
    }
}