#include "includes.h"
void split(int x,deque<Students> studDeq,deque<Students> vargDeq,deque<Students> kietDeq){
        auto start = steady_clock::now();

    for (auto it = studDeq.begin(); it < studDeq.end(); it++)
    {
        if(it->vid>=5)
            kietDeq.push_back({it->names,it->lastNames,it->vid,it->med,it->egzaminas});
        else
            vargDeq.push_back({it->names,it->lastNames,it->vid,it->med,it->egzaminas});
    }
     auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        cout<< std::to_string(x)+" Neoptimizuotas: " + std::to_string(elapsedTime.count())<<"s ";

        std::ofstream foutVarg(".\\deque\\vargNotOptimal" + std::to_string(x) + ".txt");
        std::ofstream foutkiet(".\\deque\\kietNotOptimal" + std::to_string(x) + ".txt");
        for (auto it = kietDeq.begin(); it < kietDeq.end(); it++)
        {
            foutVarg << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        for (auto it = vargDeq.begin(); it < vargDeq.end(); it++)
        {
            foutkiet << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        foutkiet.close();
        foutVarg.close();
}
void splitOptimal(int x, deque<Students> studDeq,deque<Students> kietDeq){
    int counter = 0;
        auto start = steady_clock::now();

    auto it = std::stable_partition(studDeq.begin(),studDeq.end(),[](Students temp){
            return temp.vid>=5;
        });
       deque<Students> vargDeq(std::make_move_iterator(it),std::make_move_iterator(studDeq.end()));
       studDeq.erase(it,studDeq.end());

        auto end = steady_clock::now();
        std::chrono::duration<double> elapsedTime = end - start;
        cout<< "Optimizuotas: " + std::to_string(elapsedTime.count())<<"s"<<endl;

        std::ofstream foutVarg(".\\deque\\vargOptimal" + std::to_string(x) + ".txt");
        std::ofstream foutkiet(".\\deque\\kietOptimal" + std::to_string(x) + ".txt");
        for (auto it = vargDeq.begin(); it < vargDeq.end(); it++)
        {
            foutVarg << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        for (auto it = studDeq.begin(); it < studDeq.end(); it++)
        {
            foutkiet << std::left << std::setfill(' ')
                     << std::setw(20) << it->names
                     << std::setw(20) << it->lastNames
                     << std::setw(20) << std::setprecision(3) << it->vid
                     << std::setw(20) << std::setprecision(2) << it->med << endl;
        }
        foutkiet.close();
        foutVarg.close();
}
void createDeque()
{
    fs::create_directory("./deque");

    int x = 100;
    string temp;
   
    deque<Students> studDeq, vargDeq, kietDeq;
    string tempName, tempLastName;
    float vid, med, i = 0,tempVid = 0, tempMed = 0,tempEgz = 0;
    deque<float> grades;
    for (int i = 0; i < 5; i++)
    {
        std::ifstream read(".\\files\\failas"+ std::to_string(x) + ".txt");
        string firstLine;
        std::getline(read, firstLine);
      while (!read.eof())
        {
            read >>tempName;
            read >> tempLastName;
            for(int l = 0;l<15;l++)
            {
                read >> temp;
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
            
            studDeq.emplace_back(tempName, tempLastName, tempVid,tempMed,tempEgz);

            
            grades.clear();
            tempVid = 0;
        }
        std::sort(studDeq.begin(), studDeq.end(), [](const Students& a, const Students& b) { 
         return a.vid > b.vid;
        });
        split(x,studDeq,vargDeq,kietDeq);
        splitOptimal(x,studDeq,kietDeq);
        

        
        read.close();
        studDeq.clear();        
        vargDeq.clear();
        kietDeq.clear();
        x *= 10;

    }
}

