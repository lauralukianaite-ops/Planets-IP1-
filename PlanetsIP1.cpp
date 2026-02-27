//Planet(name,gravity,moons)
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <cassert>

using namespace std;

//klases aprasymas
class Planet{

    private: //tiesiogiai pasiekti duomenis nera gerai, reikia naudoti private
        string name;
        double gravity;
        int moons;

        int id;
        static int lastId;
        static int count;

    public:
        Planet(string name){
            init(name,0.0,0);
        }
        Planet(string name, double gravity, int moons){
            init(name,gravity,moons);
        }
        //Destruktorius:
        ~Planet(){
            count--;
        }
    
    private:
        void init(string name, double gravity, int moons){
            count++;
            setName(name);
            id = lastId++;
            this->moons = 0;
            string errors = "";
            try{
                setGravity(gravity);
            }catch(exception &e){
                errors += string(e.what()) + "\n";
            }
            try{
                setMoons(moons);
            }catch(exception &e){
                errors += string(e.what()) + "\n";
            }
            if(!errors.empty()) 
                throw invalid_argument(errors);
        }

    public:
        void setName(string name){
            this->name = name;
        }
        void setGravity(double gravity){
            if(gravity > 0)
                this->gravity = gravity;
            else 
                throw invalid_argument("Exception in Planet: gravity must be positive!");
        }
        void setMoons(int moons){
            if((moons>=0) && (moons >= this-> moons))
                this->moons = moons;
            else
                throw invalid_argument("Exception in Planet: number of moons connot be negative and cannot decrease!");
        }
        
        int getId(){
            return id;
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
        static int getCount(){
            return count;
        }

        string toString(){
            stringstream ss;
            ss << getId() << " " << getName() << " " << getGravity() << " " << getMoons();
            return ss.str();
        }
};

int Planet::lastId = 0;
int Planet::count=0;

int main(){
    try{
        //test1: kurti objekta, getteriai grazina teisingas reiksmes, veikia toString
        cout << "Test1: ";
        {
            Planet p("Earth",9.81,1);
            assert(p.getName() == "Earth");
            assert(p.getGravity() == 9.81);
            assert(p.getMoons() == 1);
            assert(p.toString() == "0 Earth 9.81 1");
            cout << "PASS" << endl;
        }
        
        //test2: seteriai keicia reiksmes
        cout << "Test2: ";
        {
            Planet p("Mars",3.72,2);
            p.setName("Venus");
            assert(p.getName() == "Venus");
            p.setGravity(8.87);
            assert(p.getGravity() == 8.87);
            p.setMoons(3);
            assert(p.getMoons() == 3);
            cout << "PASS" <<endl;
        }
    }catch(...){
        cout << "Unexpected error occured!" << endl;
    }
    return 0;
}