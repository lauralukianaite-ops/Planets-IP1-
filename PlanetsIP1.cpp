//Planet(name,gravity,moons)
#include <iostream>
#include <string>

using namespace std;

//klases aprasymas
class Planet{
    private: //tiesiogiai pasiekti duomenis nera gerai, reikia naudoti private
        string name;
        double gravity;
        int moons;
    public:
        Planet(string name){
            setName(name);
            setGravity(0.0);
            setMoons(0);
        }
        Planet(string name, double gravity, int moons){
            setName(name);
            setGravity(gravity);
            setMoons(moons);
        }
        void setName(string name){
            this->name = name;
        }
        void setGravity(double gravity){
            this->gravity = gravity;
        }
        void setMoons(int moons){
            this->moons = moons;
        }

        string getName (){
            return name;
        }
        double getGravity(){
            return gravity;
        }
        int getMoons(){
            return moons;
        }
};

int main(){
    Planet p("Earth",9.81,1);
    cout << "Success!" <<endl;
    return 0;
}