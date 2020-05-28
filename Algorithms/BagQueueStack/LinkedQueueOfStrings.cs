public class LinkedQueueOfStrings
{
    private Node first, last;
    private int N;
    
    private class Node
    {
        public string item;
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

    public void Enqueue(string item)
    {
        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if (IsEmpty()) first = last;
        else oldLast.next = last;
        N++;
    }

    public string Dequeue()
    {
        var item = first.item;
        first = first.next;
        if (IsEmpty()) last = null;
        N--;
        return item;
    }
}