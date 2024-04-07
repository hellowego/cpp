#include "leetcode.h"

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int level = 0;
        TreeNode *nodes = root;
        while (nodes->left != nullptr)
        {
            nodes = nodes->left;
            level++;
        }
        int low = 1 << level, high = (1 << (level + 1)) - 1;

        while (low < high)
        {
            int mid = (low + high + 1) / 2;
            if (exists(root, level, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode *root, int level, int k)
    {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bits > 0)
        {
            if (bits & k)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};