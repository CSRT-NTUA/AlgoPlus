#ifndef ROPE_H
#define ROPE_H

#ifdef TREE_VISUALIZATION_H
#include "../../visualization/tree_visual/tree_visualization.h"
#endif

#ifdef __cplusplus
#include <iostream>
#include <memory>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>
#endif

class rope {
    struct node {
        int64_t len;
        bool is_leaf;
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
        std::string data;

        explicit node(int64_t len, std::shared_ptr<node> left, std::shared_ptr<node> right) {
            this->len = len;
            this->is_leaf = false;
            this->left = left;
            this->right = right;
        }

        explicit node(std::string s) {
            this->len = s.size();
            this->is_leaf = true;
            this->left = nullptr;
            this->right = nullptr;
            this->data = s;
        }
    };

    void _inorder(std::function<void(std::shared_ptr<node>)> callback,
                   std::shared_ptr<node> root) {
      if (root) {
        _inorder(callback, root->left);
        callback(root);
        _inorder(callback, root->right);
      }
    }

    std::vector<std::shared_ptr<node> > ropes;
    std::shared_ptr<node> root;

public:

    explicit rope(std::string s, int64_t splits = 2) : root(nullptr) {
        this->create(s, splits);
    }

    void create(std::string s, int64_t splits = 2);

    std::string inorder();

    #ifdef TREE_VISUALIZATION_H
    void visualize() {
      std::string _generated = generate_visualization();
      tree_visualization::visualize(_generated);
    }
    #endif

private:
    std::string generate_visualization() {
    std::string _generate = _inorder_gen(root);
    return _generate;
    }

    std::string _inorder_gen(std::shared_ptr<node> root) {
        std::string _s;
        if (root->left) {
            if(root->is_leaf) {
                _s += root->data;
            }
            else {
                _s += std::to_string(root->len);
            }
            _s += "->";
            if(root->left->is_leaf) {
                _s += root->left->data;
            }
            else {
                _s += std::to_string(root->left->len);
            }
            _s += "\n";
            _s += _inorder_gen(root->left);
        }
        if (root->right) {
            if(root->is_leaf){
                _s += root->data;
            }
            else {
                _s += std::to_string(root->len);
            }
            _s += "->";
            if(root->right->is_leaf){
                _s += root->right->data;
            }
            else {
                _s += std::to_string(root->right->len);
            }
            _s += "\n";
            _s += _inorder_gen(root->right);
        }
        return _s;
    }
};

void rope::create(std::string s, int64_t splits) {
    assert(s.size() >= splits);

    std::string s1 = s.substr(0, (int(s.size()) / 2) + 1);
    std::string s2 = s.substr(int(s.size()) / 2 + 1, int(s.size()) - int(s.size() / 2));
    std::shared_ptr<node> split1 = std::make_shared<node>(s1);
    std::shared_ptr<node> split2 = std::make_shared<node>(s2);

    std::shared_ptr<node> root_block = std::make_shared<node>(s.size(), split1, split2);
    root = root_block;
    splits--;


    auto split_tree = [&](int64_t splits) -> void {
        std::queue<std::shared_ptr<node> > q;
        q.push(root);

        while(splits){
            q = std::queue<std::shared_ptr<node> >{};
            q.push(root);
            while(!q.empty()){
                int64_t size = q.size();
                for(int64_t i = 0; i<size; i++){
                    std::shared_ptr<node> curr = q.front();
                    q.pop();
                    if(splits <= 0){
                        break;
                    }
                    if(curr -> is_leaf == true){
                        std::string s1 = (curr -> data).substr(0, int(curr -> len) / 2 + 1);
                        std::string s2 = (curr -> data).substr(int(curr -> len) / 2 + 1, int(curr -> len) - int(curr -> len) / 2);
                        std::shared_ptr<node> split1 = std::make_shared<node>(s1);
                        std::shared_ptr<node> split2 = std::make_shared<node>(s2);

                        std::shared_ptr<node> block_node = std::make_shared<node>(curr -> len, split1, split2);
                        curr = block_node;
                        splits--;
                    }

                    if(curr -> left != nullptr) { q.push(curr -> left); }
                    if(curr -> right != nullptr) { q.push(curr -> right); }
                }
            }
        }
    };

    split_tree(splits);
}

std::string rope::inorder() {
    std::string path;
    _inorder(
        [&](std::shared_ptr<node> callbacked) {
            if(callbacked -> is_leaf == true){
                path += callbacked -> data;
            }
        },
        root);
    return path;
}

#endif
