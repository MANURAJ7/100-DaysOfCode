public:
class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};
Node *head = new Node(-1, -1);
Node *tail = new Node(-1, -1);

int size;
unordered_map<int, Node *> m;

LRUCache(int capacity)
{
    size = capacity;
    head->next = tail;
    tail->prev = head;
}

void addNode(Node *newNode)
{
    Node *temp = head->next;
    newNode->prev = head;
    newNode->next = temp;
    head->next = newNode;
    temp->prev = newNode;
}

void deleteNode(Node *delNode)
{
    Node *prevNode = delNode->prev;
    Node *nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

int get(int key)
{
    if (m.find(key) != m.end())
    {
        Node *resNode = m[key];
        int ans = resNode->val;

        deleteNode(resNode);
        addNode(resNode);

        return ans;
    }
    return -1;
}

void put(int key, int value)
{
    if (m.find(key) != m.end())
    {
        Node *curr = m[key];
        m.erase(key);
        deleteNode(curr);
    }
    if (m.size() == size)
    {
        m.erase(tail->prev->key);
        deleteNode(tail->prev);
    }
    addNode(new Node(key, value));
    m[key] = head->next;
}