#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    
    std::string line;
//     std::ifstream myfile ("test.txt");
    std::ifstream myfile ("input7.txt");
    std::vector<int> mylist;
    std::string word;
    
    if (myfile.is_open())
    {
        std::getline(myfile, line);
        std::stringstream s(line);
        while (getline(s, word, ',')) {
            mylist.push_back(std::atoi(word.c_str()));
        }
        
        myfile.close();
    }


    // Part 1 - calc median and distance to it for every item 
    std::sort(mylist.begin(), mylist.end());
    auto median = mylist[(mylist.size()/2)];

    auto acc = 0;
    for (auto &x: mylist)  {
        acc += std::abs(x-median);
    }
    
    std::cout << "part 1 = " << acc <<std::endl;
    
    // Part 2
}
