#include<iostream>
using namespace std;
class diagonal
{
	private :
		int *A;
		int n;
	public :
		diagonal()//constructor To set the minimum size of the array, non parameterized constructor
		{
			n = 2;
			A = new int [2];
		}
		diagonal(int n) //parameterized constructor
		{ 
			this->n = n;
			A = new int [n];
		}

		~diagonal() // destructor
		{
			delete []A;
		}
		void set(int i, int j, int x);
		int get(int i, int j);
		void display();
};

class Lowertriangular 
{	
private:
	int *A;
	int n;
public :
	Lowertriangular ()
	{
		n = 2;
		A = new int [2];
	}
	Lowertriangular(int n)
	{
		this -> n = n;
		A = new int [n*(n+1)/2];
	}
	~Lowertriangular()
	{
		delete[]A ;
	}
	void sett(int i,int j, int x);
	int gett(int i, int j);
	void Display();
};

void diagonal:: set(int i,int j,int x)
{
	if(i == j)
	{
		A[i-1] = x;
	}
}
int diagonal:: get(int i, int j)
{
	if(i == j)
	{
		return A[i-1];
	}
	return 0;
}
void diagonal :: display()
{ 
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(i == j)
			{
				cout << A[i]<<" ";
			}
			else 
			{
				cout <<"0 ";
			}
		}
		cout<<endl;
	}

}
 void Lowertriangular :: sett(int i, int j, int x)
 {
 	if( i >= j)
 	{
 		A[i*(i-1)/2 + j-1] = x;
 	}
 }
 int Lowertriangular :: gett(int i , int j)
 {
 	if(i >= j)
 	{
 		cout<< A[i*(i-1) /2 + j-1];
 	}
 	return 0;
 }
 void Lowertriangular :: Display()
 {
 	for(int i = 1; i < n; i++)
 	{
 		for(int j = 1; j < n; j++)
 		{ 
 			if(i >= j)
 			{
 				cout<< A[i*(i-1)/2 + j-1] <<" ";
 			}
 			else 
 			{ 
 				cout<<"0" ;
 			}

 		}
 		cout << endl ;
 	}
 }
int main()
{
	Lowertriangular d(4);
	//d.sett(1,1,5);
	d.sett(3,2,6);
	d.gett(3,2);
	//d.sett(4,4,12);
	//d.Display();
	return 0;
}