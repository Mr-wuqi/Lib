#ifndef GTREENODE_H
#define GTREENODE_H
#include "Object.h"
#include "TreeNode.h"
#include "LinkList.h"

namespace Lib
{

template<typename T>
class GTreeNode : public TreeNode<T>
{
public:
    //任意多的指向后继节点的指针
    LinkList<GTreeNode<T>*> child;

    //工厂方法
    static GTreeNode<T>* NewNode()
    {
        GTreeNode<T>* ret = new GTreeNode<T>();

        //如果是从堆空间创建的则m_flag = true;
        if(ret != NULL)
        {
            ret->m_flag = true;
        }

        return ret;
    }
};

}

#endif // GTREENODE_H
