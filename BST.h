//
// Created by ZaberKo on 2019-02-11.
//

#ifndef DATASTRUCTURE_BST_H
#define DATASTRUCTURE_BST_H


#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>


template<typename Key, typename Value>
class BST {

    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(const Key &key, const Value &value) {
            this->key = key;
            this->value = value;
            this->right = this->left = nullptr;
        }
    };

    Node *root;
    int count;
public:
    template<typename T>
    using vector=std::vector<T>;

    template<typename T>
    using stack=std::stack<T>;

    template<typename K, typename T>
    using pair=std::pair<K, T>;

    template<typename T>
    using queue=std::queue<T>;


    BST() {
        root = nullptr;
        count = 0;
    }

    ~BST() {
        std::cout << "start delete" << std::endl;
        if (root == nullptr)
            return;
        //traversed by postOrder
        stack<pair<Node *, bool>> stack;
        stack.push(make_pair(root, false));
        bool visited;

        while (!stack.empty()) {

            std::cout << "stack size: " << stack.size() << std::endl;
            Node *node = stack.top().first;
            visited = stack.top().second;
            stack.pop();

            if (visited) {
                delete node;
            } else {
                stack.push(make_pair(node, true));
                if (node->right)
                    stack.push(make_pair(node->right, false));
                if (node->left)
                    stack.push(make_pair(node->left, false));
            }
        }
    }


    int Size() {
        return count;

    }

    bool IsEmpty() {
        return count == 0;
    }

    void Insert(const Key &key, const Value &value) {
        Node *node = root;
        Node *prevNode = nullptr;

        if (root == nullptr) {
            root = new Node(key, value);
            count++;
            return;
        }

        while (node) {
            prevNode = node;
            if (key == node->key) {
                node->value = value;
                return;
            } else if (key < node->key) {
                node = node->left;
            } else { //key>node->key
                node = node->right;

            }
        }


        count++;
        node = new Node(key, value);
        InsertHelper(prevNode, node);

    }

    bool Contain(const Key &key) {
        Node *node = root;
        while (node) {
            if (key == node->key)
                return true;
            else if (key < node->key)
                node = node->left;
            else
                node = node->right;
        }
        return false;

    }

    Value *Search(const Key &key) {
        Node *node = root;
        while (node) {
            if (key == node->key)
                return &(node->value);
            else if (key < node->key)
                node = node->left;
            else
                node = node->right;
        }
        return nullptr;
    }


    void PreOrder(vector<Value> &vec) {
        if (root == nullptr)
            return;
        stack<Node *> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node *node = stack.top();
            stack.pop();
            vec.push_back(node->value);
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);

        }
    }

    void PreOrder2(vector<Value> &vec) {
        if (root == nullptr)
            return;
        //traversed by postOrder
        stack<pair<Node *, bool>> stack;
        stack.push(make_pair(root, false));
        bool visited;
        while (!stack.empty()) {
            Node *node = stack.top().first;
            visited = stack.top().second;
            stack.pop();
            if (visited) {
                vec.push_back(node->value);
            } else {
                if (node->right)
                    stack.push(make_pair(node->right, false));
                if (node->left)
                    stack.push(make_pair(node->left, false));
                stack.push(make_pair(node, true));
            }
        }
    }

    void InOrder(vector<Value> &vec) {
        if (root == nullptr)
            return;
        //traversed by postOrder
        stack<pair<Node *, bool>> stack;
        stack.push(make_pair(root, false));
        bool visited;
        while (!stack.empty()) {
            Node *node = stack.top().first;
            visited = stack.top().second;
            stack.pop();
            if (visited) {
                vec.push_back(node->value);
            } else {
                if (node->right)
                    stack.push(make_pair(node->right, false));
                stack.push(make_pair(node, true));
                if (node->left)
                    stack.push(make_pair(node->left, false));
            }
        }
    }

    void PostOrder(vector<Value> &vec) {
        if (root == nullptr)
            return;
        //traversed by postOrder
        stack<pair<Node *, bool>> stack;
        stack.push(make_pair(root, false));
        bool visited;
        while (!stack.empty()) {
            Node *node = stack.top().first;
            visited = stack.top().second;
            stack.pop();
            if (visited) {
                vec.push_back(node->value);
            } else {
                stack.push(make_pair(node, true));
                if (node->right)
                    stack.push(make_pair(node->right, false));
                if (node->left)
                    stack.push(make_pair(node->left, false));
            }
        }
    }

    void LevelOrder(vector<Value> &vec) {
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            vec.push_back(node->value);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

    }


    Value *GetMin() {
        Node *node = root;
        if (node == nullptr)
            return nullptr;

        while (node->left)
            node = node->left;

        return &(node->value);

    }


    Value *GetMax() {
        Node *node = root;
        if (node == nullptr)
            return nullptr;

        while (node->right)
            node = node->right;

        return &(node->value);
    }

    void RemoveMin() {
        Node *node = root;
        Node *prevNode = nullptr;
        if (node == nullptr)
            return;

        while (node->left) {
            prevNode = node;
            node = node->left;
        }

        //node->left==nullptr
        if (prevNode == nullptr) { //node==root
            root = node->right;
        } else {
            prevNode->left = node->right;
        }
        delete node;
        count--;
    }

    void Remove(const Key &key) {
        Node *node = root;
        Node *prevNode = nullptr;

        if (root == nullptr)
            return;

        //---------find node-------
        while (node) {

            if (key == node->key) {
                break;
            } else if (key < node->key) {
                prevNode = node;
                node = node->left;
            } else {
                prevNode = node;
                node = node->right;
            }
        }

        if(node== nullptr)
            return;

        //-------delete----------
        //case 1
        if (node->left == nullptr) {

            InsertHelper(prevNode, node->right);
            delete node;
            return;
        }
        //case 2
        if (node->right == nullptr) {
            InsertHelper(prevNode, node->left);
            delete node;
            return;
        }

        //case 3
        //node->left != nullptr && node->right != nullptr
        //find right tree smallest node (leftmost)

        Node *nodeMin = node->right;
        Node *prevNodeMin=node;

        while (nodeMin->left){
            prevNodeMin=nodeMin;
            nodeMin = nodeMin->left;
        }

        //delete from original place
        prevNodeMin->left= nodeMin->right;

        //put into new place


        delete node;

    }

private:
    void InsertHelper(Node *parent, Node *node) {
        if (parent == nullptr || node == nullptr)
            return;



        if (node->key < parent->key)
            parent->left = node;
        else //key>parent->key
            parent->right = node;
    }


    Node *GetMin(Node *_root) {
        Node *node = _root;
        if (node == nullptr)
            return nullptr;

        while (node->left)
            node = node->left;

        return node;

    }
};


#endif //DATASTRUCTURE_BST_H
