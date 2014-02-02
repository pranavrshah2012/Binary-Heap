
/*
 * pqueue.cpp
 *
 *  Created on: Nov 11, 2012
 *      Author: Pranav Shah
 */

#include "pqueue.h"
#include "binaheap.h"
#include "node.h"
#include "iostream"
using namespace std;
#include<conio.h>
#include<string.h>
using namespace std;
pqueue::pqueue() {
	// TODO Auto-generated constructor stub
	front = NULL;
	rear = NULL;
}

pqueue::~pqueue() {
	// TODO Auto-generated destructor stub
}

bool pqueue::isEmpty() {
	return front == NULL ? true : false;

}

node* pqueue::insert(node* n) {

	//n->setdata(no);
	if (isEmpty()) {
		front = rear = n;
		cout << "root is " << front->getdata()<<endl;

	} else {
		rear->setnext(n);
		rear = rear->next;
		cout << "last element inserted is" << rear->getdata()<<endl;
	}
	return n;
}

node* pqueue::remove()
{
	if(isEmpty())
	{
		cout<<"queue is empty";
		return 0;
	}
	else
	{
	node* n = front;
	front = front->next;
	cout << endl << "deleted is" << n->getdata()<<endl;
	return n;
	}
}

int main()

{
	char ch;
	int z;
	binaheap b;
	binaheap h;int x;int y;
	string str;char c;
int n=0;
	while(1)
{
	cout<<"\n\nenter your choice"<<endl;
	cout<<"Enter c to clear heap"<<endl;
	cout<<"enter o to copy heap"<<endl;
	cout<<"enter s to switch heap"<<endl;
	cout<<"enter d to display heap"<<endl;
	cout<<"enter a to add element"<<endl;
	cout<<"enter r to remove"<<endl;
	cout<<"enter u for union"<<endl;
	cout<<"enter i for intersection"<<endl;
	cout<<"enter q to exit"<<endl;
	cin>>ch;char e;
	cin.get(e);
	int hh;int gg;
	string str;
switch(ch)
{
	case 'c': cout<<"clearing"<<endl;
				b.clearheap();
				break;

	case 'o':   b.copyheap(&b,&h,x);
				cout<<endl;
				cout<<"\n copied heap is";
				h.displayheap(&h);
				break;

	case 's':cout<<"\nswitch operation";
					cout<<"\noriginal heap 1 is "<<endl;
					x=b.displayheap(&b);
					cout<<"\noriginal heap 2 is "<<endl;
					y=h.displayheap(&h);
					b.switchheap(&b,&h);
					cout<<"\nswapped heap 1 is"<<endl;
					b.displayheap(&b);
					cout<<"\nswapped heap 2 is"<<endl;
					h.displayheap(&h);
					break;

	case 'd':cout<<"\ndisplaying heaps";
				cout<<"\nheap 1 is"<<endl;
				b.displayheap(&b);
				cout<<"\n2nd heap is";
				h.displayheap(&h);
				break;

	case 'a':	cout<<"\nenter how many elements in first heap";
				cin>>gg;
				for(int i=0;i<gg;i++)
				{
					cout<<"\nenter";
					cin>>n;
				b.countheap(&b,n);
				}
				cout<<"\nenter how many elements in 2nd heap";
								cin>>hh;
								for(int i=0;i<hh;i++)
								{
									cout<<"\nenter";
									cin>>n;
								h.countheap(&h,n);
								}
								break;

	case 'r':  cout<<"enter element to be removed";
				int rem;
				cin>>rem;
				cout<<"\n before removal";
				 b.displayheap(&b);
				b.findandremove(&b,rem);
				cout<<"after removal\n";
				b.displayheap(&b);
				break;


	case 'u':
					cout<<"\noriginal heap 1 is ";
					x=b.displayheap(&b);
					cout<<"\noriginal heap 2 is ";
					y=h.displayheap(&h);
					z=x+y-1;
					b.unionheap(&b,&h,z);
					cout<<"\n after union";
					cout<<"\nheap 1\n";
					b.displayheap(&b);
					cout<<"\nheap 2\n";
					h.displayheap(&h);
					break;

	case 'i':
			cout<<"\noriginal heap 1 is "<<endl;
			 x=b.displayheap(&b);
			cout<<"\noriginal heap 2 is "<<endl;
			 y=h.displayheap(&h);
			z=x+y-1;
			b.intersectionheap(&b,&h,x,y);
			cout<<"\n after intersection\n";
			cout<<"\nheap 1";
			b.displayheap(&b);
			cout<<"\nheap 2";
			h.displayheap(&h);
			break;

	case 'q':exit(1);
			break;


}//switch



}  //while

return 0;
}





