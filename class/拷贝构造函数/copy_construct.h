#include <iostream>

using namespace std;

class MyCopyConstruct{
private:
    int value;
public:
    MyCopyConstruct(int   initialization_value  ){
        value=initialization_value;
    }
    //error: invalid constructor; you probably meant ‘MyCopyConstruct (const MyCopyConstruct&)
    // MyCopyConstruct(MyCopyConstruct initialization_object){ 
    //     value=initialization_object.value;
    // }
    MyCopyConstruct(const MyCopyConstruct & initialization_object){
        value=initialization_object.value;
    }
    void PrintValue(){
        cout<<"value \n"<<value<<endl;
    }

};