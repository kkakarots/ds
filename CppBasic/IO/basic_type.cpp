#include <iostream>


void printBasicType();


/**
 * 文件说明：基础类型的输入输出说明
 * 基础类型
 *  int    |  整形
 *  char   |  字符型
 *  float  |  浮点型
 *  double |  双浮点型
 *  bool   |  布尔型
 *  void   |  无类型
 */

/**
 * 输入输出基础类型
 * @param void
 * @returns void
 */
void printBasicType()
{
    int ia;
    char ca;
    float fa;
    double da;
    bool ba;
    // void类型 不能声明变量

    std::cout << "Please input int, float, char, bool:" << std::endl;
    std::cin >> ia >> fa >> ca >> ba;
    std::cout
        << "Show Results: \n"
        << ia << "\n"
        << fa << "\n"
        << ca << "\n"
        << ba << "\n----------------------------------------------------------------end"
        << std::endl;
}