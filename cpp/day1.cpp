#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

int main(int argc, char* argv[]) {
    
    std::string line;
    std::ifstream myfile ("input1.txt");
    std::vector<int> mylist;
    
    if (myfile.is_open())
    {
        while (myfile.good() )
        {
            myfile >> line;
            int value = std::atoi(line.c_str());
            mylist.push_back(value);
        }
        myfile.close();
    }

    // Part 1    
    int measurements = 0;
    for (auto it = mylist.begin();  it != mylist.end(); it++) {

        if (*std::next(it, 1) > *it) {
            measurements++;
        }
    }
    std::cout << measurements << '\n';
    
    // Part 2
    // Method 1
    measurements = std::inner_product(mylist.begin(), std::next(mylist.end(), -4), std::next(mylist.begin(), 3), 0, std::plus<>(), std::less<>());
    std::cout << "inner product : " << measurements << '\n';
    
    // Method 2
    measurements = 0;
    for (auto it = mylist.begin();  it != std::next(mylist.end(), -4); it++) {
        auto first = *it + *std::next(it, 1) + *std::next(it, 2);
        auto second = *std::next(it, 1) + *std::next(it, 2) + *std::next(it, 3);
        if (second > first) {
            measurements++;
        }
    }
    std::cout << "iterator for : " << measurements << '\n';
    
    // Method 3
    measurements = 0;
    int last = std::numeric_limits<int>::max();
    for(int i = 0; i < mylist.size() - 3; i++) {
        int thisWindow = mylist.at(i) + mylist.at(i + 1) + mylist.at(i + 2);
        if(thisWindow > last)
            measurements++;
        last = thisWindow;
    }
    std::cout << "classical for : " << measurements << '\n'; 
}
