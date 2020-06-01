using System;
using Hugo;

public class MaxPq<TKey> where TKey: IComparable<TKey>
{
    private TKey[] _pq;
    private int _n = 0;

    public MaxPq(int max)
    {
        _pq = new TKey[max + 1];
    }

    public void Insert(TKey v)
    {
        _pq[++_n] = v;
        Swim(_n);
    }

    public TKey Max()
    {
        return _pq[1];
    }

    public TKey DelMax()
    {
        TKey max = _pq[1];
        Utils.Swap(ref _pq[1], ref _pq[_n--]);
        Sink(1);
        return max;
    }

    bool IsEmpty()
    {
        return _n == 0;
    }

    int Size()
    {
        return _n;
    }

    private void Swim(int k)
    {
        while (k > 1 && _pq[k / 2].CompareTo(_pq[k]) < 0)
        {
            Utils.Swap(ref _pq[k / 2], ref _pq[k]);
            k /= 2;
        }
    }

    private void Sink(int k)
    {
        while (k * 2 <= _n)
        {
            int j = k * 2;
            if (j < _n && _pq[j].CompareTo(_pq[j + 1]) < 0) j++;
            if (_pq[k].CompareTo(_pq[j]) > 0) break;
            Utils.Swap(ref _pq[k], ref _pq[j]);
            k = j;
        }
    }
}