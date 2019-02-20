//
// Created by ZaberKo on 2019-02-15.
//

#ifndef DATASTRUCTURE_AVLTREE_H
#define DATASTRUCTURE_AVLTREE_H

#include <algorithm>
#include <vector>

template<typename Key, typename Value>
class AVLTree {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        int height;

        Node(const Key &key, const Value &value) {
            this->key = key;
            this->value = value;
            this->right = this->left = nullptr;
            this->height = 0;
        }

        Node(const Node &&node) {
            this->key = node.key;
            this->value = node.value;
            this->right = node.right;
            this->left = node.left;
            this->height = node.height;
        }
    };

    Node *root;
    int size;


public:
    void Add(Key key, Value value) {
        root = Add(root, key, value);
    }

    bool IsBST() {
        std::vector<Key> vec(size);
        InOrder(root, vec);

        for (int i = 0; i < vec.size() - 1; ++i) {
            if (vec[i] > vec[i + 1])
                return false;

        }
        return true;
    }

    bool IsBalanced() {
        return IsBalanced(root);
    }

    Value *Remove(const Key &key) {
        root = Remove(root, key);
    }

private:
    int get_height(Node *node) {
        if (node)
            return node->height;
        else
            return 0;
    }

    //return insert node's root
    Node *Add(Node *node, Key key, Value value) {
        if (node == nullptr) {
            size++;
            return new Node(key, value);
        }

        if (key < node->key)
            node->left = Add(node->left, key, value);
        else if (key > node->key)
            node->right = Add(node->right, key, value);
        else
            node->value = value;

        //update height
        UpdateHeight(node);

        //rotate
        node = Rotate(node);

        return node;
    }

    Node *Rotate(Node *node) {

        int bf = get_balanced_factor(node);
        int bf_l = get_balanced_factor(node->left);
        int bf_r = get_balanced_factor(node->right);

        //LL
        if (bf > 1 && bf_l >= 0) {
            return RightRotate(node);
        }

        //RR
        if (bf < 1 && bf_r <= 0) {
            return LeftRotate(node);
        }

        //LR
        if (bf > 1 && bf_l < 0) {
            node->left = LeftRotate(node->left);
            return RightRotate(node);
        }

        //RL
        if (bf < -1 && bf_r > 0) {
            node->right = RightRotate(node->right);
            return LeftRotate(node);
        }

        return node;
    }

    Node *RightRotate(Node *y) {
        Node *x = y->left;
        Node *t3 = x->right;

        x->right = y;
        y->left = t3;


        //Beware of the update order
        UpdateHeight(y);
        UpdateHeight(x);

        return x;
    }

    Node *LeftRotate(Node *y) {
        Node *x = y->right;
        Node *t2 = x->left;

        x->left = y;
        y->right = t2;


        //Beware of the update order
        UpdateHeight(y);
        UpdateHeight(x);

        return x;
    }

    Node *Remove(Node *node, const Key &key) {
        if (node == nullptr)
            return nullptr;

        Node *resultNode;
        if (key < node->key) {
            node->left = remove(node->left, key);
            resultNode = node;
        } else if (key > node->key) {
            node->right = remove(node->right, key);
            resultNode = node;
        } else {

            if (node->left == nullptr) {
                resultNode = node->right;
                delete node;
                size--;
            } else if (node->right == nullptr) {
                resultNode = node->right;
                delete node;
                size--;
            } else {
                Node *successor = new Node(get_min(node->right));
                successor->right = Remove(node->right, successor->key);
                successor->left = node->left;
                delete node;
                resultNode=successor;
            }

            if(resultNode== nullptr)
                return resultNode;

            UpdateHeight(resultNode);

            resultNode=Rotate(resultNode);

            return resultNode;
        }
    }


    void UpdateHeight(Node *node) {
        node->height = 1 + max(get_height(node->left), get_height(node->right));
    }

    void InOrder(const Node *node, std::vector<Key> &vec) {
        if (node == nullptr)
            return;

        InOrder(node->left, vec);
        vec.push_back(node->key);
        InOrder(node->right);
    }

    bool IsBalanced(Node *node) {
        if (node == nullptr)
            return true;

        int bf = get_balanced_factor(node);
        if (abs(bf) > 1)
            return false;
        return IsBalanced(node->left) && IsBalanced(node->right);
    }


    int get_balanced_factor(Node *node) {
        if (node == nullptr)
            return 0;

        return get_height(node->left) - get_height(node->right);
    }


    Node *get_min(Node *node) {
        if (node->left == nullptr)
            return node;

        return minimum(node->left);
    }

    // 删除掉以node为根的二分搜索树中的最小节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node *RemoveMin(Node *node) {

        if (node->left == NULL) {

            Node *rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }

        node->left = removeMin(node->left);
        node = Rotate(node);
        return node;
    }
};


#endif //DATASTRUCTURE_AVLTREE_H
