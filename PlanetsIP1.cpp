//Planet(name,gravity,moons)
#include <iostream>
#include <string>
#include <sstream>

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
    
    private:
        void setName(string name){
            this->name = name;
        }
    
    public:
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

        string toString(){
            stringstream ss;
            ss << getName() << " " << getGravity() << " " << getMoons() << endl;
            return ss.str();
        }
};

int main(){
    Planet p("Earth",9.81,1);
    cout << p.toString() << endl;
    p.setGravity(9.8);
    cout << p.toString() <<endl;
    return 0;
}