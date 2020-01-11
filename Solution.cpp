#include <iostream>
using namespace std;

//function for addition
void addHugeINTs(int *N1, int *N2,int size1,int size2,int *Sum)
{
	int carry = 0,k = 0;
	int i = size1 - 1;
	int j = size2 - 1;
	for (; i >= 0 && j >= 0; i--, j--, k++)
	{
		Sum[k] = (N1[i] + N2[j] + carry) % 10;
		carry = (N1[i] + N2[j] + carry) / 10;
	}
	//if num1 is greater than num2
	if (size1 > size2) 
	{
		while (i >= 0)
		{
			Sum[k++] = (N1[i] + carry) % 10;
			carry = (N1[i--] + carry) / 10;
		}
	}
	//if num2 is greater than num1
	else if (size1 < size2) 
	{
		while (j >= 0)
		{
			Sum[k++] = (N2[j] + carry) % 10;
			carry = (N2[j--] + carry) / 10;
		}
	} 
	else
	{
		if (carry > 0)
			Sum[k++] = carry;
	}
	cout<<"The SUM result of Number1 and Number2 comes out to be as: ";
	//printing on console
	for (k--; k >= 0; k--)
		cout<<Sum[k];
	cout<<endl;
}

//function for multiplication
void mulHugeINTs(int *N1, int *N2,int size1,int size2,int *Multi)
{
	int add = 0,m = 0;
	int i = size1 - 1;
	int j = size2 - 1;
	for (; i >= 0 && j >= 0; i--, j--, m++)
	{
		Multi[m] = (N1[i] * N2[j] + add) % 10;
		add = (N1[i] * N2[j] + add) / 10;
	}
	//if num1 is greater than num2
	if (size1 > size2) 
	{
		while (i >= 0)
		{
			Multi[m++] = (N1[i] * add) % 10;
			add = (N1[i--] * add) / 10;
		}
	} 
	//if num2 is greater than num1
	else if (size1 < size2) 
	{
		while (j >= 0)
		{
			Multi[m++] = (N2[j] * add) % 10;
			add = (N2[j--] * add) / 10;
		}
	} 
	else
	{
		if (add > 0)
			Multi[m++] = add;
	}
	cout<<"The MULTIPLICATION result of Number1 and Number2 comes as: ";
	//output for console
	for (m--; m >= 0; m--)
		cout<<Multi[m];
	cout<<endl;
}


int main()
{
	//allocation of dynamic arrays
	int *N1=new int [100000];
	int *N2=new int [100000];
	int *Sum=new int[100000];
	int *Multi=new int[100000];
	char *a1=new char[100000]; 
	char *a2=new char[100000];
	int size1, size2;

	//taking input from user
	cout<<"Enter Number1: ";
	cin>>a1;
	cout<<"Enter Number2: ";
	cin>>a2;

	/* convert character to integer*/
	for (size1 = 0; a1[size1] != '\0'; size1++)
		N1[size1] = a1[size1] - '0';
	for (size2 = 0; a2[size2] != '\0'; size2++)
		N2[size2] = a2[size2] - '0';

	//function call for adding huge INTs
	addHugeINTs(N1,N2,size1,size2,Sum);

	//function call for multiplying huge INTs
	mulHugeINTs(N1,N2,size1,size2,Multi);

	//deallocation of dynamic arrays
	delete []N1;
	delete []N2;
	delete []Sum;
	delete []Multi;
	delete []a1;
	delete []a2;

	//program successfully terminated
	system("pause");
	return 0;
	
}