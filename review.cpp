#include<iostream>
using namespace std;

int main()
{
	int v1 = 0;	//v1 holds [0]														v1 [0]  0x7800
	int *p1 = &v1; //p1 gets the address of v1, like 00x7800						p1      0x7800
	*p1 = 77; //changes the value stored at address of v1 to hold [77]              v1 [77] 0x7800

	int *p2 = p1;	//copy the address of p1 to p2									p2		0x7800
	*p2 = 42;		//changes value stored of v1 to now hold [42]					v1 [42] 0x7800

	cout << v1 << endl;		//42
	cout << &v1 << endl;	//0x7800
	cout << *p1 << endl;	//42
	cout << p1 << endl;		//0x7800
	cout << p2 << endl;		//0x7800
	cout << *p2 << endl;	//42


	//---------------------------------------------------------------------------------------------------------------------------
	//Chapter 9.2 Savitch

	int* p3, * p4;	//creates p3		0x7801
					//creates p4		0x7802

	p3 = new int;	//		  p3   []	0x1000
	*p3 = 55;		//		  p3   [55] 0x1000
	p4 = p3;		//		  p4		0x1000


	cout << "*p3 == " << *p3 << endl; //55		0x1000
	cout << "*p4 == " << *p4 << endl; //55		0x1000

	*p3 = 77;						  //changes value to p3  [77] 0x1000
	cout << "*p3 == " << *p3 << endl; //77		0x1000
	cout << "*p4 == " << *p4 << endl; //77 because p4 address is also 0x1000

	p3 = new int;					  //		  p3   []   0x2000
	*p3 = 99;						  //		  p3   [99] 0x2000
	cout << "*p3 == " << *p3 << endl; //99		0x2000
	cout << "*p4 == " << *p4 << endl; //77 because p4 address is still 0x1000

	return 0;
}