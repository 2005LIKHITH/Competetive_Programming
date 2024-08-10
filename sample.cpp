
#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Book {
  public:
  string author;
  string title;
  int pages;
  int price;
  
  Book(string author, string title, int pages, int price) {
    this->author = author;
    this->title = title;
    this->pages = pages;
    this->price = price;
  }
};

int32_t main() {
  string author, title;
  int pages, price;
  cin >> author >> title >> pages >> price;
  Book B1(author, title, pages, price);
  cout << B1.author << '\n';
}


#include<bits/stdc++.h>
using namespace std;
#define int long long int

class Distance{
  public:
  double x1,y1,x2,y2;
  Distance(double x1,double y1,double x2,double y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
  }
  double calculate(){
    double temp1 = pow((x2-x1),2);
    double temp2 = pow((y2-y1),2);
    double ans = pow(temp1+temp2,0.5);
    return ans;
  }
  
};

int32_t main(){
  double x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  Distance D(x1,y1,x2,y2);
  cout<<setprecision(7)<<fixed<<D.calculate()<<'\n';
}

#include<bits/stdc++.h>
using namespace std;
#define int long long int

class ComplexNumber{
    public:
    float rP1;
    float iP1;
    float rP2;
    float iP2;
    ComplexNumber(float rP1,float iP1,float rP2,float iP2){
        this->rP1 = rP1;
        this->iP1 = iP1;
        this->rP2 = rP2;
        this->iP2 = rP2;
        cout<<rP1+rP2<<'\n';
    }
};
int32_t main(){
    float a,b,c,d;
    cin>>a>>b>>c>>d;
    ComplexNumber add(a,b,c,d);
}

// Design a structure book and read the book details and print it [author ,title ,pages, price]
//Desin a structure point (x,y) coordinates find the distance between two points
//Design a class complex number addn of two complex number