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

Node* sortedBuildTreeHelper(vector<int>& nodes, int si, int ei) {
    if(si>ei) return NULL;

    int mid = si + (ei-si)/2;
    Node* curr = new Node(nodes[mid]);

    curr->left = sortedBuildTreeHelper(nodes, si, mid-1);
    curr->right = sortedBuildTreeHelper(nodes, mid+1, ei);

    return curr;
}

Node* sortedBuildTree(vector<int>& nodes) {
    return sortedBuildTreeHelper(nodes, 0, nodes.size()-1);
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
  Node* root = sortedBuildTree(nodes);
  cout << "Level Order:\n";
  levelOrder(root);
  cout << "In Order: ";
  inOrder(root);
  cout << endl;
}
