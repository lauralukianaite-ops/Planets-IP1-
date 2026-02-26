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
    Planet p; //objekto instancija
    p.setName("Earth");
    p.setGravity(9.81);
    p.setMoons(1);
    cout << "Success!" <<endl;
    return 0;
}