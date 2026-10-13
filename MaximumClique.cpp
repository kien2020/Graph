// This code find maximum clique with heuristic, the worst case will cost 2^n but average runtime is much better
bitset<50> near[50];

inline bitset<50> MaximumClique(bitset<50> rem, bitset<50> cur, int best)
{
    if (rem.none() || cur.count() + rem.count() <= best)
    {
        return cur;
    }
    int x = __builtin_ctzll(rem.to_ullong());
    bitset<50> temp;
    rem[x] = 0;
    temp = MaximumClique(rem, cur, best);
    best = max(best, (int)temp.count());
    rem &= near[x];
    cur[x] = 1;
    cur = MaximumClique(rem, cur, best);
    if (temp.count() > cur.count())
    {
        return temp;
    }
    return cur;
}
