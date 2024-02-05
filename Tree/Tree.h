#pragma once
#include <iostream>
template <typename T>
class Tree {
public:
	Tree() {
		root = nullptr;
	}
	void add(T data) {
		if (!root) root = new Node(data);
		else add(root, data);
	}
private:
	void add(Node* current, T data)
	{
		if (data == current->data) return;
		
		if (data < current->data) {
			if (current->left) add(current->left, data);
			else
			{
				current->left = new Node(data);
				current->left->parent = current;
			}
		}
		else
		if (data > current->data) {
			if (current->right) add(current->right, data);
			else {
				current->right = new Node(data);
				current->right->data = current;
			}
		}
	}

	void del(Node* current, T data) {
		if (current->data == data) {
			if (current->left == nullptr && current->right == nullptr) {
				current->parent = nullptr;
				delete current;
			}
			if (current->left == nullptr && current->right != nullptr) {
				current->parent = nullptr;
				current->right = nullptr;
				delete current;
			}
			if (current->left != nullptr && current->right == nullptr) {
				current->parent = nullptr;
				current->left = nullptr;
				delete current;
			}
			
			if (current->left != nullptr && current->left != nullptr) {
				current->parent = nullptr;
				current->left = nullptr;
			}
		}
		if (current->data < data) {
			del(current->right, data);
		}
		if (current->data > data) {
			del(current - left, data);
		}
	}
private:
	class Node {
	public:
		Node()
		{
			data = "Null";
			parent = nullptr;
			right = nullptr;
			left = nullptr;
		}
		Node(T data) {
			parent = nullptr;
			right = nullptr;
			left = nullptr;
			this->data = data;
		}
		~Node() {

		}
		Node* parent;
		Node* right;
		Node* left;
		T data;
	};
	Node* root;
	
};