#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#ifdef __cplusplus
#include <iostream>
#endif

template <typename T>
class circular_linked_list
{
public:
    explicit circular_linked_list(std::vector<T> __elements = {}) noexcept
        : root(nullptr), tail(nullptr), __size(0)
    {
        if (!__elements.empty())
        {
            for (T &x : __elements)
            {
                this->push_back(x);
            }
        }
    }

    bool empty() { return root == nullptr; }

    size_t size() { return __size; }

    void push_back(T key)
    {
        std::shared_ptr<node> p = std::make_shared<node>(key);
        if (root == nullptr)
        {
            root = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
        tail->next = root; 
        __size++;
    }

    void push_front(T key)
    {
        std::shared_ptr<node> p = std::make_shared<node>(key);
        if (root == nullptr)
        {
            root = p;
            tail = p;
        }
        else
        {
            p->next = root;
            root = p;
            tail->next = root;
        }
        __size++;
    }

    void erase(T key)
    {
        if (empty())
        {
            return;
        }

        std::shared_ptr<node> t = root;
        std::shared_ptr<node> to_be_removed = nullptr;

        do
        {
            if (t->next->val == key)
            {
                to_be_removed = t->next;
                t->next = t->next->next;
                to_be_removed.reset();
                __size--;

                if (t->next == root)
                {
                    tail = t; 
                }

                if (root == tail)
                {
                    tail = nullptr;
                }

                return;
            }

            t = t->next;
        } while (t != root);
    }

    bool search(T key)
    {
        try
        {
            if (empty())
            {
                return false;
            }
            else
            {
                std::shared_ptr<node> t = root;
                do
                {
                    if (t->val == key)
                    {
                        return true;
                    }
                    t = t->next;
                } while (t != root);

                return false;
            }
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }

    std::vector<T> elements()
    {
        std::vector<T> __elements;

        if (this->empty())
        {
            return __elements;
        }

        std::shared_ptr<node> head = root;
        do
        {
            __elements.push_back(head->val);
            head = head->next;
        } while (head != root);

        return __elements;
    }

    friend std::ostream &operator<<(std::ostream &out, circular_linked_list<T> &l1)
    {
        out << '{';
        std::shared_ptr<node> head = l1.root;
        do
        {
            out << head->val << ' ';
            head = head->next;
        } while (head != l1.root);
        out << '}' << '\n';
        return out;
    }

private:
    struct node
    {
        T val;
        std::shared_ptr<node> next;
        node(T key = 0) : val(key), next(nullptr) {}
    };

    std::shared_ptr<node> root;
    std::shared_ptr<node> tail;
    size_t __size;
};

#endif