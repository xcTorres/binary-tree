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
};

template <typename Key_T, typename Value_T, typename Compare_T = std::less<Key_T>>
class bst {
private:
	node<Key_T,Value_T>* _root;
public:
	void insert(Key_T key, Value_T value) {
		if (_root == nullptr) {
			_root = new node<Key_T, Value_T>(key,value);
		}
		else {
			insert(this->_root, key, value);
		}
	};
	void insert(node<Key_T, Value_T>* root, Key_T key, Value_T value) {
		if (root->_key > key) {
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