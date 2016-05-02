#include <cstdlib>

template<typename T>
class RB_TreeNode
{
    public:
        RB_TreeNode():lson(NULL),rson(NULL),color(1){}
        T data;
        RB_TreeNode *lson;
        RB_TreeNode *rson;
        bool color;
};
int main()
{
     
    return 0;
}

