# include "copy_construct.h"

int main(){

MyCopyConstruct  object1_(7);
MyCopyConstruct object2_(object1_);
object1_.PrintValue();
object2_.PrintValue();

}
     