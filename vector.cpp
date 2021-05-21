#include "includes.h"
bool sorter(Students lhs, Students rhs)
{
    if (lhs.getVid() < rhs.getVid())
    {
        return true;
    }
    return false;
}
void splitVector(int x, vector<Students> &studVec, vector<Students> &vargVed,vector<Students> &studKiet){
    std::sort(studVec.begin(),studVec.end(),sorter);
    auto start = steady_clock::now();
    vector<Students> tempVec;
    tempVec.push_back(Students(" ","",0,0,0));
    for (int p = 0; p < x; p++)
        {
            tempVec[0].setName(studVec[p].getName());
            tempVec[0].setLastName(studVec[p].getLastName());
            tempVec[0].setMed(studVec[p].getMed());
            tempVec[0].setVid(studVec[p].getVid());
            tempVec[0].setEgzam(studVec[p].getEgzam());

            //<<tempVec[0].getVid()<<endl;
           // Students student = new Students.stud(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());
            if (studVec[p].getVid() >= 5){
                studKiet.push_back(tempVec[0]);

                //emplace_back(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());
            }
            else{
                vargVed.push_back(tempVec[0]);
               // emplace_back(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());
            }
           // cout<<tempVec[0].getName()<<endl;
            tempVec.clear();
            tempVec.push_back(Students("","",0,0,0));

            
        }  
        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        cout<< std::to_string(x)+" Neoptimizuotas: " + std::to_string(elapsedTime.count())<<"s ";


        std::ofstream foutstudVarg(".\\vector\\vargNotOptimal"  + std::to_string(x) + ".txt");
        std::ofstream foutstudKiet(".\\vector\\studNotOptimal"  + std::to_string(x) + ".txt");
       
        for (int j = 0; j < studKiet.size(); j++)
        {
            foutstudKiet << std::left << std::setfill(' ')
                     << std::setw(20) << studKiet[j].getName()
                     << std::setw(20) << studKiet[j].getLastName()
                     << std::setw(20) << std::setprecision(3) << studKiet[j].getVid()
                     << std::setw(20) << std::setprecision(2) << studKiet[j].getMed() << endl;
        }
        for (int j = 0; j < vargVed.size(); j++)
        {
          foutstudVarg << std::left << std::setfill(' ')
                     << std::setw(20) << vargVed[j].getName()
                     << std::setw(20) << vargVed[j].getLastName()
                     << std::setw(20) << std::setprecision(3) << vargVed[j].getVid()
                     << std::setw(20) << std::setprecision(2) << vargVed[j].getMed() << endl;
        }
        foutstudVarg.close();
        foutstudKiet.close();
}
bool moreThengetVid(Students h){ return h.getVid()>=5;}
void splitVectorOptimal(int x, vector<Students> &studVec,vector<Students> &studKiet){

        auto start = steady_clock::now();

        vector<Students>::iterator bound;
        bound = std::partition(studVec.begin(),studVec.end(),moreThengetVid);
        //std::sort(studVec.begin(),studVec.end(),sorter);
        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;

        cout<< "Optimizuotas: " + std::to_string(elapsedTime.count())<<"s "<<endl;
        std::ofstream foutstudVarg(".\\vector\\vargOptimal"  + std::to_string(x) + ".txt");
        std::ofstream foutstudKiet(".\\vector\\kietOptimal"  + std::to_string(x) + ".txt");
        for (std::vector<Students>::iterator it = studVec.begin();it != bound ;++it)
          foutstudVarg << std::left << std::setfill(' ')
                     << std::setw(20) << it->getName()
                     << std::setw(20) << it->getLastName()
                     << std::setw(20) << std::setprecision(3) << it->getVid()
                     << std::setw(20) << std::setprecision(2) << it->getMed() << endl;
    
        for (std::vector<Students>::iterator it = bound;it != studVec.end() ;++it)
        {
          foutstudKiet << std::left << std::setfill(' ')
                     << std::setw(20) << it->getName()
                     << std::setw(20) << it->getLastName()
                     << std::setw(20) << std::setprecision(3) << it->getVid()
                     << std::setw(20) << std::setprecision(2) << it->getMed() << endl;
        }
}
void createVector()
{        
    fs::create_directories("./vector");
    vector<Students> studVec, vargVed, studKiet;
    int x = 100000, gradeCount=0;
    string temp;
    float i = 0, tempVid = 0, tempMed = 0,tempEgz = 0;
    vector<float> grades;
    string tempName, tempLastName;
    for (int i = 0; i < 2; i++)
    {
        studVec.reserve(x);
        std::ifstream read(".\\files\\failas" + std::to_string(x) + ".txt");
        string firstLine;
        vector<Students> tempVec;
        tempVec.push_back(Students("","",0,0,0));
        std::getline(read, firstLine);
        int counter = 0;
        while (!read.eof())
        {
            //cout<<"tempVec[0].getName()"<<endl;
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
           // cout<<"tempVec[1].getName()"<<endl;
            std::sort(grades.begin(), grades.end());
            tempVid = (tempVid / 14) * 0.4 + tempEgz * 0.6;
            
            tempMed = (grades[7]+grades[8])/2;       
            
           
            tempVec[0].setName(tempName);
            tempVec[0].setLastName(tempLastName);
            tempVec[0].setMed(tempMed);
            tempVec[0].setVid(tempVid);
            tempVec[0].setEgzam(tempEgz);
            studVec.push_back(tempVec[0]);
            tempVec.clear();
            tempVec.push_back(Students(" "," ",0,0,0));
            counter++;
            grades.clear();
            tempVid = 0;
            gradeCount = 0;
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