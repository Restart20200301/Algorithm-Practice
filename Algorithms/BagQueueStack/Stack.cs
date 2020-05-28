public class Stack<Item>
{
    private Node first = null;
    private int N = 0;
    
    private class Node
    {
        public Item item;
        public Node next;
    }

    public bool IsEmpty()
    {
        return first == null;
    }

    public int Size()
    {
        return N;
    }

    public void Push(Item item)
    {
        var oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        N++;
    }

    public Item Pop()
    {
        var item = first.item;
        first = first.next;
        N--;
        return item;
    }
}