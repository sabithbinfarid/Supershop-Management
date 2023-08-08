#include <iostream>
#include <string>
using namespace std;

int n;
class userlogin
{
public:
    string name;
    int password;
    userlogin() {}
    userlogin(string Name,int Password)
    {
        name=Name;
        password=Password;
        cout<<"your account create successfully"<<endl;
    }


};
//user login

class product
{

public:
    string product_name;
    int product_id;
    int product_price;
    friend int product_data(int id1,int n);
    friend class productdetails;


};
product customer[100];
//product array object


class productdetails:public product
{

public:
    productdetails() {}
    friend int product_data(int id1,int n);

    void getproductdata()
    {

        cout<<"enter product number"<<endl;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cout<<"enter product name "<<i<<":"<<endl;
            cin>>customer[i].product_name;
            cout<<"enter product id "<<i<<":"<<endl;
            cin>>customer[i].product_id;
            cout<<"enter product price"<<i<<":"<<endl;
            cin>>customer[i].product_price;

        }
    }

};
//product number,id and price


int product_data(int id1,int n)
{

    for(int i=1; i<=n; i++)
    {
        if(id1==customer[i].product_id)
        {
            cout<<"product name: "<<customer[i].product_name<<endl;
            cout<<"product id: "<<customer[i].product_id<<endl;
            cout<<"product price: "<<customer[i].product_price<<endl;
        }
    }

}
//friend function to find product id number


class calculation
{
public:
    calculation() {}
    void calculationprice(int id1,int n,int quantity)
    {

        for(int i=1; i<=n; i++)
        {
            if(id1==customer[i].product_id)
            {
                cout<<"your" <<customer[i].product_name<< "order is confirm and your grand totall is: ";

                cout<<customer[i].product_price*quantity<<endl;
            }
        }
    }


};
//order product price calculation

int main()
{
    cout<<"welcome to our shop center,please create your account to buy something"<<endl;
    string name1;
    int id2,fid,tn;
    cout<<"Enter your name"<<endl;
    cin>>name1;
    cout<<"Enter your id"<<endl;
    cin>>id2;
    userlogin ob1(name1,id2);

    productdetails ob2;
    ob2.getproductdata();
    cout<<"enter finding product id"<<endl;
    cin>>fid;
    product_data(fid,n);

    cout<<"Do you want to buy it"<<endl<<"press 1 otherwise enter 0"<<endl;
    int yes ;
    cin>>yes;
    if(yes)
    {
        int quantity;
        cout<<"enter quantity"<<endl;
        cin>> quantity;
        calculation ob;
        ob.calculationprice(fid,n,quantity);
    }

}
