bool delete_min(List *head)
{
    if (head -> next == head)
    {
        delete head;
        return TRUE;
    }
    else
    {
        int min = head -> data;
        List p_min = head;
        List current = head;
        while (head != current)
        {
            head = head -> next;
            if (head -> data < min)
            {
                p_min = head;
            }
        }
        delete(p_min);
    }

}
