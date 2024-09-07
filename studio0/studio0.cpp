/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator
#include <ofstream> 

using namespace std; // optional, could say std::cout and std::endl below instead

const int SUCCESS = 0;
const int ERROR_WRONG_ARGUMENTS = 1;
const int ERROR_OPEN_FILE = 2;

int main(int argc, char* argv[]) {
   
    if (argc < 2) {
        std::cerr << "usage: studio0 <arg1> [<arg2> ...]" << std::endl;
        return ERROR_WRONG_ARGUMENTS;
    }

    std::cout << "Number of arguments: " << argc - 1 << std::endl;
    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
        std::ofstream outFile(argv[i]) 

        if (!outFile) {
            std::cerr << "Error: Could not open file " << argv[i] << " for writing." << std::endl;
            return ERROR_FILE_OPEN;
        }

        // Write output to the file
        outFile << "Number of arguments: " << argc - 1 << std::endl;
        for (int j = 1; j < argc; ++j) {
            outFile << "Argument " << j << ": " << argv[j] << std::endl;
        }
    }

    return SUCCESS;
}