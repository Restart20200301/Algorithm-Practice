public class FixedCapacityStack<Item>
{
    private Item[] a;
    private int N;

    public FixedCapacityStack(int cap)
    {
        a = new Item[cap];
        N = 0;
    }

    public bool IsEmpty()
    {
        return N == 0;
    }

    public int Size()
    {
        return N;
    }

    public void Push(Item item)
    {
        a[N++] = item;
    }

    public Item Pop()
    {
        return a[--N];
    }

}