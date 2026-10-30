#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    right=left=NULL;
  }
};

Node* searchIdx(Node* root, int num) {
    if(root->left == NULL && root->right == NULL) return root;
    else if(num < root->data) {
        if(root->left==NULL) {
            return root;
        }
        return searchIdx(root->left, num);
    }
    else {
        if(root->right==NULL) {
            return root;
        }
        return searchIdx(root->right, num);
    }
}

Node* buildTree(vector<int>& nodes) {
    Node* root = new Node(nodes[0]);

    for(int i=1; i<nodes.size(); i++) {
        Node* currNode = new Node(nodes[i]);
        Node* prevNode = searchIdx(root, currNode->data);
        if(currNode->data > prevNode->data)
            prevNode->right = currNode;
        else prevNode->left = currNode;
    }

    return root;
}

void inOrder(Node* root) {
    if(root == NULL) return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if(currNode==NULL) {
            cout << endl;
            if(q.empty()) break;
            q.push(NULL);
            continue;
        }

        cout << currNode->data << ' ';
        if(currNode->left != NULL) q.push(currNode->left);
        if(currNode->right != NULL) q.push(currNode->right);
    }
}

int main()
{
  int n;
  cout << "How many nodes you want to enter: ";
  cin >> n;
  vector<int> nodes(n);
  cout << "Enter Nodes:\n";
  for(int i=0; i<n; i++) {
    cin >> nodes[i];
  }
  Node* root = buildTree(nodes);
  cout << "Level Order:\n";
  levelOrder(root);
  cout << "In Order: ";
  inOrder(root);
  cout << endl;
}
