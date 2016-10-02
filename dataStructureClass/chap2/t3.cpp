#include <iostream>
#include "my_list.h"
using namespace std;
int main()
{
    MyList old_l;
    old_l.init_list(100);
    old_l.display_my_list();
    MyList new_l; 
    new_l = old_l.reverse_list();
    new_l.display_my_list();
    return 0;
}

