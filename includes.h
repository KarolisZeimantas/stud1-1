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
#include <memory>
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
class Student{
    protected:
    float vidurkis;
    float mediana;
    float egzam;
    string vardas;
    string pavar;
    public:

    virtual float getVid() = 0;
    virtual float getEgz() = 0;
    virtual float getMat() = 0;
    virtual string getVar() = 0;
    virtual string getPav() = 0;

    void vid(float v){ vidurkis = v;}
    void med(float m){ mediana = m;}
    void egz(float e){ egzam = e;}
    void pav(string v){ vardas = v;}
    void var(string p){ pavar = p;}


};

class Stud  : public Student{
    public: 
    float getVid(){return vidurkis;}
    float getEgz(){return egzam;}
    float getMed(){return mediana;}
    string getNam(){return vardas;}  
    string getLas(){return pavar;}
}; 
void createFiles();
void createVector();
bool checkForDigit(std::string digit);
double round2(double vid);



#endif