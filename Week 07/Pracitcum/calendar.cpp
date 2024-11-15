struct Node
{
    pair<int, int> time = { 0, 0 };
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int start, int end) : time(start, end) {}
};

class MyCalendar {
private:
    Node* root = nullptr;

public:
    bool insert(Node* curr, int startTime, int endTime)
    {
        if (startTime < curr->time.second && endTime > curr->time.first)
        {
            return false;
        }

        if (startTime >= curr->time.second)
        {
            if (curr->right)
            {
                return insert(curr->right, startTime, endTime);
            }

            else
            {
                curr->right = new Node(startTime, endTime);
                return true;
            }
        }

        else
        {
            if (curr->left)
            {
                return insert(curr->left, startTime, endTime);
            }

            else
            {
                curr->left = new Node(startTime, endTime);
                return true;
            }
        }
    }

    bool book(int startTime, int endTime) {

        if (!root)
        {
            root = new Node(startTime, endTime);
            return true;
        }

        else
        {
            return insert(root, startTime, endTime);
        }

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */