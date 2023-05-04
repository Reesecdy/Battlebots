#ifndef COURSESET_H
#define COURSESET_H
#include <string>
#include <vector>
#include "course.h"

class courseSet{

    public:
    courseSet();
    bool readDataFile(char *filename);
    void printDataSet();
    int inProgress();
    int noCredit();
    int totalHours();
    double GPA();
    double csGPA(); //cs gpa
    int Earned(); //credit hours earned
    int RCredit(); //recieving credit
    
    private:
    std::vector<course *> data; //variable array with each course in it
};

#endif // COURSET_H