using System.Collections;
using System.Collections.Generic;

public class SequentialSearchST<TKey, TValue> : IEnumerable<TKey>
{
    private class Node
    {
        public TKey key;
        public TValue val;

        public Node next;

        public Node(TKey key, TValue val, Node next)
        {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }

    private Node head;

    public TValue Get(TKey key)
    {
        for (Node x = head; x != null; x = x.next)
            if (x.key.Equals(key))
                return x.val;
        return default(TValue);
    }

    public void Put(TKey key, TValue val)
    {
        for (Node x = head; x != null; x = x.next)
        {
            if (x.key.Equals(x))
            {
                x.val = val;
                return;
            }
        }

        head = new Node(key, val, head);
    }

    public int Size()
    {
        int cnt = 0;
        for (Node x = head; x != null; x = x.next, cnt++) ;
        return cnt;
    }

    public void Delete(TKey key)
    {
        Node prev = head;
        for (Node x = head; x != null; x = x.next)
        {
            if (x.key.Equals(key))
            {
                if (x != head) prev.next = x.next;
                else head = head.next;
                return;
            }
            prev = x;
        }
    }

    public IEnumerator<TKey> GetEnumerator()
    {
        for (Node x = head; x != null; x = x.next)
            yield return x.key;    
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}