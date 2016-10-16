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
                    char_list_first -> next = char_tmp;
                }
            }
            else if (head -> data == int)
            {
                int_tmp = head;
                if (int_list_first == 0)
                    int_list_first = int_tmp;
                else
                {
                    int_list_first -> next = int_tmp;
                }
            }
            else if (head -> data == other)
            {
                other_tmp = head;
                if (other_list_first == 0)
                    other_list_first = other_tmp;
                else
                {
                    other_list_first -> next = other_tmp;
                }
            }
            head = head -> next;
        }

        char_tmp = 0;
        int_tmp = 0;
        other_tmp = 0;
        delete char_tmp;
        delete int_tmp;
        delete other_tmp;
    }
}
