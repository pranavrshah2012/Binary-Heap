/*
 * binaheap.h
 *
 *  Created on: Nov 11, 2012
 *      Author: Pranav Shah
 */

#ifndef BINAHEAP_H_
#define BINAHEAP_H_



#include "node.h"
#include <iostream.h>
#include<conio.h>
using namespace std;

class binaheap {


public:
	node* root;

	void input(binaheap *h);
	int count;
	binaheap();
	virtual ~binaheap();
	node* insert1(node* temp,int n);
	void insertinqueue(int n);
	void heapify(node* temp1);
	node* clearheap();
	void switchheap(binaheap *h1, binaheap *h2);
	int displayheap(binaheap *g);
	void countheap(binaheap *g,int n);
	binaheap* copyheap(binaheap* h,binaheap* g,int n);
	binaheap* unionheap(binaheap* h,binaheap*g,int n);
	binaheap* intersectionheap(binaheap*h,binaheap* g,int x,int y);
	void findandremove(binaheap* h,int n);
	int countagain(binaheap* g) ;

};
#endif /* BINAHEAP_H_ */
