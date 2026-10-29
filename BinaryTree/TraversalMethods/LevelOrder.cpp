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

static int idx=-1;
Node* buildTree(vector<int>& nodes) {
  idx++;
  if(nodes[idx]==-1) return NULL;

  Node* currNode = new Node(nodes[idx]);
  currNode->left = buildTree(nodes);
  currNode->right = buildTree(nodes);
  
  return currNode;
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
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  levelOrder(root);
  return 0;
}
