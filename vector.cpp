#include "includes.h"
bool sorter(Students const &lhs, Students const &rhs)
{
    if (lhs.vid < rhs.vid)
    {
        return true;
    }
    return false;
}
void splitVector(int x, vector<Students> studVec, vector<Students> vargVed,vector<Students> studKiet){
    std::sort(studVec.begin(),studVec.end(),sorter);

    auto start = steady_clock::now();
    for (int p = 0; p < x; p++)
        {
            if (studVec[p].vid >= 5){
                studKiet.push_back(Students(studVec[p].names,studVec[p].lastNames,studVec[p].vid,studVec[p].med,studVec[p].egzaminas));

            }
            else{
                vargVed.push_back(Students(studVec[p].names,studVec[p].lastNames,studVec[p].vid,studVec[p].med,studVec[p].egzaminas));

            }
            
        }  
        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        cout<< std::to_string(x)+" Neoptimizuotas: " + std::to_string(elapsedTime.count())<<"s ";


        std::ofstream foutstudVarg(".\\vector\\vargNotOptimal"  + std::to_string(x) + ".txt");
        std::ofstream foutstudKiet(".\\vector\\kietNotOptimal"  + std::to_string(x) + ".txt");
       
        for (int j = 0; j < studKiet.size(); j++)
        {
            foutstudKiet << std::left << std::setfill(' ')
                     << std::setw(20) << studKiet[j].names
                     << std::setw(20) << studKiet[j].lastNames
                     << std::setw(20) << std::setprecision(3) << studKiet[j].vid
                     << std::setw(20) << std::setprecision(2) << studKiet[j].med << endl;
        }
        for (int j = 0; j < vargVed.size(); j++)
        {
          foutstudVarg << std::left << std::setfill(' ')
                     << std::setw(20) << vargVed[j].names
                     << std::setw(20) << vargVed[j].lastNames
                     << std::setw(20) << std::setprecision(3) << vargVed[j].vid
                     << std::setw(20) << std::setprecision(2) << vargVed[j].med << endl;
        }
        foutstudVarg.close();
        foutstudKiet.close();
}
bool moreThenVid(Students h){ return h.vid>=5;}
void splitVectorOptimal(int x, vector<Students> studVec,vector<Students> studKiet){

        auto start = steady_clock::now();

        vector<Students>::iterator bound;
        bound = std::partition(studVec.begin(),studVec.end(),moreThenVid);
        //std::sort(studVec.begin(),studVec.end(),sorter);

        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;

        cout<< "Optimizuotas: " + std::to_string(elapsedTime.count())<<"s "<<endl;
        std::ofstream foutstudVarg(".\\vector\\vargOptimal"  + std::to_string(x) + ".txt");
        std::ofstream foutstudKiet(".\\vector\\kietOptimal"  + std::to_string(x) + ".txt");
        for (std::vector<Students>::iterator it = studVec.begin();it != bound ;++it)
          foutstudVarg << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
    
        for (std::vector<Students>::iterator it = bound;it != studVec.end() ;++it)
        {
          foutstudKiet << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
}
void createVector()
{        
    fs::create_directory("./vector");
    vector<Students> studVec, vargVed, studKiet;
    int x = 100000, gradeCount=0;
    string temp;
    float vid, med, i = 0, tempVid = 0, tempMed = 0,tempEgz = 0;
    vector<float> grades;
    string tempName, tempLastName;
    for (int i = 3; i < 5; i++)
    {
      studVec.reserve(x);
        std::ifstream read(".\\files\\failas" + std::to_string(x) + ".txt");
        string firstLine;
        std::getline(read, firstLine);
        while (!read.eof())
        {
            read >>tempName;
            read >> tempLastName;
            for(int l = 0;l<15;l++)
            {
                read >> temp;
                gradeCount++;
                if (l==14)
                {
                    tempEgz = std::stoi(temp);
                }
                tempVid += std::stoi(temp);
                grades.emplace_back(std::stoi(temp));
            }
            std::sort(grades.begin(), grades.end());
            tempVid = (tempVid / 14) * 0.4 + tempEgz * 0.6;
            
            tempMed = (grades[7]+grades[8])/2;       
            
            gradeCount = 0;
            studVec.emplace_back(tempName, tempLastName, tempVid,tempMed,tempEgz);

            
            grades.clear();
            tempVid = 0;
        }
     
        splitVector(x,studVec,vargVed,studKiet);
        splitVectorOptimal(x,studVec,studKiet);
       
        read.close();
        studVec.clear();
        vargVed.clear();
        studKiet.clear();
        x *= 10;

    }
}