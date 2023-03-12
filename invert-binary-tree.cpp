#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// create a tree given a vector of input elements
// returns root of tree
TreeNode *createTree(vector<int> input) {
  queue<TreeNode *> nodes;
  TreeNode *node, *parent, *root;

  if (input.size() == 0) {
    return nullptr;
  }

  // First element of input vector will always be the root node
  root = new TreeNode(input[0]);

  if (input.size() == 1) {
    return root;
  }

  parent = root;
  bool isLeftFilled = false;

  for (long unsigned int i = 1; i < input.size(); i++) {
    // cout << input[i] << ": ";
    if (input[i] != NULL) {
      node = new TreeNode(input[i]);
      // add node to queue
      nodes.push(node);
      if (!isLeftFilled) {
        parent->left = node;
        // cout << "adding " << node->val << " to left of " << parent->val << endl;
        isLeftFilled = true;
      } else {
        parent->right = node;
        // cout << "adding " << node->val << " to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
      // cout << "adding " << node->val << " to " << parent->val << endl;
    } else {
      if (!isLeftFilled) {
        parent->left = nullptr;
        isLeftFilled = true;
        // cout << "adding null to left of " << parent->val << endl;
      } else {
        parent->right = nullptr;
        // cout << "adding null to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
    }
  }

  return root;
}

void printTree(TreeNode *root) {
  TreeNode *node;
  queue<TreeNode *> q;

  if (root == nullptr)
    return;

  // Root node does not have any child nodes
  if ((root->left == nullptr) && (root->right == nullptr)) {
    cout << root->val << endl;
    return;
  }

  q.push(root);

  while (!q.empty()) {
    if (q.front() == nullptr) {
      cout << "NULL, ";

    } else {
      node = q.front();
      cout << node->val << ", ";

      q.push(node->left);

      q.push(node->right);
    }
    q.pop();
  }

  cout << endl;
}

// Add root node to the queue
// Traverse through the tree using the queue
// Swap left and right of each node
// Add the left and right to the end of the queue
TreeNode *invertTree(TreeNode *root) {
  TreeNode *node = root;

  // Root is null
  if (root == nullptr) {
    return nullptr;
  }

  // Root node does not have any child nodes
  if ((root->left == nullptr) && (root->right == nullptr)) {
    return root;
  }

  queue<TreeNode *> q;

  q.push(root);

  // Traverse the tree
  while (!q.empty()) {
    node = q.front();
    swap(node->left, node->right);
    if (node->left != nullptr)
      q.push(node->left);
    if (node->right != nullptr)
      q.push(node->right);
    q.pop();
  }

  return root;
}

int main(int argc, char const *argv[]) {
  vector<int> input1 = {3, 9, 20, NULL, NULL, 15, 7};
  vector<int> input2 = {1};
  vector<int> input3 = {1, 7, 9, 2, 6, NULL, 9, NULL, NULL, 5, 11, 5, NULL};
  vector<int> input4 = {1, 2, 3, 4, 5};

  vector<int> input5 = {2, 1, 3};             // valid binary search tree
  vector<int> input6 = {17, 5, NULL, 1, 15};  // valid binary search tree

  vector<int> input7 = {25, 5, NULL, NULL, 15, 10, 30};
  vector<int> input8 = {25, 5, NULL, NULL, 15, 4, 20};

  TreeNode *root = createTree(input8);
  printTree(root);

  return 0;
}
