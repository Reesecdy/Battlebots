#include <iostream>
#include "courseSet.h"
#include <iomanip>

/**
* Program start
**/
int main(int argc, char *argv[])
{
    // Total number of courses: 47
    // Courses receiving credit: 39
    // Courses in progress: 4
    // Courses not receiving credit: 4
    // Total GPA credit hours earned: 130
    // Overall GPA: 3.18
    // CS GPA: 2.73
    courseSet* sample = new courseSet(); // create new dataset
    sample->readDataFile(argv[1]);//sample.txt
    sample->printDataSet();//print total courses
    std::cout<<"Courses receiving credit: " << sample->RCredit() << "\n";
    std::cout<<"Courses in progress: " << sample->inProgress() << "\n";
    std::cout<<"Courses not receiving credit: " << sample->noCredit() << "\n";
    std::cout<<"Total GPA credit hours earned: " << sample->Earned() << "\n";
    std::cout<<std::fixed<<std::setprecision(2)<<"Overall GPA: " << sample->GPA() << "\n";
    std::cout<<"CS GPA: " << sample->csGPA() << "\n";
    //9 lines of code in main <10
}