#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    Node* head, * tail;
};

void solve(LinkedList& num1, LinkedList& num2) {

    long long sum = 0;

    Node* currF = num1.head;
    Node* currS = num2.head;

    int carry = 0;

    vector<int> res;

    while (currF && currS)
    {
        int digit = currF->data + currS->data + carry;
        if (digit >= 10)
        {
            carry = digit / 10;
            digit %= 10;
        }

        else
        {
            carry = 0;
        }

        res.push_back(digit);

        currF = currF->next;
        currS = currS->next;
    }

    while (currF)
    {
        int digit = currF->data + carry;
        if (digit >= 10)
        {
            carry = digit / 10;
            digit %= 10;
        }

        else
        {
            carry = 0;
        }

        res.push_back(digit);

        currF = currF->next;
    }

    while (currS)
    {
        int digit = currS->data + carry;
        if (digit >= 10)
        {
            carry = digit / 10;
            digit %= 10;
        }

        else
        {
            carry = 0;
        }

        res.push_back(digit);

        currS = currS->next;
    }

    if (carry)
    {
        res.push_back(carry);
    }

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }

}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}