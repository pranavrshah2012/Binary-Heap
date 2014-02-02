/*
 * node.h
 *
 *  Created on: Nov 9, 2012
 *      Author: Pranav Shah
 */

#ifndef NODE_H_
#define NODE_H_

class node {

public:
	int data;
	node * left;
	node * right;
	node * parent;
	node *next;

	node();
	virtual ~node();
	int getdata();
	void setdata(int n);
	void setnext(node *e) {
		next = e;
	}

	node* getnext() {
		return next;
	}
	node* getleft() {
		return left;
	}
	node* getright() {
		return right;
	}
	node* getparent() {
		return parent;
	}
	void setleft(node *e) {
		this->left = e;
	}
	void setright(node *f) {
		this->right = f;
	}
	void setparent(node *g) {
		this->parent = g;
	}

};

#endif /* NODE_H_ */
