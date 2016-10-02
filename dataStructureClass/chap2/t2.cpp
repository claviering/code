#include <iostream>
#include "my_list.h"
using namespace std;

int main()
{
    MyList l;
    l.init_list(100); 
    l.display_my_list();
    l.delete_node(4);
    l.display_my_list();
    return 0;
}

