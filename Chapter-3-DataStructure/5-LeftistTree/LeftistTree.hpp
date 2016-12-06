#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <algorithm>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

/* ����������������������ݽṹ */
/* �ڵ��±�Ϊx�Ľڵ� �����Һ��ӽڵ���±�Ϊ LEFT_CHILD(x) RIGHT_CHILD(x) */
#define LEFT_CHILD(x) ((x)->left)
#define RIGHT_CHILD(x) ((x)->right)

struct LeftistNode {
    int value;
    /* �ڵ�i�ľ���Ϊdistance */
    int distance;
    /* ���Һ��ӽڵ� ���ڵ� */
    LeftistNode *left;
    LeftistNode *right;
    LeftistTree *tree;
};

struct LeftistTree {
    LeftistNode *root;
    int size;
    int compare(LeftistNode*, LeftistNode*);
};

/* ������s[start, end]��ʼ��Ϊ������ ���ڵ�rootΪ0 */
LeftistTree *LeftistTreeNew(int (*compare)(LeftistNode*, LeftistNode*))
{
    LeftistTree *t = new LeftistTree();
    if (!t)
        return NULL;
    t->root = NULL;
    t->size = 0;
    t->compare = compare;
    return t;
}

void LeftistNodeFree(LeftistNode *e)
{
    if (!e)
        return;
    LeftistNodeFree(e->left);
    LeftistNodeFree(e->right);
    free(e);
}
void LeftistTreeFree(LeftistTree *t)
{
    LeftistNodeFree(t->root);
}

LeftistNode *LeftistNodeMerge(LeftistNode *a, LeftistNode *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    int (*compare)(LeftistNode*, LeftistNode*) = a->tree->compare;
    if (compare(a, b) > 0) {
        return LeftistNodeMerge(b, a);
    }

    a->right = LeftistNodeMerge(a->right, b);

    if (!a->left) {
        swap(a->left, a->right);
    } else {
        if (a->left->distance < a->right->distance)
            swap(a->left, a->right);
        a->distance = a->right->distance + 1;
    }

    return a;
}

/* �ϲ� */
LeftistTree *LeftistTreeMerge(LeftistTree *a, LeftistTree *b)
{
    LeftistTree *t = new LeftistTree();
    if (!t)
        return NULL;
    t->compare = a->compare;
    t->size = a->size + b->size;
    t->root = LeftistNodeMerge(a->root, b->root);
    return t;
}

int LeftistTreePush(LeftistTree *t, int value)
{
    LeftistNode *e = new LeftistNode();
    if (!e)
    node->m_index = value;
    return(leftist_tree_merge(root, node));

    int mid = (left_node[root] + right_node[root]) / 2;
    if (left_node[root] >= start && right_node[root] <= end) {
        return sum[root];
    } else if (end <= mid) {
        return LeftistTreeQuery( LEFT_CHILD(root), start, end );
    } else if (start >= mid + 1) {
        return LeftistTreeQuery( RIGHT_CHILD(root), start, end );
    } else { 
        return LeftistTreeQuery( LEFT_CHILD(root), start, mid) 
            + LeftistTreeQuery( RIGHT_CHILD(root), mid + 1, end);
    }
}

#endif