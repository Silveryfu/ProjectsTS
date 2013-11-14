#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

class Proc{
public:

    Proc(int p, int id){
        priority=p;
        procID=id;
        blockState=0;
        procType=1;    //normal as default
        /*generate the simulation of a process and IOs*/
        initialize_loc();
    };

    Proc(int p, int id, int pt){
        priority=p;
        procID=id;
        blockState=0;
        procType=pt;
        /*generate the simulation of a process and IOs*/
        initialize_loc();
    };

    ~Proc(){};

    int isBlocked(){
        return blockState;
    }

    int getID(){
        return procID;
    }

    int getPriority(){
        return priority;
    }

    void proc_execute(){
        cout<<"This is process "<<procID<<" running."<<endl;
        for(list<int>::const_iterator ci=loc.begin();ci!=loc.end();++ci){
            cout<<*ci<<endl;
        };
        cout<<"Proc finishes."<<endl;
    }

protected:
    Proc(){};

private:
    int priority;
    int procID;
    int procType; //cpu-bounded as 2, normal as 1, io-bounded as 0
    int blockState;
    list<int> loc;   //"lines of codes"

    void initialize_loc(){
        srand(time(NULL));
        int num_of_lines=10+rand()%100;   //a process will have 10 to 110 lines of code
        int io_odd;  //probablity of a io occurence
        for(int i=0;i<num_of_lines;i++){
            io_odd=rand()%(procType*30+5);   //averagely, an io-bounded proc io occurs 1 out of 5, normal: 1/35, cpu-bounded: 1/65;
            if(io_odd!=0) loc.push_front(1);
            else loc.push_front(0);
        }
    }
};

int main()  //for unit test
{
    //Proc* p=new Proc(7, 3, 2);
    //Proc* p=new Proc(7, 3, 0);
    Proc* p=new Proc(7, 3);
    cout << p->getPriority() << endl;
    p->proc_execute();
    return 0;
}