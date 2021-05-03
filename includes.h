#ifndef GRANDPARENT_H6
#define GRANDPARENT_H6
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ratio>
#include <fstream>
#include <iomanip>
#include <string> 
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <chrono>
#include <list>
#include <deque>
#include <cmath>
#include <ctype.h>
#include <iterator>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <filesystem>
namespace fs = std::filesystem;
using std::chrono::steady_clock;
using std::remove_if;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::move;
using std::vector;
using std::fixed;
using std::chrono::duration;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::deque;
using std::string;
using std::list;

struct Students{
    std::string names;
    std::string lastNames;
    float vid;
    float med=0;
    float egzaminas;
    
    
    Students(string names, string lastNames,float vid, float med, float egzaminas): names(names), lastNames(lastNames),vid(vid),med(med),egzaminas(egzaminas){

    }
    Students(const Students& student): names(student.names), lastNames(student.lastNames), vid(student.vid), med(student.med), egzaminas(student.egzaminas){

    }
    bool operator()(Students const & a, Students const & b) const
        {
        return a.vid <b.vid;
        }
};
void createList();
void createDeque();
void createFiles();
void createVector();
bool checkForDigit(std::string digit);
bool sorter(Students const &lhs, Students const &rhs);
double round2(double vid);
bool sortList(Students const &a, Students const &b);



#endif