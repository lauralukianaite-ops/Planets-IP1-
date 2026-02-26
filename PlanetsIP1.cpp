//Planet(name,gravity,moons)
#include <iostream>
#include <string>

using namespace std;

//klases aprasymas
class Planet{
    public: //public reiskia kad duomenis galima bus pasiekti ir keisti veliau programoje
        string name;
        double gravity;
        int moons;
};

int main(){
    Planet p; //objekto instancija
    p.name = "Earth";
    p.gravity = 9.81;
    p.moons = 1;
    cout << "Success!" <<endl;
    return 0;
}