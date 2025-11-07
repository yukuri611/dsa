#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Node {
   public:
    int val;
    Node* prev;
    Node* nxt;

    Node(int val) : val(val), prev(NULL), nxt(NULL) {}
};

struct LinkedList {
    Node* head;
    Node* tail;

   public:
    void push(Node* node) {
        node->prev = tail->prev;
        tail->prev->nxt = node;
        node->nxt = tail;
        tail->prev = node;
    }
    void erase(Node* node) {
        node->prev->nxt = node->nxt;
        node->nxt->prev = node->prev;
    }
    void insert(Node* front, Node* node) {
        node->nxt = front->nxt;
        front->nxt->prev = node;
        front->nxt = node;
        node->prev = front;
    }
    LinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->nxt = tail;
        tail->prev = head;
    }

    ~LinkedList() {
        Node* current = head->nxt;
        while (current != tail) {
            Node* next = current->nxt;
            delete current;  // データノードを解放
            current = next;
        }
        delete head;  // head 番兵を解放
        delete tail;  // tail 番兵を解放
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    map<int, Node*> Map;
    LinkedList linkedlist;
    rep(i, N) {
        int a;
        cin >> a;
        Node* newNode = new Node(a);
        linkedlist.push(newNode);
        Map[a] = newNode;
    }

    int Q;
    cin >> Q;
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int x, y;
            cin >> x >> y;
            Node* newNode = new Node(y);
            linkedlist.insert(Map[x], newNode);
            Map[y] = newNode;
        } else {
            int x;
            cin >> x;
            linkedlist.erase(Map[x]);
            Map.erase(x);
        }
    }

    Node* curr = linkedlist.head;
    curr = curr->nxt;
    while (curr != linkedlist.tail) {
        cout << curr->val << " ";
        curr = curr->nxt;
    }
    cout << endl;
    return 0;
}
