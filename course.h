//Declaration of course class
#ifndef COURSE_H
#define COURSE_H

#include <string>

class course{
    public:
    course(std::string name, int credit, double grade, bool Inp, bool Rc);
    std::string getName();
    double getGrade();
    int getCredit();
    void setInp(bool set);
    bool getInp();
    void setRc(bool set);
    bool getRc();
    void setCs(bool set);
    bool getCs();
    void print();

    private:
    std::string name; //class name
    int credit; //class credits
    bool inp; //in progress
    bool Rc; //receiving credit
    bool cs; //cs class
    double grade; //grade of class
};
#endif //COURSE_H