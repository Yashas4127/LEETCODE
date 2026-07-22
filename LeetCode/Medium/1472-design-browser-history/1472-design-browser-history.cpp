
class Node {

public:
    string data;
    Node *next, *prev;

    Node(string val) {
        data = val;
        next = prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* current;

    BrowserHistory(string homepage) { current = new Node(homepage); }

    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    string back(int steps) {
        while (steps && current->prev) {
            current = current->prev;
            steps--;
        }
        return current->data;
    }
    string forward(int steps) {
        while (steps && current->next) {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */