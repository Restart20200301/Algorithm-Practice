using System;

public class BST<TKey, TValue> where TKey: IComparable<TKey>
{
    private Node root;

    private class Node
    {
        public TKey key;
        public TValue val;
        public Node left, right;
        public int n;

        public Node(TKey key, TValue val, int n)
        {
            this.key = key;
            this.val = val;
            this.n = n;
        }
    }

    public int Size()
    {
        return Size(root);
    }

    private int Size(Node x)
    {
        if (x == null) return 0;
        
        return x.n;
    }

    public TValue Get(TKey key)
    {
        return Get(root, key);
    }

    private TValue Get(Node x, TKey key)
    {
        if (x == null) return default(TValue);
        int cmp = key.CompareTo(x.key);
        if (cmp < 0) return Get(x.left, key);
        else if (cmp > 0) return Get(x.right, key);
        else return x.val;
    }

    public void Put(TKey key, TValue val)
    {
        root = Put(root, key, val);
    }

    private Node Put(Node x, TKey key, TValue val)
    {
        if (x == null) return new Node(key, val, 1);
        int cmp = key.CompareTo(x.key);
        if (cmp < 0) x.left = Put(x.left, key, val);
        else if (cmp > 0) x.right = Put(x.right, key, val);
        else x.val = val;
        x.n = Size(x.left) + Size(x.right) + 1;
        return x;
    }

    public TKey Min()
    {
        Node x = root;
        while (x.left != null)
        {
            x = x.left;
        }

        return x.key;
    }
}