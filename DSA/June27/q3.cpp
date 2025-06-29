class doubleNode{
    public:
    string url;
    doubleNode* next;
    doubleNode* prev;

    doubleNode(string u): url(u), next(nullptr), prev(nullptr){};
    doubleNode(string u, doubleNode* n, doubleNode* p): url(u), next(n), prev(p){};

};


class BrowserHistory {
    doubleNode* head;
    doubleNode* curr;
public:
    BrowserHistory(string homepage) {
        head = new doubleNode(homepage);
        curr = head;
    }
    
    void visit(string url) {
        curr->next = new doubleNode(url,nullptr,curr);
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps){
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next && steps){
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */