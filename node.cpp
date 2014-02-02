/*
/*
 * node.cpp
 *
 *  Created on: Nov 9, 2012
 *      Author: Pranav Shah
 */
#include "node.h"
#include "iostream"
using namespace std;
#include<conio.h>

node::node() {
	// TODO Auto-generated constructor stub
data=NULL;
left=NULL;
right=NULL;
next=NULL;
parent=NULL;
}

node::~node() {
	// TODO Auto-generated destructor stub
}


void node:: setdata(int num)
{
	this->data=num;
}

int node:: getdata()
{
	return data;
}

/*
int main()
{
	node n;
	node o;
	node p;
	n.setdata(10);
	o.setdata(20);
	p.setdata(30);
	n.setleft(&o);
	o.setparent(&n);
	n.setright(&p);
	p.setparent(&n);
	cout<<""<<n.getdata()<<" "<<n.getleft()->getdata()<<endl;
    cout<<""<<n.getdata()<<" "<<n.getright()->getdata()<<endl;
    cout<<"abc";

    if(o.getleft()==NULL)
    {
    node r;
    r.setdata(40);
    o.setleft(&r);
    cout<<"o left"<<r.getdata();

    }



return 0;

}

*/





