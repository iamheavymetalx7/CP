#include <bits/stdc++.h>
    using namespace std;


    template <class T>
    class animal{

        public:
            T name;
            void show(){
                cout<<"the animal is: "<<name<<endl;
            }
    };




    
    int main()
    {
        animal<string> an;
        an.name = "lion";
        an.show();
        return 0;
       
    }