//https://www.hackerrank.com/challenges/tree-top-view/problem

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

void topView(Node *root)
{
    using nodeDist = std::pair<Node *, int>;
    if (root == nullptr)
    {
        return;
    }

    std::map<int, std::list<Node *>> disMap;
    std::queue<nodeDist> nodesQueue;
    nodesQueue.push(nodeDist(root, 0));
    while (!nodesQueue.empty())
    {
        auto item = nodesQueue.front();
        nodesQueue.pop();
        auto mapItem = disMap.find(item.second);
        if (mapItem == disMap.end())
        {
            //there is not such element
            disMap[item.second] = std::list<Node *>{item.first};
        }
        else
        {
            mapItem->second.push_back(item.first);
        }
        if (item.first->left != nullptr)
        {
            nodesQueue.push(nodeDist{item.first->left, item.second - 1});
        }
        if (item.first->right != nullptr)
        {
            nodesQueue.push(nodeDist{item.first->right, item.second + 1});
        }
    }
    for (auto &item : disMap)
    {
        std::cout << item.second.front()->data << " ";
    }
}
