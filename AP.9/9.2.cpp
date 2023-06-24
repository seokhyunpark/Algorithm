#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

typedef struct node *node_ptr;

typedef struct node {
    char symbol;
    int frequency;
    node_ptr left;
    node_ptr right;
} node_t;

struct compare {
    bool operator()(node_ptr p, node_ptr q) {
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<node_ptr, vector<node_ptr>, compare> PriorityQueue;

node_ptr create_node(char symbol, int frequency) {
    node_ptr node = (node_ptr)malloc(sizeof(node_t));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL; node->right = NULL;
    return node;
}

void huffman(int n, PriorityQueue &PQ) {
    for (int i = 1; i <= n - 1; i++) {
        node_ptr p = PQ.top(); PQ.pop();
        node_ptr q = PQ.top(); PQ.pop();
        node_ptr r = create_node('+', p->frequency + q->frequency);
        r->left = p;
        r->right = q;
        PQ.push(r);
    }
}

void preorder(node_ptr root) {
    if (root != NULL) {
        cout << root->symbol << ":" << root->frequency << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node_ptr root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->symbol << ":" << root->frequency << " ";
        inorder(root->right);
    }
}

void make_enoder(node_ptr node, string code, map<char, string> &encoder) {
    if (node->symbol != '+') {
        encoder[node->symbol] = code;
    }
    else {
        make_enoder(node->left, code + "0", encoder);
        make_enoder(node->right, code + "1", encoder);
    }
}

void decode(node_ptr root, node_ptr node, string s, int i) {
    if (i <= s.length()) {
        if (node->symbol != '+') {
            cout << node->symbol;
            decode(root, root, s, i);
        }
        else {
            if (s[i] == '0')
                decode(root, node->left, s, i + 1);
            else
                decode(root, node->right, s, i + 1);
        }
    }
}


int main() {
    int n; cin >> n;
    vector<char> symbol(n);
    vector<int> frequency(n);
    for (int i = 0; i < n; i++)
        cin >> symbol[i];
    for (int i = 0; i < n; i++)
        cin >> frequency[i];
    PriorityQueue PQ;
    for (int i = 0; i < n; i++) {
        node_ptr node = create_node(symbol[i], frequency[i]);
        PQ.push(node);
    }
    huffman(n, PQ);
    node_ptr root = PQ.top();
    preorder(root); cout << endl;
    inorder(root); cout << endl;

    map<char, string> encoder;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        make_enoder(root, "", encoder);
        for (int j = 0; j < s.length(); j++)
            cout << encoder[s[j]];
        cout << endl;
    }
    map<char, string> decoder;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        decode(root, root, s, 0);
        for (int j = 0; j < s.length(); j++)
            cout << decoder[s[j]];
        cout << endl;
    }



    return 0;
}
