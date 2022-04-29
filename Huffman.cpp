#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node {
  public:
  int freq = 0;
  char ch;
  Node *left, *right;

  Node(char ch, int freq) {
    this->ch = ch;
    this->freq = freq;
    this->left = nullptr;
    this->right = nullptr;
  }

  static Node *create_node(Node* left, Node* right) {
    auto node = new Node(' ', 0);
    node->left = left;
    node->right = right;
    node->freq = left->freq + right->freq;
    return node;
  }
};

string get_code(Node* root, char input, string base = "") {
  if (root->ch == input) return base;
  if (root->left) {
    auto left_code = get_code(root->left, input, base + "0");
    if (left_code != "?") return left_code;
  }
  if (root->right) {
    auto right_code = get_code(root->right, input, base + "1");
    if (right_code != "?") return right_code;
  }
  return "?";
}

struct compare {
  bool operator()  (Node* a, Node* b) {
    return a->freq > b->freq;
  }
};

int main() {
  priority_queue<Node*, vector<Node*>, compare>characters;
  vector<Node*> input = {new Node('h', 1), new Node('e', 1), new Node('l', 2), new Node('o', 3)};
  string s = "hellooo";
  for (int i = 0; i < input.size(); i++) {
    characters.push(input[i]);
  }
  while (characters.size() > 1) {
    Node* left = characters.top();
    characters.pop();
    Node* right = characters.top();
    characters.pop();
    auto t = Node::create_node(left, right);
    characters.push(t);
  }

  auto root = characters.top();
  for (int i = 0; i < s.size(); i++) {
    cout << get_code(root, s[i]) << " ";
  }
  cout << endl;

  return 0;
}
