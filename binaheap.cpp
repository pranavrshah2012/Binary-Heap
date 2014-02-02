/*
 * binaheap.cpp

 *
 *  Created on: Nov 7, 2013
 *      Author: Pranav Shah
 */

/*
 * binaheap.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: Pranav Shah
 */
#include "pqueue.h"
#include "binaheap.h"
#include "node.h"
#include <iostream>
#include<conio.h>
#include<queue.h>
using namespace std;

binaheap::binaheap() {
	// TODO Auto-generated constructor stub
	root = NULL;
	count = 0;
}

binaheap::~binaheap() {
	// TODO Auto-generated destructor stub
}

void binaheap::input(binaheap *h) {
	int n;
	cout << "how many elements you want?";
	cin >> n;
	cout << " n is" << n;
	for (int i = 0; i < n; i++) {
		cout << endl << "enter element";
		cin >> n;
		h->countheap(h, n);
	}

}

node* binaheap::insert1(node* temp, int num) {
	node* n = new node();
	n->setdata(num);
	if (temp->getleft() == NULL) {

		temp->setleft(n);
		count++;
		//cout<<"after set left"<<endl;
		//cout << endl << "left is " << n->getdata();
		//cout<<"parent set before"<<endl;
		n->setparent(temp);
		//cout<<"parent set after"<<endl;

		temp = temp->getleft();
		//cout<<"after getleft "<<endl;
	} else if (temp->getright() == NULL) {
		temp->setright(n);
		//cout << endl << "right is " << n->getdata();
		n->setparent(temp);
		count++;
		temp = temp->getright();
	}
	return temp;

}

void binaheap::insertinqueue(int n) {

	if (root == NULL) {
		node* myNode = new node();
		myNode->setdata(n);
		root = myNode;
		count++;
		return;
	}

	queue<node*> q;

	q.push(root);

	while (!q.empty()) {
		node *temp = (q.front());
		//cout<<"temmp="<<temp->data<<endl;
		if (n == (temp->data)) {
			return;
		}

		if (temp->getleft() != NULL && temp->getright() != NULL) {
			q.push(temp->getleft());
			q.push(temp->getright());
			q.pop();
		} else			// if (temp->getleft() == NULL)
		{
			node* ret = insert1(temp, n);

			heapify(ret);

			return;
		}
//				else if (temp->getright() == NULL)
//						{
//						node* ret=	insert1(temp, n);
//						heapify(ret);
//						return;
//						}

	}			//while

	return;
}

void binaheap::heapify(node* temp) {
	node* gp;
	int var;
	//cout<<"in heapify "<<endl;

	//cout<<"getting gp "<<endl;
	while (temp != this->root) {
		gp = temp->getparent();
		if (temp->getdata() > gp->getdata()) {
			//	cout<<"in if condition in while loop"<<endl;
			var = gp->getdata();
			//	cout<<"hi"<<endl;
			gp->setdata(temp->getdata());
			//	cout<<"yo"<<endl;
			temp->setdata(var);
			//cout<<" after set data"<<endl;
			//cout<<"before temp"<<endl;
			temp = temp->getparent();

		} else {
			return;
		}

	}
//	cout<<" before root "<<endl;
//	return root;
}

node* binaheap::clearheap() {
	root = NULL;
//cout<<endl<<"cleared heap is "<<root;
//	root->left=NULL;
//	root->data=NULL;
//	root->right=NULL;
	return root;
}

void binaheap::switchheap(binaheap *h, binaheap *k) {
	node *temp = h->root;	//if parameter is *h,*k then error..y?
	h->root = k->root;
	k->root = temp;

}

int binaheap::displayheap(binaheap* g) {

	cout << endl;

	int count = 0;
	queue<node*> q;
	q.push(g->root);
	++count;
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			cout << " " << temp->getdata();
			++count;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			cout << " " << temp->getdata();
			++count;
		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			cout << " " << temp->getdata();
			++count;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			cout << " " << temp->getdata();
			++count;
		}
	}	//end while

	return count;
}

binaheap* binaheap::copyheap(binaheap*h, binaheap* g, int n) {
	int i;
	node* x = g->clearheap();
	queue<node*> q;
	//int tempcount=h->countagain(h);
	int a[h->count];
	//int a[h->count];
	i = 0;
	q.push(h->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		//sm error if put  * full func error to put ->
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			a[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			a[i] = temp->getdata();
			i++;
		}
	}	//end while
	for (i = 0; i < h->count; i++) {
		g->countheap(g, a[i]);

	}
	return g;
}

binaheap* binaheap::unionheap(binaheap*h, binaheap* g, int n) {
	int i;
	int x = h->count;
	queue<node*> q;
	int y = g->count;
	n = x + y;
	int a[n];
	i = 0;
	q.push(h->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		//sm error if put  * full func error to put ->
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			a[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			a[i] = temp->getdata();
			i++;
		}
	}	//end while
	//2nd while

	q.push(g->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		//sm error if put  * full func error to put ->
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			a[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			a[i] = temp->getdata();
			i++;
		}
	}	//end while
	node* xxx = h->clearheap();
	cout << "";
	for (i = 0; i < n; i++) {
		h->countheap(h, a[i]);
	}
	return h;
}

binaheap* binaheap::intersectionheap(binaheap*h, binaheap* g, int x, int y) {
	int i;
	queue<node*> q;
	int xx = h->count;
	int yy = g->count;
//	int n=xx+yy;
	int a[xx];

	i = 0;
	q.push(h->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		//sm error if put  * full func error to put ->
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			a[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			a[i] = temp->getdata();
			i++;
		}
	}	//end while
	//2nd while

	int b[yy];
	i = 0;
	q.push(g->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		//sm error if put  * full func error to put ->
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			b[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			b[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			b[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			b[i] = temp->getdata();
			i++;
		}
	}	//end while
	node* xxx = h->clearheap();
	int j = 0;
	int k = 0;
	for (i = 0; i < xx; i++) {
		for (j = 0; j < yy; j++) {
			if (a[i] == b[j]) {
				k++;
			}
		}
	}

	int c[k];

	for (i = 0; i < xx; i++) {
		for (j = 0; j < yy; j++) {
			if (a[i] == b[j]) {
				c[k] = a[i];
				h->countheap(h, c[k]);
				k++;
			}
		}
	}
	return h;
}

void binaheap::countheap(binaheap*h, int n) {
	int i;

	if (h->root == NULL) {
		node* myNode = new node();
		myNode->setdata(n);
		h->root = myNode;
		count++;
		return;
	}
	queue<node*> q;
	int a[h->count];
	i = 0;
	q.push(h->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			a[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			a[i] = temp->getdata();
			i++;
		}
	}	//end while
	bool flag = false;
	for (i = 0; i < (h->count); i++) {
		// cout<<" - "<<a[i];
		if (n == a[i]) {
			flag = true;
			break;
		}

	}
	if (flag == 0)
		h->insertinqueue(n);

	//return g;
}

void binaheap::findandremove(binaheap*h, int n) {
	int i;
	queue<node*> q;
	int a[h->count];
	i = 0;
	q.push(h->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		//if(n==(temp->data)){cout<<endl<<"ele found"; break;}
		if (temp->getleft() != NULL && temp->getright() != NULL) {
			q.push(temp->getleft());
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			a[i] = temp->getdata();
			i++;

		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			a[i] = temp->getdata();
			i++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			a[i] = temp->getdata();
			i++;
		}
	}	//end while
	bool flag = false;
	int opt;
	for (i = 0; i < (h->count); i++) {
		// cout<<" - "<<a[i];
		if (n == a[i]) {
			a[i] = -777;
			opt = 2;
		}

	}
	cout << endl;
	if (opt == 2) {
		int oldcount = h->count;
		h->clearheap();
		for (i = 0; i < oldcount; i++) {
			if (a[i] != -777)
				h->countheap(h, a[i]);
		}
	} else
		cout << "element not found\n";
	//return g;
}

int binaheap::countagain(binaheap* g) {
	int countone = 1;
	queue<node*> q;
	q.push(g->root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		if (temp->getleft() != NULL && temp->getright() != NULL)

		{
			q.push(temp->getleft());
			q.push(temp->getright());
			count++;
		} else if (temp->getleft() != NULL && temp->getright() == NULL) {
			q.push(temp->getleft());
			count++;
		}
		//no need fr this below block mostly
		else if (temp->getright() != NULL && temp->getleft() == NULL)

		{
			q.push(temp->getright());
			count++;
		} else if (temp->getleft() == NULL && temp->getright() == NULL) {
			count++;
			;
		}
	}	//end while

	return count;
}






