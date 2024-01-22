#ifdef __cplusplus
#include "../../visualization/tree_visual/tree_visualization.h"
#include <functional>
#include <queue>
#include <string>
#include <vector>
#endif

/*
 *Class for AVL tree.
 */
template <typename T> class avl_tree {
public:
  /*
   *Contructor for AVL tree class.
   *@param __elements: you can directly pass a vector<T> so you don't have to do
   *insert multiple times.
   */
  explicit avl_tree(std::vector<T> __elements = {}) noexcept : root(nullptr) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->insert(x);
      }
    }
  }
  ~avl_tree() noexcept {}

  /*
   *insert function.
   *@param key: key to be inserted.
   */
  void insert(T key) { root = __insert(root, key); }

  /*
   *clear function
   *Erase all the nodes from the tree.
   */
  void clear() {
    free(root);
    return;
  }

  /*
   *search function.
   *@param key: key to be searched.
   */
  bool search(T key) { return __search(root, key); }

  /*
   *remove function.
   *@param key: key to be removed.
   */
  void remove(T key) { root = __remove(root, key); }

  /*
   *inorder function.
   *Returns vector<T>, the elements inorder.
   */
  std::vector<T> inorder() {
    std::vector<T> path;
    __inorder([&](node *callbacked) { path.push_back(callbacked->info); },
              root);
    return path;
  }
  /*
   *preorder function.
   *Returns vector<T>, the elements preorder.
   */
  std::vector<T> preorder() {
    std::vector<T> path;
    __preorder([&](node *callbacked) { path.push_back(callbacked->info); },
               root);
    return path;
  }
  /*
   *postorder function.
   *Returns vector<T>, the elements postorder.
   */
  std::vector<T> postorder() {
    std::vector<T> path;
    __postorder([&](node *callbacked) { path.push_back(callbacked->info); },
                root);
    return path;
  }

  /*
   *visualize function
   *Returns .dot file that can be previewed using graphviz in vscode.
   */
  void visualize() {
    std::string __generated = generate_visualization();
    visualization::visualize(__generated);
  }

private:
  /*
   *Struct for the node type pointer.
   *@param info: the value of the node.
   *@param height: height of each node.
   *@param left: pointer to the left.
   *@param right: pointer to the right.
   */
  typedef struct node {
    T info;
    int64_t height;
    struct node *left;
    struct node *right;
  } node;
  node *root;

  int64_t height(node *root) {
    if (root == nullptr)
      return 0;
    return 1 + std::max(height(root->left), height(root->right));
  }

  node *createNode(T info) {
    node *nn = new node();
    nn->info = info;
    nn->height = 0;
    nn->left = nullptr;
    nn->right = nullptr;
    return nn;
  }

  int64_t getBalance(node *root) {
    return height(root->left) - height(root->right);
  }

  node *rightRotate(node *root) {
    node *t = root->left;
    node *u = t->right;
    t->right = root;
    root->left = u;
    return t;
  }

  node *leftRotate(node *root) {
    node *t = root->right;
    node *u = t->left;
    t->left = root;
    root->right = u;
    return t;
  }

  node *minValue(node *root) {
    if (root->left == nullptr)
      return root;
    return minValue(root->left);
  }

  node *__insert(node *root, T item) {
    node *nn = createNode(item);
    if (root == nullptr)
      return nn;
    if (item < root->info)
      root->left = __insert(root->left, item);
    else
      root->right = __insert(root->right, item);
    int b = getBalance(root);
    if (b > 1) {
      if (getBalance(root->left) < 0)
        root->left = leftRotate(root->left); // Left-Right Case
      return rightRotate(root);              // Left-Left Case
    } else if (b < -1) {
      if (getBalance(root->right) > 0)
        root->right = rightRotate(root->right); // Right-Left Case
      return leftRotate(root);                  // Right-Right Case
    }
    return root;
  }

  node *__remove(node *root, T key) {
    if (root == nullptr)
      return root;
    if (key < root->info)
      root->left = __remove(root->left, key);
    else if (key > root->info)
      root->right = __remove(root->right, key);

    else {
      if (!root->right) {
        node *temp = root->left;
        delete (root);
        root = nullptr;
        return temp;
      } else if (!root->left) {
        node *temp = root->right;
        delete (root);
        root = nullptr;
        return temp;
      }
      node *temp = minValue(root->right);
      root->info = temp->info;
      root->right = __remove(root->right, temp->info);
    }
    return root;
  }

  bool __search(node *root, T key) {
    while (root) {
      if (root->info < key) {
        root = root->right;
      } else if (root->info > key) {
        root = root->left;
      } else {
        return true;
      }
    }
    return false;
  }

  void __inorder(std::function<void(node *)> callback, node *root) {
    if (root) {
      __inorder(callback, root->left);
      callback(root);
      __inorder(callback, root->right);
    }
  }

  void __postorder(std::function<void(node *)> callback, node *root) {
    if (root) {
      __inorder(callback, root->left);
      __inorder(callback, root->right);
      callback(root);
    }
  }

  void __preorder(std::function<void(node *)> callback, node *root) {
    if (root) {
      callback(root);
      __inorder(callback, root->left);
      __inorder(callback, root->right);
    }
  }

  std::string generate_visualization() {
    std::string __generate = __inorder_gen(root);
    return __generate;
  }

  std::string __inorder_gen(node *root) {
    std::string __s;
    if (std::is_same_v<T, char> || std::is_same_v<T, std::string>) {
      if (root->left) {
        __s += root->info;
        __s += "->";
        __s += root->left->info;
        __s += "\n";
        __s += __inorder_gen(root->left);
      }
      if (root->right) {
        __s += root->info;
        __s += "->";
        __s += root->right->info;
        __s += "\n";
        __s += __inorder_gen(root->right);
      }
    } else {
      if (root->left) {
        __s += std::to_string(root->info) + "->" +
               std::to_string(root->left->info) + "\n" +
               __inorder_gen(root->left);
      }
      if (root->right) {
        __s += std::to_string(root->info) + "->" +
               std::to_string(root->right->info) + "\n" +
               __inorder_gen(root->right);
      }
    }
    return __s;
  }
};
