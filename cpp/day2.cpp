#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char* argv[]) {
    
    std::string command;
    int value;
    std::ifstream myfile ("input2.txt");
    
    int depth_part1 = 0;
    int depth_part2 = 0;
    int total_horizontal = 0;
    int aim = 0;
    
    if (myfile.is_open())
    {
        while (myfile >> command >> value)
        {
//             std::cout << command << std::endl;
//             std::cout << value << std::endl;
            
            if (command == "down") {
                    depth_part1 += value;
                    aim += value;
            }  else if (command == "up") {
                    depth_part1 -= value;
                    aim -= value;
            } else if (command == "forward") {
                total_horizontal += value;
                depth_part2 += aim * value;
            }
            
        }
        myfile.close();
    }
    
    std::cout << "Depth part 1: " << depth_part1 << std::endl;
    std::cout << "Total Horizontal: " << total_horizontal << std::endl;
    std::cout << "Depth part 2: " << depth_part2 << std::endl;
    std::cout << "Result Part 1: " << depth_part1 * total_horizontal << std::endl;
    std::cout << "Result Part 2: " << depth_part2 * total_horizontal << std::endl;
}   
