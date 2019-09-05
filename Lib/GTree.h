#ifndef GTREE_H
#define GTREE_H
#include "GTreeNode.h"
#include "Tree.h"
#include "Exception.h"
#include "LinkQueue.h"

namespace Lib
{

template<typename T>
class GTree : public Tree<T>
{
protected:
    //队列成员
    LinkQueue< GTreeNode<T>* > m_queue;

    GTreeNode<T>* find(GTreeNode<T>* node, const T& value) const
    {
        GTreeNode<T>* ret = NULL;

        if(node != NULL)
        {
            if(node->value == value)
            {
                return node;
            }
            else
            {
                //遍历当前节点里的每一个子树在每一个子树里查找value
                for(node->child.move(0); !node->child.end() && (ret == NULL); node->child.next())
                {
                    ret = find(node->child.current(), value);
                }
            }
        }

        return ret;
    }

    GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* obj) const
    {
        GTreeNode<T>* ret = NULL;

        if(node == obj)
        {
            return node;
        }
        else
        {
            if(node != NULL)
            {
                //遍历当前节点里的每一个子树在每一个子树里查找value
                for(node->child.move(0); !node->child.end() && (ret == NULL); node->child.next())
                {
                    ret = find(node->child.current(), obj);
                }
            }
        }

        return ret;
    }

    //功能函数free,便于实函数clear
    void free(GTreeNode<T>* node)
    {
        if(node != NULL)
        {
            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                free(node->child.current());
            }

            //清除根节点自身,判断是不是来源于堆空间如果是栈空间则什么也不做
            if(node->flag())
            {
                delete node;
            }

        }
    }

    //删除功能函数，将node为根节点的子树从原来的树中删除，ret作为子树返回（ret指向堆空间中的树对象）
    void remove(GTreeNode<T>* node, GTree<T>*& ret)
    {
        //从堆空间申请一颗树
        ret = new GTree<T>();

        if(ret == NULL)
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to creat new Tree...");
        }
        else
        {
            if(root() == node)
            {
                this->m_root = NULL;
            }
            else
            {
                //定义一个引用是node的父节点的孩子链表的别名
                LinkList<GTreeNode<T>*>& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;

                child.remove(child.find(node));

                node->parent = NULL;
            }

            ret->m_root = node;

        }
    }

    //计算以node为根节点得树得节点数目
    int count(GTreeNode<T>* node) const
    {
        int ret = 0;

        if(node != NULL)
        {
            ret = 1;

            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                ret += count(node->child.current());
            }
        }
        return ret;
    }

    //求树得高度
    int height(GTreeNode<T>* node) const
    {
        int ret = 0;

        if(node != NULL)
        {
            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                int h = height(node->child.current());

                if(ret < h)
                {
                    ret = h;
                }
            }

            ret += 1;
        }

        return ret;
    }

    int degree(GTreeNode<T>* node) const
    {
        int ret = 0;

        if(node != NULL)
        {
            //先求出根节点得度数
            ret = node->child.length();

            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                int d = degree(node->child.current());

                if(ret < d)
                {
                    ret = d;
                }
            }
        }

        return ret;
    }

public:

    GTree()
    {

    }

    bool insert(TreeNode<T>* node)
    {
        bool ret = true;
        if(node != NULL)
        {
            if(this->m_root == NULL)
            {
                node->parent = NULL;
                //重点
                this->m_root = node;
            }
            else
            {
                //查找一下指定的父节点是否在当前树中
                GTreeNode<T>* np = find(node->parent);

                if(np != NULL)
                {
                    //查一下要插入的新节点是否已经在树中
                    GTreeNode<T>* n = dynamic_cast<GTreeNode<T>*>(node);

                    if(np->child.find(n) < 0)
                    {
                        //插入到父节点的子节点链表中
                        np->child.insert(n);
                    }
                }
                else
                {
                    THROW_EXCEPTION(InvalidOperationException, "Invalid parent tree node...");
                }

            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Parameter node cannot be NULL...");
        }

        return ret;
    }

    bool insert(const T& value, TreeNode<T>* parent)
    {
        bool ret = true;
        GTreeNode<T>* node = GTreeNode<T>::NewNode();

        if(node != NULL)
        {
            node->value = value;
            node->parent = parent;

            insert(node);
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to creat new Tree Node...");
        }

        return ret;
    }

    SharedPointer< Tree<T> > remove(const T& value)
    {
        GTree<T>* ret = NULL;
        //找到以value为值得node元素
        GTreeNode<T>* node = find(value);

        if(node == NULL)
        {
            THROW_EXCEPTION(InvalidParameterException, "Can not find the node via parameter value...");
        }
        else
        {
            remove(node, ret);

            m_queue.clear();
        }

        return ret;
    }

    SharedPointer< Tree<T> > remove(TreeNode<T>* node)
    {
        GTree<T>* ret = NULL;
        //找到node节点的弟子
        node = find(node);

        if(node == NULL)
        {
            THROW_EXCEPTION(InvalidParameterException, "parameter node is invalid...");
        }
        else
        {
            remove(dynamic_cast<GTreeNode<T>*>(node), ret);

            m_queue.clear();
        }

        return ret;
    }

    GTreeNode<T>* find(const T& value) const
    {
        return find(root(), value);
    }

    GTreeNode<T>* find(TreeNode<T>* node) const
    {
        return find(root(), dynamic_cast<GTreeNode<T>*>(node));
    }

    GTreeNode<T>* root() const
    {
        return dynamic_cast<GTreeNode<T>*>(this->m_root);
    }

    int degree() const
    {
        return degree(root());
    }

    int count() const
    {
        return count(root());
    }

    int height() const
    {
        return height(root());
    }

    void clear()
    {
        free(root());

        this->m_root = NULL;

        m_queue.clear();
    }


    bool begin()
    {
        bool ret = (root() != NULL);

        if(ret)
        {
            m_queue.clear();
            m_queue.add(root());
        }

        return ret;
    }


    bool end()
    {
        return (m_queue.length() == 0);
    }

    //将游标指向下一个节点，然后把此节点得孩子压入队列中
    bool next()
    {
        bool ret = (m_queue.length() > 0);

        if( ret )
        {
            //node指向对头元素
            GTreeNode<T>* node = m_queue.front();

            //将对头元素删除
            m_queue.remove();

            //将弹出队列得节点得孩子压入队列中
            for(node->child.move(0); !node->child.end(); node->child.next())
            {
                m_queue.add(node->child.current());
            }
        }

        return ret;
    }

    T current()
    {
        //只有在遍历得过程当中调用此函数才有意义
        if(!end())
        {
            //其实游标所指向得位置就是队头元素
            return m_queue.front()->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position...");
        }
    }

    ~GTree()
    {
        clear();
    }
};

}

#endif // GTREE_H
