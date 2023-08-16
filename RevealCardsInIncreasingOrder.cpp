vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    if (deck.size() <= 2)
        return deck;
    vector<int> ans;
    sort(deck.begin(), deck.end());
    deque<int> q;
    q.push_back(deck.back());
    deck.pop_back();
    q.push_front(deck.back());
    deck.pop_back();
    while (deck.size())
    {
        int last = q.back();
        q.pop_back();
        q.push_front(last);
        q.push_front(deck.back());
        deck.pop_back();
    }
    while (q.size())
    {
        deck.push_back(q.front());
        q.pop_front();
    }
    return deck;
}