import java.util.*;
class p180_6
{
    public static void main(String[] args)
    {
        List<String> letter_list = new ArrayList<String>();
        String[] letter = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        for (int i = 0; i < 10; i++)
        {
            double x = Math.random();
            int index = (int)(x * 100) % 25;
            letter_list.add(letter[index]);
        }
        System.out.println("sort before: " + letter_list);
        Collections.sort(letter_list);
        System.out.println("sort after: " + letter_list);
    }
}
