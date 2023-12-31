#ifdef __cplusplus
#include <functional>
#include <vector>
#endif

template <typename T> class avl_tree {
public:
  avl_tree() : root(nullptr) {}
  ~avl_tree() {}

  void insert(T key) { root = __insert(root, key); }

  void remove(T key) { root = __remove(root, key); }

  std::vector<T> inorder() {
    std::vector<T> path;
    __inorder([&](node *callbacked) { path.push_back(callbacked->info); },
              root);
    return path;
  }

  std::vector<T> preorder() {
    std::vector<T> path;
    __preorder([&](node *callbacked) { path.push_back(callbacked->info); },
               root);
    return path;
  }

  std::vector<T> postorder() {
    std::vector<T> path;
    __postorder([&](node *callbacked) { path.push_back(callbacked->info); },
                root);
    return path;
  }

private:
  typedef struct node {
    T info;
    int64_t height;
    struct node *left;
    struct node *right;
  } node;
  node *root;
  int64_t height(node *root) {
    if (root == NULL)
      return 0;
    return 1 + std::max(height(root->left), height(root->right));
  }

  node *createNode(int info) {
    node *nn = new node();
    nn->info = info;
    nn->height = 0;
    nn->left = NULL;
    nn->right = NULL;
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
    if (root->left == NULL)
      return root;
    return minValue(root->left);
  }

  node *__insert(node *root, int item) {
    node *nn = createNode(item);
    if (root == NULL)
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

  node *__remove(node *root, int key) {
    if (root == NULL)
      return root;
    if (key < root->info)
      root->left = __remove(root->left, key);
    else if (key > root->info)
      root->right = __remove(root->right, key);

    else {
      if (!root->right) {
        node *temp = root->left;
        delete (root);
        root = NULL;
        return temp;
      } else if (!root->left) {
        node *temp = root->right;
        delete (root);
        root = NULL;
        return temp;
      }
      node *temp = minValue(root->right);
      root->info = temp->info;
      root->right = __remove(root->right, temp->info);
    }
    return root;
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
};
