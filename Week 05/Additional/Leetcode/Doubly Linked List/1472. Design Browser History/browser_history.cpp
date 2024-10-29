struct DoublyLinkedNode
{
    DoublyLinkedNode* prev = nullptr;
    string data;
    DoublyLinkedNode* next = nullptr;

    DoublyLinkedNode(string data)
    {
        this->data = data;
    }
};

class BrowserHistory {
    DoublyLinkedNode* browse = nullptr;
public:
    BrowserHistory(string homepage) {
        browse = new DoublyLinkedNode(homepage);
    }

    void visit(string url) {
        DoublyLinkedNode* goingTo = new DoublyLinkedNode(url);
        browse->next = goingTo;
        goingTo->prev = browse;
        browse = browse->next;
    }

    string back(int steps) {
        while (steps && browse->prev)
        {
            browse = browse->prev;
            steps--;
        }

        return browse->data;
    }

    string forward(int steps) {
        while (steps && browse->next)
        {
            browse = browse->next;
            steps--;
        }

        return browse->data;
    }

    ~BrowserHistory()
    {
        while (browse->prev)
        {
            browse = browse->prev;
        }

        while (browse)
        {
            DoublyLinkedNode* temp = browse->next;
            delete browse;
            browse = temp;
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */