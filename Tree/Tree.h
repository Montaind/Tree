#pragma once
#include <iostream>
template <typename T>
class Tree {
public:
	Tree() {
		
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