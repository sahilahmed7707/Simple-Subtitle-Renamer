#include <iostream>
#include <filesystem>
#include <sstream>
namespace fs = std::filesystem;
int main()
{
    std::cout << "Enter the path to work in is the form of - D:/Directory/Subdirectory/Modify This Folder Contents" << std::endl;
    std::string path{};
    std::getline(std::cin, path);
    std::vector<std::string> videonames;
    std::vector<fs::directory_entry> subs;
    std::cout << "Enter video file extension last 3 characters only, Example mp4"<<std::endl;
    std::string ext1{};
    std::cin >> ext1;
    for (const auto& entry : fs::directory_iterator(path))             //Checks all the files in the directory whether they are a video file and adds them to a vector if they are
    {
        std::stringstream stream;
        stream << entry.path();
        std::string st = stream.str();
        int a = st.size();
        char e1 = ext1.at(0), e2 = ext1.at(1), e3 = ext1.at(2);
        if((st.at(a-4)==e1) && (st.at(a - 3) == e2) && (st.at(a-2) == e3))
        videonames.push_back(st);
    }
    int x = 0;
    std::cout << "Enter subtitle file extension last 3 characters only, Example srt" << std::endl;
    std::string ext2{};
    std::cin >> ext2;
    for (auto &entry : fs::directory_iterator(path))                    //Checks all the files in the directory whether they are a subtitle file and renames them to the corresponding video name if they are
    {
        std::stringstream stream;
        stream << entry.path();
        std::string st = stream.str();
        int a = st.size();
        char e1 = ext2.at(0), e2 = ext2.at(1), e3 = ext2.at(2);
        if ((st.at(a - 4) == e1) && (st.at(a - 3) == e2) && (st.at(a - 2) == e3)&&(x<=videonames.size()))
        {
            std::string a = videonames.at(x);
            int start = a.find("\\");
            std::string targetname;
            for(int i=1;i<start+1;i++) 
                targetname.push_back(a.at(i));
            for (int i = start + 2; i < a.size() - 4; i++)
            {
                targetname.push_back(a.at(i));
            }
            targetname.append("srt");
            fs::path sttr(targetname);
            std::cout << targetname << std::endl;
            fs::rename(entry.path(), targetname);
            std::cout << entry.path() << std::endl;
            x++;
        }
    }
    return 0;
}
