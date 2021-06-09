//https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem

class LRUCache final : public Cache
{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    }
    ~LRUCache()
    {
        for (auto &i : mp)
        {
            delete i.second;
        }
    }
    void set(int key, int value) override
    {
        const auto &it = mp.find(key);
        if (it == mp.end())
        {
            miss(key, value);
        }
        else
        {
            mp[key]->value = value;
        }
    }
    int get(int key) override
    {
        const auto &it = mp.find(key);
        if (it == mp.end())
        {
            return -1;
        }
        hit(it->second);
        return it->second->value;
    }

private:
    void hit(Node *node)
    {
        //if(node->prev == nullptr){ // node is the head
        if (head == node)
        {
            return;
        }

        Node *prev = node->prev; // for sure this is no null
        Node *next = node->next;
        Node *lastHead = head;
        node->prev = nullptr;
        node->next = lastHead;
        lastHead->prev = node;
        head = node;
        prev->next = next;
        if (next == nullptr)
        {
            tail = prev;
        }
        else
        {
            next->prev = prev;
        }
    }
    void drop_tail()
    {
        mp.erase(tail->key);
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    Node *insert_in_head(int key, int value)
    {
        auto new_head = new Node(nullptr, head, key, value);
        if (head != nullptr)
            head->prev = new_head;
        head = new_head;
        return new_head;
    }
    inline bool is_full()
    {
        return mp.size() > cp;
    }
    void miss(int key, int value)
    {
        Node *new_head = insert_in_head(key, value);
        if (tail == nullptr)
            tail = head;
        head = new_head;
        mp[key] = new_head;
        if (is_full())
        {
            drop_tail();
        }
    }
};