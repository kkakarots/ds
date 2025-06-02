#include <iostream>
#include <cstdlib>
#include "basic_type.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    std::cout << "# IO | 输入输出" << std::endl;
    printBasicType();
    system("pause");
    return 0;
}
