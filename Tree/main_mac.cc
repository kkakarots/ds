/**
 * * 结构体指针带别名版 
 */
#include <iostream>
#include <cstdlib>

using namespace std;

/** 二叉树节点结构体 */
typedef struct TreeNode
{
    int val;         // 节点值
    TreeNode *left;  // 左子节点指针
    TreeNode *right; // 右子节点指针
} TreeNode, *TreePtr;

/** 构造函数(初始化) */
TreePtr InitTreeNode(int val)
{
    TreePtr f_tnode = new TreeNode;
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
    std::cout << "🏔️ 树 \n"
              << std::endl;
    TreePtr tnode = InitTreeNode(1);
    cout << tnode->val << endl;
#if true

#endif
    system("pause");
    return 0;
}