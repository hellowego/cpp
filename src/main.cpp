#include<iostream>
#include"../include/add.h"
#include"../include/sub.h"

int main(){
    std::cout<<"5-2 = "<< sub(5, 2) <<std::endl;
    std::cout<<"2+3 = "<<add(2, 3)<<std::endl;
    return 0;
}