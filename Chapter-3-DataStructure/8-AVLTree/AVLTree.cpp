#include "AVLTree.hpp"
#include <assert.h>
#include <math.h>

#define TEST_MAX 1024

int main()
{
    AVLTree *t = AVLTreeNew();

    for (int i = 1; i <= TEST_MAX; i++) {
        AVLTreeInsert(t, i);
        /* AVL���ĸ߶Ȳ����� log(N) */
        assert( pow(2, ) );
    }
    return 0;
}
