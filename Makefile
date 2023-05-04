CXX = g++
CXXFLAGS = -std=c++11

audit: main.cpp course.cpp courseSet.cpp course.h courseSet.h
		$(CXX) $(CXXFLAGS) -o audit main.cpp course.cpp courseSet.cpp

test: audit
		./audit

clean: 
		rm -f ./audit
		