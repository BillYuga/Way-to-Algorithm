#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <algorithm>
#ifndef MAX
#define MAX 64
#endif

/* ����������������������ݽṹ */
/* �ڵ��±�Ϊx�Ľڵ� �����Һ��ӽڵ���±�Ϊ LEFT_CHILD(x) RIGHT_CHILD(x) ���ڵ���±�Ϊ FATHER(x) */
#define LEFT_CHILD(x) (2 * (x) + 1)
#define RIGHT_CHILD(x) (2 * (x) + 2)
#define FATHER(x) (((x) - 1) / 2)

/* �ڵ�i���������ΧΪ[left_node[i], right_node[i]] ������ĺ�Ϊsum[i] */
int left_node[MAX * 3];
int right_node[MAX * 3];
int sum[MAX * 3];

/* ������s[start, end]��ʼ��Ϊ������ ���ڵ�rootΪ0 */
int SegmentTreeInit(int root, int s[MAX], int start, int end)
{
    if (start == end) {
        left_node[root] = start;
        right_node[root] = end;
        sum[root] = s[start];
        return sum[root];
    }

    int mid = (start + end) / 2;
    int left_sum = SegmentTreeInit( LEFT_CHILD(root), s, start, mid );
    int right_sum = SegmentTreeInit( RIGHT_CHILD(root), s, mid + 1, end );
    left_node[root] = start;
    right_node[root] = end;
    sum[root] = left_sum + right_sum;
    return sum[root];
}

/* ����s[index]��v */
void SegmentTreeAdd(int root, int index, int v)
{
    if (left_node[root] > index || right_node[root] < index) {
        return;
    }

    assert( left_node[root] <= index );
    assert( right_node[root] >= index );
    sum[root] += v;

    if (left_node[root] == right_node[root]) {
        return;
    }
    SegmentTreeAdd( LEFT_CHILD(root), index, v );
    SegmentTreeAdd( RIGHT_CHILD(root), index, v );
}

/* ��ѯ����s[start, end]��Χ�ĺ� */
int SegmentTreeQuery(int root, int start, int end)
{
    int mid = (left_node[root] + right_node[root]) / 2;
    if (left_node[root] >= start && right_node[root] <= end) {
        return sum[root];
    } else if (end <= mid) {
        return SegmentTreeQuery( LEFT_CHILD(root), start, end );
    } else if (start >= mid + 1) {
        return SegmentTreeQuery( RIGHT_CHILD(root), start, end );
    } else { 
        return SegmentTreeQuery( LEFT_CHILD(root), start, mid) 
            + SegmentTreeQuery( RIGHT_CHILD(root), mid + 1, end);
    }
}

#endif