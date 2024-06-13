#include<iostream>
using namespace std;

class Counter{
    private:
        int cnt;
    public:
    Counter(): cnt(0){
    }
    Counter (int c): cnt(c){

    }
    int get_count(){
       return cnt;
    }
    Counter operator ++(){ //prefix
        return Counter(++cnt);
    }
        Counter operator ++(int){ //prefix
        return Counter(cnt++); //object initialized to this count, then increment count
    }
};


int main(){
    Counter c1,c2;
    cout<<"c1 val "<<c1.get_count()<<endl; //0

    cout<<"c2 val "<<c2.get_count()<<endl; //0

    ++c1; //1
    c2 = ++c1; //c2=2, c1=2
    cout<<"c1 val "<<c1.get_count()<<endl;//2

    cout<<"c2 val "<<c2.get_count()<<endl;//2
    Counter c3;
    c3=c1++; //c2=2, c1=3

        cout<<"c1 val "<<c1.get_count()<<endl;//3

    cout<<"c3 val "<<c3.get_count()<<endl;//2



}