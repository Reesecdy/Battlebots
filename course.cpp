//implementation of course class
#include "course.h"
#include <iostream>

    //constructor for course
    course::course(std::string name, int credit, double grade, bool Inp, bool Rc){
        this->name = name;
        this->credit = credit;
        this->grade = grade;
        this->inp = Inp;
        this->Rc = Rc;
        cs = false;
    }

    //used for debugging, but prints out entire class data
    void course::print(){
        std::cout << name << " grade:" << grade << " credits:" << credit << " in progress:" << inp << " recieving credit:" << Rc << "\n";
    }
    std::string course::getName(){
        return name;
    }
    double course::getGrade(){
        return grade;
    }
    int course::getCredit(){
        return credit;
    }
    void course::setInp(bool set){
        inp = set;
    }
    bool course::getInp(){
        return inp;
    }
    void course::setRc(bool set){
        Rc = set;
    }
    bool course::getRc(){
        return Rc;
    }
    void course::setCs(bool set){
        cs = set;
    }
    bool course::getCs(){
        return cs;
    }