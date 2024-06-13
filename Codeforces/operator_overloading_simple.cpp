#include <iostream>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

class Distance{

    private:
        int feet;
        double inches;
    public:
        Distance() : feet(0),inches(0.0)
        {

        }
        Distance(int ft, double in): feet(ft), inches(in){

        }
        void getDist(){
            cout<<"Enter feet: "<<endl;
            cin>>feet;
            cout<<"Enter inches: "<<endl;
            cin>>inches;
        }
        void showDist() const {
            cout<<feet<<" - "<<inches<<endl;
        }

        Distance operator + (Distance) ; // add 2 distances;

        bool operator < (Distance); // comparing two dist;

        void operator += (Distance);

};

void Distance::operator+=(Distance d2){
    feet +=d2.feet;
    inches += d2.inches;
    if (inches>=12.0){
        inches-=12.0;
        feet+=1;
    }

}

Distance Distance::operator + (Distance d2){
    int f = feet + d2.feet;
    double i = inches + d2.inches;
    if (i>=12.0){
        i-=12.0;
        f++;
    }
    return Distance(f,i);

}

bool Distance::operator < (Distance d2){

    if (feet<d2.feet){
        return true;
    }
    if (inches<d2.inches){
        return true;
    }
    return false;

    // double bf1 = feet + inches/12;
    // double bf2 = d2.feet + d2.inches/12;
    // cout<<bf1<<" "<<bf2<<endl;

    // return (bf1<bf2)?true:false;
}

int main(){

    Distance d1,d3,d4;
    d1.getDist();

    Distance d2(11,2.4);

    d1+=d2;
    // d3 = d1+d2;
    // d4 = d1+d2+d3;

    cout<<"dist 1: ";d1.showDist();cout<<endl;
    cout<<"dist 2: ";d2.showDist();cout<<endl;
    // cout<<"dist 3: ";d3.showDist();cout<<endl;
    // cout<<"dist 4: ";d4.showDist();cout<<endl;

    // if (d1<d2)
    // {cout<<"d1 is shorter distance\n";}
    // else
    // {cout<<"d1 is the greater or equal to distance d2\n";}

    return 0;


}