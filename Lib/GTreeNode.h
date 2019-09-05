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
    //������ָ���̽ڵ��ָ��
    LinkList<GTreeNode<T>*> child;

    //��������
    static GTreeNode<T>* NewNode()
    {
        GTreeNode<T>* ret = new GTreeNode<T>();

        //����ǴӶѿռ䴴������m_flag = true;
        if(ret != NULL)
        {
            ret->m_flag = true;
        }

        return ret;
    }
};

}

#endif // GTREENODE_H
