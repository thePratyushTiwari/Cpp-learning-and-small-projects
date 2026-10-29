#include<iostream>
#include<vector>
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

void inOrder(Node* root) {
  if(root==NULL) return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

int main()
{
  vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root = buildTree(nodes);
  inOrder(root);
  cout << '\n';
  return 0;
}
