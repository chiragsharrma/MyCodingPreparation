#include<iostream>
using namespace std;

class complex{
    int a ,b;
    public:
        void setNumber(int n1,int n2){
            a = n1;
            b = n2;
        }
        friend complex sumComplex(complex o1, complex o2);
        void printNumber(){
            cout<<"your number is: "<< a<<" + "<< b<<"i"<<"\n";
        }
       
};
      complex sumComplex(complex o1, complex o2){
                complex o3;
                o3.setNumber( (o1.a*o2.a) , (o1.b*o2.b) );
                return o3 ;
      }

int main(){
    complex c1 , c2, sum;
    c1.setNumber(1,4);
    c2.setNumber(5,8);
    c1.printNumber();
    c2.printNumber();
    sum = sumComplex(c1,c2);
    sum.printNumber();

    return 0;
}
//properties of friend function: - 
/*1) Not in the scope of class.
  2)can be invoked without the help of any objects
  3) since it is not a member of class so it can not be called from objects of that class so c1.sumComplex ==  invalid.
  4) usually contains the arguments as objects.
  5) can be declared inside public or private section of class.
  6) it can not access the name of the member directly ,it needs object to access them object.member.*/