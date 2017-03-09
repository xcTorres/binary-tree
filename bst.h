#pragma once
#ifndef BST_H
#define BST_H
#include <algorithm>
#include <iostream>
using namespace std;
#define PRE_ORDER 0
#define MID_ORDER 1
#define POST_ORDER 2

template <typename Key_T, typename Value_T>
struct node {
	Key_T _key;
	Value_T _value;
	node<Key_T, Value_T>* _left;
	node<Key_T, Value_T>* _right;

	node(Key_T key, Value_T value) {
		this->_key = key;
		this->_value = value;
		this->_left = nullptr;
		this->_right = nullptr;
	}
	~node()
	{
		if (_left != nullptr)
			delete _left;
		if (_right != nullptr)
			delete _right;
	}
	void operator=(node<Key_T, Value_T> &n) {
		this->_key = n._key;
		this->_value = n._value;
		this->_left = n._left;
		this->_right = n._right;
	}
};

template <typename Key_T, typename Value_T, typename Compare_T = std::less<Key_T>>
class bst {
private:
	node<Key_T,Value_T>* _root;
	Compare_T cmp;
public:
	bst() {
		_root = nullptr;
		cmp = Compare_T();
	};
	bool compare(Key_T key1, Key_T key2) {
		return cmp(key1, key2);
	};
	void insert(Key_T key, Value_T value) {
		if (_root == nullptr) {
			_root = new node<Key_T, Value_T>(key,value);
		}
		else {
			insert(this->_root, key, value);
		}
	};
	void insert(node<Key_T, Value_T>* root, Key_T key, Value_T value) {
		if (compare(key,root->_key)) {
			if (root->_left == nullptr) {
				root->_left = new node<Key_T, Value_T>(key, value);
			}
			else {
				insert(root->_left, key, value);
			}
		}
		else {
			if (root->_right == nullptr) {
				root->_right = new node<Key_T, Value_T>(key, value);
			}
			else {
				insert(root->_right, key, value);
			}
		}
	};

	node<Key_T, Value_T>** search(node<Key_T, Value_T>** root,Key_T key) {
		if ( (*root) == nullptr || (*root)->_key == key)
			return root;

		if (compare(key, _root->_key))
			return search( &((*root)->_left), key);

		return search(&((*root))->_right, key);
	};


	/* Given a non-empty binary search tree, return the node with minimum
	key value found in that tree. Note that the entire tree does not
	need to be searched. */
	node<Key_T, Value_T>* minValueNode( node<Key_T, Value_T>* root)
	{
		node<Key_T, Value_T>* current = root;

		/* loop down to find the leftmost leaf */
		while (current->_left != NULL)
			current = current->_left;
		return current;
	}


	void remove(Key_T key) {
		if (_root == nullptr) {
			cout << "the tree is empty" << endl;
			return;
		}
		remove(&_root, key);
	};

	void remove(node<Key_T, Value_T>** root, Key_T key) {
		node<Key_T, Value_T>** result = (search(root, key));
		//cout << &(*(search(root, key))) << "       " << &result << endl;
		if ((*result) == nullptr){
			cout << "the binary tree doesn't have the key:" << key << endl;
		}
		
		/* case
		   1: node is the leaf 
		   2: node only have the right child
		   3: node only have the left child
		   4: node both have two children
		*/  
		int _case;
		if ((*result)->_left == nullptr && (*result)->_right == nullptr)
			_case = 1;
		else if ((*result)->_left == nullptr && (*result)->_right != nullptr)
			_case = 2;
		else if ((*result)->_left != nullptr && (*result)->_right == nullptr)
			_case = 3;
		else
			_case = 4;

		node<Key_T, Value_T>* temp;
		switch (_case){
		case 1:
			delete *result;
			*result = nullptr;
			break;
		case 2:
			temp = (*result);
			*result = (*result)->_right;
			//delete temp;
			break;
		case 3:
			temp = (*result);
			*result = (*result)->_left;
			//delete temp;
			break;
		case 4:
			temp = minValueNode((*result)->_right);
			(*result)->_key = temp->_key;
			(*result)->_value = temp->_value;
			//delete temp;
			//temp = nullptr;
			break;
		default:
			break;
		}	
	}

	void print(int mode = 0) {
		print(this->_root, mode);
	}
	void print(node<Key_T, Value_T>* root, int mode = 0) {
		if (root == nullptr) {
			return;
		}
		else {
			switch (mode)
			{
			case 0:
				cout << "key:" << root->_key << "   value:" << root->_value << endl;
				print(root->_left, mode);
				print(root->_right, mode);
				break;
			case 1:
				print(root->_left, mode);
				cout << "key:" << root->_key << "   value:" << root->_value << endl;
				print(root->_right, mode);
				break;
			case 2:
				print(root->_left, mode);
				print(root->_right, mode);
				cout << "key:" << root->_key << "   value:" << root->_value << endl;
				break;
			default:
				break;
			}
		}
	};
};
#endif