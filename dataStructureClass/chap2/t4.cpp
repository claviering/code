void separate(List *head, List *char_list_first, List *int_list_first, List *other_list_first)
{
    if (head == 0)
    {
        return;
    }
    else
    {
        char_tmp = new List;
        int_tmp = new List;
        other_tmp = new List;

        while (head != 0)
        {
            if (head -> data == char)
            {
                char_tmp = head;
                if (char_list_first == 0)
                    char_list_first = char_tmp;
                else
                {
                    char_tmp -> next = head;
                    char_tmp = head;
                }
            }
            else if (head -> data == int)
            {
                int_tmp = head;
                if (int_list_first == 0)
                    int_list_first = int_tmp;
                else
                {
                    int_tmp -> next = head;
                    int_tmp = head;
                }
            }
            else if (head -> data == other)
            {
                other_tmp = head;
                if (other_list_first == 0)
                    other_list_first = other_tmp;
                else
                {
                    other_tmp -> next = head;
                    other_tmp = head;
                }
            }
            head = head -> next;
        }

        char_tmp = char_list_first;
        int_tmp = int_list_first;
        other_tmp = other_list_first;

        char_tmp = 0;
        int_tmp = 0;
        other_tmp = 0;
        delete char_tmp;
        delete int_tmp;
        delete other_tmp;
    }
}
