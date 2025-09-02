/**
 * ! 结构体指针不带别名版
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

TreeNode *InitTreeNode(int val);
void levelOrder(TreeNode *root);
void preOrder(TreeNode *root);
void inOrder(TreeNode *root);
void postOrder(TreeNode *root);

/**
 * main function
 * @return 0
 */
int main()
{
    SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8
    std::cout << "🏔️ 树 \n"
              << std::endl;
    // TreeNode *tnode = InitTreeNode(100);
    // cout << "tnode Val:" << tnode->val << endl;
    // cout << "tnode Left:" << tnode->left << endl;
    // cout << "tnode Right:" << tnode->right << endl;

    /** 构造节点 */
    TreeNode *tn1 = InitTreeNode(1);
    TreeNode *tn2 = InitTreeNode(2);
    TreeNode *tn3 = InitTreeNode(3);
    TreeNode *tn4 = InitTreeNode(4);
    TreeNode *tn5 = InitTreeNode(5);

    /*
        example:
             tn1
            /   \
           tn2  tn3
          /   \
         tn4  tn5
    */
    /** 构建节点之间的引用 */
    tn1->left = tn2;
    tn1->right = tn3;
    tn2->left = tn4;
    tn2->right = tn5;

    {
        /** 插入节点 */
        TreeNode *p = InitTreeNode(101);
        // 在tn1 -> tn2 之间插入节点 p
        tn1->left = p;
        p->left = tn2;
        cout << "✅ Successed" << endl;
        /** 插入节点 */

        /** 删除节点 */
        tn1->left = tn2;
        delete (p);
        cout << "✅ Deleted" << endl;
        /** 删除节点 */
    }
    /** 遍历 */
    levelOrder(tn1);
    /** 遍历 */

#if true

#endif
    system("pause");
    return 0;
}

/**
 * 初始化树节点
 * @param val 值
 * @return TreeNode* 新建的节点指针
 */
TreeNode *InitTreeNode(int val)
{
    TreeNode *f_tnode = new TreeNode;
    f_tnode->val = val;
    f_tnode->left = NULL;
    f_tnode->right = NULL;
    return f_tnode;
}

/**
 * 层序遍历(广度优先)
 * @param root 根节点指针
 * @return void
 */
void levelOrder(TreeNode *root)
{
    /**
     * "队列"
     */
    cout << "Level Order:" << endl;
    /*
        层序遍历
        get node -> left -> right
        left -> left -> right ...
        ->left/->right == null --> stop

    */
    return;
}
/**
 * 前序遍历(深度优先)
 * @param root 根节点指针
 * @return void
 */
void preOrder(TreeNode *root)
{
    cout << "pre order" << endl;
    return;
}
/**
 * 中序遍历(深度优先)
 * @param root 根节点指针
 * @return void
 */
void inOrder(TreeNode *root)
{
    cout << "in order" << endl;
    return;
}
/**
 * 后序遍历(深度优先)
 * @param root 根节点指针
 * @return void
 */
void postOrder(TreeNode *root)
{
    cout << "post order" << endl;
    return;
}