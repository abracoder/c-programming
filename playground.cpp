#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> v(5);
    int n;
    cout << "enter vector elements"<< endl;
    cout << v.size();
    for(int i=0;i!=v.size();i++){
        cin >> n;
        // v.push_back(n);
        v[i]=n;
        if(i==5){
            break;
        }
    }
    cout<<"contents of vector /n";
    vector < int > :: iterator it=v.begin();
    cout << "iterator"<<*it<<endl;
    for(auto i:v){
        cout<<i<<endl;
    }
    cout << "hello world"<< endl;
    cout << "getting started with DSA";

    return 0;
}