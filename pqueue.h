/*
 * pqueue.h
 *
 *  Created on: Nov 11, 2012
 *      Author: Pranav Shah
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include "node.h"
#include <iostream>
#include "binaheap.h"

using namespace std;
#include<conio.h>

class pqueue {


public:
	node* front;
	node* rear;

	pqueue();
	virtual ~pqueue();
	bool isEmpty();
	node* insert(node* n);
	node* remove();
	void input(binaheap* h);
};

#endif /* PQUEUE_H_ */
