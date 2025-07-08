/**
 * !结构体指针不带别名版 
 */
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

/** 二叉树节点结构体 */
typedef struct TreeNode
{
    int val;         // 节点值
    TreeNode *left;  // 左子节点指针
    TreeNode *right; // 右子节点指针
} TreeNode;

/** 构造函数(初始化) */
TreeNode *InitTreeNode(int val)
{
    TreeNode *f_tnode = new TreeNode;
    f_tnode->val = val;
    f_tnode->left = NULL;
    f_tnode->right = NULL;
    return f_tnode;
}
/**
 * MAIN
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    std::cout << "🏔️ 树 \n"
              << std::endl;
    TreeNode *tnode = InitTreeNode(1);
    cout << "Val:" << tnode->val << endl;
    cout << "Left:" << tnode->left << endl;
    cout << "Right:" << tnode->right << endl;
#if true

#endif
    system("pause");
    return 0;
}