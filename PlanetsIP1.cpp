//Planet(name,gravity,moons)
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

//klases aprasymas
class Planet{

    private: //tiesiogiai pasiekti duomenis nera gerai, reikia naudoti private
        string name;
        double gravity;
        int moons;
        
    public:
        Planet(string name){
            init(name,0.0,0);
        }
        Planet(string name, double gravity, int moons){
            init(name,gravity,moons);
        }
    
    private:
        void init(string name, double gravity, int moons){
            setName(name);
            setGravity(gravity);
            setMoons(moons);
        }
        void setName(string name){
            this->name = name;
        }
    
    public:
        void setGravity(double gravity){
            if(gravity > 0)
                this->gravity = gravity;
            else 
                throw invalid_argument("Exception in Planet: gravity must be positive!");
        }
        void setMoons(int moons){
            if(moons>=0)
                this->moons = moons;
            else
                throw invalid_argument("exception in Planet: number of moons connot be negative!");
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
    try{
        Planet p("Earth",-9.81,-1);
        cout << p.toString() << endl;
        p.setGravity(-9.8);
        cout << p.toString() <<endl;
    }catch(...){
        cout << "Unexpected error occured!" <<endl;
    }
    return 0;
}