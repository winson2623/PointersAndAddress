#include<iostream>
using namespace std;

typedef int* IntPtr;

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
	cout << endl;

	//---------------------------------------------------------------------------------------------------------------------------
	//Chapter 9.2 Savitch Dynamic Pointers

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

	cout << endl;

	//---------------------------------------------------------------------------------------------------------------------------
	//Chapter 9.5 Savitch Arrays

	int* p;	
	int a[10];	//creates array a of 10 spaces
	int i;

	for (int i = 0; i < 10; i++) {
		a[i] = i;	//places int i in each index
		p = a;		//make pointer p point to first element of a
	}

	for (i = 0; i < 10; i++) {
		cout << p[i] << " ";	//0 1 2 3 4 5 6 7 8 9
	}
	cout << endl;

	for (i = 0; i < 10; i++) {
		p[i] = p[i] + 1;		//increments p pointer by 1 which also updates a
	}

	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";	//1 2 3 4 5 6 7 8 9 10
	}
	cout << endl;
	cout << endl;

	//---------------------------------------------------------------------------------------------------------------------------
	//Chapter 9.7 Savitch Two-Dimension Dynamic Arrays

	int d1, d2;
	cout << "Enter row and columns: \n";
	cin >> d1 >> d2;
								//												say d1 = 3 and d2 = 4
	int** m = new int*[d1];		//assign an array of d1 pointers to the row		m ->[?] [?] [?]
	int j, k;
	for (j = 0; j < d1; j++) {	
		m[j] = new int[d2];		//in each row, assign an array of d2 input			[ ? ? ? ? ]
								// m is now a d1 row by d2 column (2D array)		[ ? ? ? ? ]
	}							//													[ ? ? ? ? ]


	cout << "Enter " << d1 << " rows of " << d2 << endl; //input the numbers you want in row x column
	for (j = 0; j < d1; j++) {		//first outer array row
		for (k = 0; k < d2; k++) {	//second inner array column
			cin >> m[j][k];			//inputs the row first [j] then column [k]
		}
	}

	cout << "echo the 2D array: \n";

	for (j = 0; j < d1; j++) {
		for (k = 0; k < d2; k++) {
			cout << m[j][k] << " ";		//outputs the same order that was given in input
		}
		cout << endl;
	}

	for (j = 0; j < d1; j++) {
		delete[] m[j];					//deletes the row j
	}
	delete[] m;							//deletes array of row pointer

	return 0;
}