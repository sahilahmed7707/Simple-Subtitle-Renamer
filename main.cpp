#include <iostream>
#include <filesystem>
#include <sstream>
namespace fs = std::filesystem;
int main()
{
    std::cout<<"Enter the path to work in is the form of - D:/Directory/Subdirectory/Modify This Folder Contents"<<std::endl;
    std::string path{};
    std::getline(std::cin,path);
    //std::string path = "D:/Movies And Series/Series/Modern Family/New folder";
    std::vector<std::string> videonames;
    std::vector<fs::directory_entry> subs;
    

}
