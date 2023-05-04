#include <iostream>
#include <fstream>
#include <sstream>
#include "courseSet.h"

//constructor
courseSet::courseSet(){
//nothing to do
}

bool courseSet::readDataFile(char *filename){
   // Create an input stream object for the filename given as an argument;
   // this also opens the file for reading
   std::ifstream inFile(filename);
   if (!inFile)
   {
      std::cerr << "Error: file " << filename << " cannot be opened\n";
      return false;
   }
   // now we have an open file, so read it in and get our data
   //std::cout << "Reading the data file....";
   std::string line;
   int credit = 0;
   double grade = 0.0;
   int lines = 0;
   bool Inp = false; //in progress
   bool Rc = true; //recieving credit
   std::string name;
   // read first line of file (data column titles) and throw it away
   //std::getline(inFile, line);
   // read the rest of the file line by line; this is safer
   // than trying to parse the lines as you read the data in
   while (std::getline(inFile, line))
   {
      // uncomment the next line if you are debugging and need to
      // see what each line looks like
      // std::cout << "line is [" << line << "]\n";
      if (line.length() < 2)
         continue; // probably at end of file
      lines++;
      //std::cout << "line: " << lines << "\n";
      // now treat the line itself as an input stream (from a string!)
      std::istringstream lineStream(line);
      std::string piece;
      int column = 0;
      // loop below separates pieces of the line by spaces
    bool Inp = false;//resets this variable and next
    bool Rc = true;
      while (std::getline(lineStream, piece, ' '))
      {
         // remove quotation marks on data, if they exist
         if (piece.front() == '"' && piece.back() == '"')
            piece = piece.substr(1, piece.size() - 2);
         // uncomment the next line if you are debugging and need to
         // see what each piece looks like
          //std::cout << "  piece [" << piece << "]\n"; //debugger
         column++;
         if (column == 4)  // credit column
         {
            credit = std::stoi(piece);
         }
         if (column == 5)  // grade column by letter
         {
            if(piece == "A+"){
                grade = 4.0;
            }
            if(piece == "A"){
                grade = 4.0;
            }
            if(piece == "A-"){
                grade = 3.7;
            }
            if(piece == "B+"){
                grade = 3.3;
            }
            if(piece == "B"){
                grade = 3.0;
            }
            if(piece == "B-"){
                grade = 2.7;
            }
            if(piece == "C+"){
                grade = 2.3;
            }   
            if(piece == "C"){
                grade = 2.0;
            }
            if(piece == "C-"){
                grade = 2.0;            
                }
            if(piece == "D+"){
                grade = 1.0;
            }
            if(piece == "D"){
                grade = 1.0;
            }
            if(piece == "D-"){
                grade = 1.0;
            }
            if(piece == "F"){
                grade = 0;
                Rc = false;
            }
            if(piece == "IP"){
                grade = 0;
                Inp = true;
            }
            if(piece == "W"){
                grade = 0;
                Rc = false;
            }
            
         }
         if(column == 2){//class name column
            name = piece;
         }
         //if(column == 3){//other half of class name
         //   name += piece;
        // }
      }
      // make a new course object
      course *period = new course(name,credit,grade,Inp,Rc);
      // add this object to our collection
      //period->print();//debugger
      data.push_back(period);
   }
   inFile.close();
   //std::cout << "done.\n";
   return true;
}

//prints the size of the data, which should be total classes
void courseSet::printDataSet(){
    std::cout<<"Total number of courses: " << data.size() << "\n";
}

//if the class is recieving credit, then increment counter
//if the class is in progress, increment count
//subtract count from counter to get coourses recieving credit
int courseSet::RCredit(){
    int counter = 0;
    for(int i = 0; i < data.size(); ++i){
        if(data[i]->getRc() == true){
            counter = counter +1;
        }
    }
    int count = 0;
    for (int i = 0; i < data.size(); ++i){
        if (data[i]->getInp() == true){
            count += 1;
        }
    }
    return counter-count;
}

//if the class is in progress then increment counter and return counter at end
int courseSet::inProgress(){
    int counter = 0;
    for (int i = 0; i < data.size(); ++i){
        if (data[i]->getInp() == true){
            counter += 1;
        }
    }
    return counter;
}
 
 //if the class is not recieving credit, increment counter and return counter at end
int courseSet::noCredit(){
    int counter = 0;
    for(int i = 0; i < data.size(); ++i){
        if(data[i]->getRc() == false){
            counter += 1;
        }
    }
    return counter;
}

//if the class is recieving credit then add number of credits to sum and return sum
int courseSet::totalHours(){
    int sum = 0;
    for(int i = 0; i < data.size(); ++i){
        if(data[i]->getRc() == true){
        sum += data[i]->getCredit();
        }
    }
    return sum;
}

//if the class is recieving credit and not in progress, add the grade to GPA and increment counter
// divide GPA by counter and return 
double courseSet::GPA(){
    double GPA = 0;
    int counter = 0;
    for(int i = 0; i < data.size(); ++i){
        if(data[i]->getRc() == true && data[i]->getInp() != true){
            GPA += data[i]->getGrade();
            counter ++;
        }
    }
    GPA = GPA / counter;
    return GPA;
}

int courseSet::Earned(){ //return the total credit hours earned
    int counter = 0;
    for(int i = 0; i < data.size(); i++){
        if(data[i]->getGrade() > 0){//if the grade is above 0
            counter += data[i]->getCredit();//add amount of credits 
        }
    }
    return counter;
}
    
    //if the class is recieving credit, the name begins with C-S and is not in progress
    //add the class grade to the GPA, increment counter and then divide GPA by counter
double courseSet::csGPA(){//returns the CS GPA from given data
    double GPA = 0;
    int counter = 0;
    for(int i = 0; i < data.size(); ++i){
        if(data[i]->getRc() == true && data[i]->getName() == "C-S" && data[i]->getInp() != true){ 
            GPA += data[i]->getGrade();
            counter ++;
            //data[i]->print();//debugger
        }
    }
    GPA = GPA / counter;
    return GPA;
}
    