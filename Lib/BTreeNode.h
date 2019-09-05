#ifndef BTREENODE_H
#define BTREENODE_H
#include "TreeNode.h"

namespace Lib
{

template <typename T>
class BTreeNode : public TreeNode<T>
{

public:
    BTreeNode<T>* left;
    BTreeNode<T>* right;

    BTreeNode()
    {
        left = NULL;
        right = NULL;
    }


    //工厂方法
    static BTreeNode<T>* NewNode()
    {
        BTreeNode<T>* ret = new BTreeNode<T>();

        //如果是从堆空间创建的则m_flag = true;
        if(ret != NULL)
        {
            ret->m_flag = true;
        }

        return ret;
    }

};


}


#endif // BTREENODE_H
