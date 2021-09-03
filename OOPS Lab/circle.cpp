#include<iostream>
#define pi 3.14
using namespace std;

class Area{
        static float SUMAREA;
        static int i;
        float radius;
        float area;

        void ar(){
            area = pi*radius*radius;
            display();
        }

        void display(){
            cout<<"Area of the circle with radius "<<radius<<": "<<area<<endl;
            SUMAREA = SUMAREA + area;
        }

    public:
        //DEFAULT CONSTRUCTOR
        Area(){
            cout<<"Enter radius for first circle: "<<endl;
            cin>>radius;
            ar();
        }
        Area(float r){
            radius = r;
            ar();
        }
        Area(Area & A){
            radius = A.radius;
            ar();
        }

        static void netarea(){
            cout<<"Sum area: "<<SUMAREA<<endl;
        }
        ~Area(){
        }
};

float Area :: SUMAREA;

int main(){
Area a1, a2(7), a3(a2);
Area :: netarea();
return 0;
}