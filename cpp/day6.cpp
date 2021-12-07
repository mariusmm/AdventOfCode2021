#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>

int main(int argc, char* argv[]) {
    
    std::string line;
    std::ifstream myfile ("input6.txt");
    std::array<std::uint64_t, 9> mylist = {0};
    std::string word;
    
    if (myfile.is_open())
    {
        std::getline(myfile, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            mylist[std::atoi(word.c_str())]++;
        }
        
        myfile.close();
    }

    std::cout << "Init state" << std::endl;
    for(int i = 0; i < mylist.size();i++) {
        std::cout << mylist[i] << ", ";
    }
    std::cout << std::endl;


    for (int j = 0; j < 256; j++) {
        
        auto zeros = mylist[0];
        
        for (int i = 0; i < mylist.size()-1; i++) {            
            mylist[i] = mylist[i+1];
        }
        
        mylist[8] = zeros;
        mylist[6] += zeros;
        
//         for(int i = 0; i < mylist.size();i++) {
//             std::cout << mylist[i] << ", ";
//         }
//         std::cout << std::endl;
    }

    std::cout << "Finish state" << std::endl;

    std::uint64_t acc = 0;
    for(int i = 0; i < mylist.size();i++) {
        acc += mylist[i];
        std::cout << mylist[i] << ", ";
    }
    std::cout << std::endl;
    
    std::cout << "Total = " << acc << std::endl;
}
