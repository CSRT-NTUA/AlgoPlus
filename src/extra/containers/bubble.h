/**
* This is the bubble data structure, we highly suggest to initialize it with a various range of elements
* like {-500, -100, 0, 100, 500}(for _SIZE=5) if you want to use elements from [-500, 500]. In the future, we will
* work on making it more generic and make the list change, for example, if the user give {-2, -1, 0, 1, 2} and always
* insert keys with value > 2, then bubble will not work efficiently, so this has to change in the future
*/

#ifndef BUBBLE_H
#define BUBBLE_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#include <optional>
#include <ranges>
#include <algorithm>
#include <utility>
#include <cassert>
#include "../../classes/tree/avl_tree.h"
#endif

template <typename T, size_t _SIZE>
class bubble {
private:
    std::vector<std::pair<T, std::optional<avl_tree<T>>>> list;
    size_t _size;

public:
    explicit bubble() noexcept : _size(0) { }

    template <size_t _NEW_SIZE>
    bubble(const bubble<T, _NEW_SIZE> &t) noexcept : _size(t._size) {
        try {
            if(_NEW_SIZE != _SIZE) { throw std::logic_error("Tried to copy bubbles with different sizes"); }
            this->list = t.list;
        }
        catch (std::logic_error &e){
            std::cerr << e.what() << '\n';
        }
    }

    template <typename... Args>
    void insert(Args&& ...keys);

    template <typename... Args>
    void remove(Args&& ...keys);

    bool search(const T& key);

    size_t size();

    bool empty();

    std::vector<T> operator[] (const size_t& index) const {
        assert(index < this->_size && index >= 0);
        if(this->list[index].second == std::nullopt) { return {this->list[index].first}; }
        return this->list[index].second.value().inorder();
    }

    friend std::ostream & operator << (std::ostream &out, const bubble<T, _SIZE> &t){
        if(t._size == 0) { return out; }
        for(auto && x : t.list) {
            out << x.first << ": {";
            if(x.second == std::nullopt){
                out << "}" << '\n';
                continue;
            }
            avl_tree<T> tmp_tree(x.second.value());
            std::vector<T> ino = tmp_tree.inorder();
            for(size_t i = 0; i<ino.size(); i++){
                if(i == ino.size() - 1) {
                    out << ino[i];
                }
                else{
                    out << ino[i] << " ";
                }
            }
            out << "}" << '\n';
        }
        return out;
    }
};

template <typename T, size_t _SIZE>
template <typename... Args>
inline void bubble<T, _SIZE>::insert(Args&& ...keys) {
    auto _insert = [&](const T&& key) -> void {
        if(_size < _SIZE) {
            list.push_back({key, std::nullopt});
            _size++;
            return;
        }
        if(_size == _SIZE) {
            std::ranges::sort(list, [](const std::pair<T, std::optional<avl_tree<T>>> &a, const std::pair<T, std::optional<avl_tree<T>>> &b){
                return a.first < b.first;
            });
        }

        auto it = std::lower_bound(std::ranges::begin(this->list), std::ranges::end(this->list), key, [](const std::pair<T, std::optional<avl_tree<T>>> &pair, const T &key){ return pair.first < key; });

        if(it != std::ranges::end(this->list)) {
            int idx = std::distance(std::ranges::begin(this->list), it);
            if(this->list[idx].first == key) { return; }

            if(idx - 1 < 0){
                if(this->list[0].second == std::nullopt) {
                    this->list[0].second = avl_tree<T>();
                }
                // if(this->list[0].first == key) { return; } I think we don't need this
                this->list[0].second.value().insert(key);
            }
            else{
                if(this->list[idx - 1].second == std::nullopt) {
                    this->list[idx - 1].second = avl_tree<T>();
                }
                // if(this->list[idx].first == key) { return; }
                this->list[idx - 1].second.value().insert(key);
            }
        }
        else {
            if(this->list[this->list.size() - 1].second == std::nullopt){
                this->list[this->list.size() - 1].second = avl_tree<T>();
            }
            // if(this->list[this->list.size() - 1].first == key) { return; }
            this->list[this->list.size() - 1].second.value().insert(key);
        }
        _size++;
    };
    (std::invoke(_insert, std::forward<Args>(keys)), ...);
}


/**
* For now remove function can't remove key elements that exist on the list
* It can only remove them if none of the nodes have a tree yet.
* We have to find a way to make the tree rebalance itself and the root of the tree come on top
* after a removal of a key element
*/
template <typename T, size_t _SIZE>
template <typename... Args>
void bubble<T, _SIZE>::remove(Args&& ...keys) {
    auto _remove = [&](const T& key) -> void{
        if(this->_size == 0) { return; }
        if(this->_size <= _SIZE) {
            auto [begin, end] = std::ranges::remove_if(this->list, [&](const std::pair<T, std::optional<avl_tree<T>>> &t) { return t.first == key; });
            list.erase(begin, end);
            _size--;
        }
        else{
            auto it = std::lower_bound(std::ranges::begin(this->list), std::ranges::end(this->list), key, [](const std::pair<T, std::optional<avl_tree<T>>> &pair, const T &key){ return pair.first < key; });
            if(it != std::ranges::end(this->list)) {
                size_t idx = std::ranges::distance(std::ranges::begin(this->list), it);

                if(this->list[idx].first == key && this->list[idx].second != std::nullopt) {
                    T curr_root = this->list[idx].second.value().get_root();
                    this->list[idx].second.value().remove(curr_root);
                    this->list[idx].first = curr_root;
                    return;
                }

                if(idx - 1 < 0){
                    if(this->list[0].second == std::nullopt){
                        return;
                    }
                    this->list[0].second.value().remove(key);
                }
                else{
                    if(this->list[idx - 1].second == std::nullopt) {
                        return;
                    }
                    this->list[idx - 1].second.value().remove(key);
                }
            }
            else {
                if(this->list[this->list.size() - 1].second == std::nullopt) {
                    return;
                }
                this->list[this->list.size() - 1].second.value().remove(key);
            }
            _size--;
        }
    };
    (std::invoke(_remove, std::forward<Args>(keys)), ...);
}

template <typename T, size_t _SIZE>
bool bubble<T, _SIZE>::search(const T& key) {
    if(this->_size == 0) { return false; }
    auto it = std::lower_bound(std::ranges::begin(this->list), std::ranges::end(this->list), key, [](const std::pair<T, std::optional<avl_tree<T>>> &pair, const T &key){ return pair.first < key; });
    if (it != std::ranges::end(this->list)){
        size_t idx = std::ranges::distance(std::ranges::begin(this->list), it);
        if(idx - 1 < 0){
            if(this->list[0].first == key) { return true; }
            if(this->list[0].second == std::nullopt) { return false; }
            if(this->list[0].second.value().search(key) == true) { return true; }
        }
        else {
            if(this->list[idx].first == key) { return true; }
            if(this->list[idx - 1].second == std::nullopt) { return false; }
            if(this->list[idx - 1].second.value().search(key) == true) { return true; }
        }
    }
    else {
        if(this->list[this->list.size() - 1].first == key) { return true; }
        if(this->list[this->list.size() - 1].second == std::nullopt) { return false; }
        if(this->list[this->list.size() - 1].second.value().search(key) == true) { return true; }
    }
    return false;
}

template <typename T, size_t _SIZE>
size_t bubble<T, _SIZE>::size() {
    return this->_size;
}

template <typename T, size_t _SIZE>
bool bubble<T, _SIZE>::empty() {
    return this->_size == 0;
}

#endif
