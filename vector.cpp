#include "includes.h"
// bool sorter(Students lhs, Students rhs)
// {
//     if (lhs.getVid() < rhs.getVid())
//     {
//         return true;
//     }
//     return false;
// }
// void splitVector(int x, vector<Students> &studVec, vector<Students> &vargVed,vector<Students> &studKiet){
//       cout<<endl;
//     std::sort(studVec.begin(),studVec.end(),sorter);
//     auto start = steady_clock::now();
//     vector<Students> tempVec;
//     for (int p = 0; p < x; p++)
//         {

//             tempVec[0].setProps(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());

//             //<<tempVec[0].getVid()<<endl;
//            // Students student = new Students.stud(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());
//             if (studVec[p].getVid() >= 5){
//                 studKiet.push_back(tempVec[0]);

//                 //emplace_back(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());
//             }
//             else{
//                 vargVed.push_back(tempVec[0]);
//                // emplace_back(studVec[p].getName(),studVec[p].getLastName(),studVec[p].getVid(),studVec[p].getMed(),studVec[p].getEgzam());
//             }
//            // cout<<tempVec[0].getName()<<endl;
//             tempVec.clear();
//             //tempVec.push_back(Students("","",0,0,0));
//             tempVec[0].setProps("","",0,0,0);

            
//         }  
//         auto end = steady_clock::now();
//         std::chrono::duration<double> elapsedTime = end - start;
//         cout<< std::to_string(x)+" Neoptimizuotas: " + std::to_string(elapsedTime.count())<<"s ";


//         std::ofstream foutstudVarg(".\\vector\\vargNotOptimal"  + std::to_string(x) + ".txt");
//         std::ofstream foutstudKiet(".\\vector\\studNotOptimal"  + std::to_string(x) + ".txt");
       
//         for (int j = 0; j < studKiet.size(); j++)
//         {
//             foutstudKiet << std::left << std::setfill(' ')
//                      << std::setw(20) << studKiet[j].getName()
//                      << std::setw(20) << studKiet[j].getLastName()
//                      << std::setw(20) << std::setprecision(3) << studKiet[j].getVid()
//                      << std::setw(20) << std::setprecision(2) << studKiet[j].getMed() << endl;
//         }
//         for (int j = 0; j < vargVed.size(); j++)
//         {
//           foutstudVarg << std::left << std::setfill(' ')
//                      << std::setw(20) << vargVed[j].getName()
//                      << std::setw(20) << vargVed[j].getLastName()
//                      << std::setw(20) << std::setprecision(3) << vargVed[j].getVid()
//                      << std::setw(20) << std::setprecision(2) << vargVed[j].getMed() << endl;
//         }
//         foutstudVarg.close();
//         foutstudKiet.close();
// }
// bool moreThengetVid(Students h){ return h.getVid()>=5;}/*
/*void splitVectorOptimal(int x, vector<Students> &studVec,vector<Students> &studKiet){

      cout<<" asf"<<endl;
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
*/
void createVector()
{        
  Stud stud;

  stud.vid(5);
}