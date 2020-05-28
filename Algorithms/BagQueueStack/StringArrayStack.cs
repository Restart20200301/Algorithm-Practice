public class StringArrayStack
{
    private string[] s;
    private int n;
    
    public StringArrayStack()
    {
        s = new string[1];
        n = 0;
    }

    public bool IsEmpty()
    {
        return n != 0;
    }

    public int Size()
    {
        return n;
    }

    public void Push(string item)
    {
        if (n == s.Length) Resize(s.Length * 2);
        s[n] = item;
        n++;
    }

    public string Pop()
    {
        n--;
        var t = s[n];
        s[n] = null;
        if (n == s.Length / 4) Resize(s.Length / 2);
        return t;
    }

    private void Resize(int size)
    {
        var copy = new string[size];
        for (int i = 0; i < s.Length; i++)
        {
            copy[i] = s[i];
        }
        s = copy;
    }
}