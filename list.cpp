#include "includes.h"
bool removeVarg(const Students& lst){return lst.vid>=5;}
bool searchVarg(Students a){ return a.vid>=5;}
void splitList(int x, list<Students> studList, list<Students> vargList,list<Students> kietList){
        auto start = steady_clock::now();

        list<Students>::iterator it;
        for (it = studList.begin();it != studList.end();it++)
        {
            if (it->vid >= 5){
                kietList.push_back(Students(it->names,it->lastNames,it->vid,it->med,it->egzaminas));

            }
            else{
                vargList.push_back(Students(it->names,it->lastNames,it->vid,it->med,it->egzaminas));

            }
            
        }
        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        cout<< std::to_string(x)+" Neoptimizuotas: " + std::to_string(elapsedTime.count())<<"s ";

        std::ofstream foutvargList(".\\list\\vargNotOptimal"  + std::to_string(x) + ".txt");
        std::ofstream foutkietList(".\\list\\kietNotOptimal"  + std::to_string(x) + ".txt");
        for (it = kietList.begin();it != kietList.end();it++)
        {
            foutkietList << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
            for (it = vargList.begin();it != vargList.end();it++)
        {
          foutvargList << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        foutvargList.close();
        foutkietList.close();
}
void splitListOptimal(int x, list<Students> studList,list<Students> kietList){

        // list<Students>::iterator it = std::copy_if(studList.begin(),studList.end(),kietList.begin(),[](Students i){return (i.vid>=5);});
        // list<Students> optKietList (studList.size());
        // //kietList.resize(std::distance(kietList.begin(),it));
        auto start = steady_clock::now();

        list<Students>::iterator it;
        for (it = studList.begin();it != studList.end();it++)
        {
            if (it->vid >= 5)
                kietList.push_back(Students(it->names,it->lastNames,it->vid,it->med,it->egzaminas));        
        }
        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        cout<< std::to_string(x)+" Optimizuotas: " + std::to_string(elapsedTime.count())<<"s"<<endl;
        studList.remove_if(removeVarg);
        std::ofstream foutvargList(".\\list\\vargOptimal"  + std::to_string(x) + ".txt");
        std::ofstream foutkietList(".\\list\\kietOptimal"  + std::to_string(x) + ".txt");
        for (it = kietList.begin();it != kietList.end();it++)
        {
            foutkietList << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        for (it = studList.begin();it != studList.end();it++)
        {
          foutvargList << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        foutvargList.close();
        foutkietList.close();
}
void createList(){
    fs::create_directory("./list");

list<Students> studList, vargList, kietList;
   int x = 100, gradeCount=0;
    string temp;
    float vid, med, i = 0, tempVid = 0, tempMed = 0,tempEgz = 0;
    vector<float> grades;
    string tempName, tempLastName;
    for (int i = 0; i < 5; i++)
    {
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
            studList.emplace_back(tempName, tempLastName, tempVid,tempMed,tempEgz);

            
            grades.clear();
            tempVid = 0;
        }
        
        studList.sort([]( const Students& a, const Students&b ){
            return a.vid < b.vid;
        } );
        splitList(x,studList,vargList,kietList);
        splitListOptimal(x,studList,kietList);
        read.close();
        studList.clear();
        vargList.clear();
        kietList.clear();
        x *= 10;

    }
}