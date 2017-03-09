// bst.cpp : 定义控制台应用程序的入口点。
//
#include<iostream>
#include"bst.h"
using namespace std;
int main() {
	bst<const char*, const char*>* tree = new bst<const char*, const char*>();
	tree->insert("a", "2.0");
	tree->insert("b", "1.0");
	tree->insert("c", "2.0");
	tree->insert("d", "2.0");
	tree->insert("e", "10.0");
	tree->insert("f", "10.0");
	tree->insert("g", "10.0");

	//preorder
	cout << "preOrder:" << endl;
	tree->print(PRE_ORDER);
	cout << "-------------------------" << endl;

	cout << "midOrder:" << endl;
	tree->print(MID_ORDER);
	cout << "-------------------------" << endl;

	cout << "postOrder:" << endl;
	tree->print(POST_ORDER);
	cout << "-------------------------" << endl;
	return 0;
}
