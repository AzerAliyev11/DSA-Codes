#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Human
{
private:
    int ID;
public:

    int age;
    string name;

    void SetID(int ID)
    {
        this->ID = ID;
    }

    int GetID()
    {
        return ID;
    }
};


bool comparator(int a, int b)
{
    return a > b ;
}

void print(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //int a;
    //cin>>a;
    //cout<<"Hello world"<<" today "<< a <<endl;

    //vector<dataType> vector_name(size, value)
    vector<int> myVector(5, 0);
    print(myVector);

    myVector.push_back(3);
    myVector.push_back(5);
    myVector.push_back(1);
    myVector.pop_back();

    print(myVector);

    sort(myVector.begin(), myVector.end(), comparator);
    print(myVector);

    vector< vector<int> > vector2D(5, vector<int>(5, 0));
    Human h1;
    h1.age = 3;
    h1.SetID(3);
    int id = h1.GetID();

    string a = "Hello";
    string b = "world";
    cout<<a+b<<endl;
}