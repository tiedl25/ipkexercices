#include <iostream>
#include <fstream>
#include <vector>
#include <array>

std::vector<std::array<double, 2>> read_point_from_file(std::string filename)
{
    std::vector<std::array<double, 2>> pointVector{30};
    std::fstream file;
    file.open(filename, std::ios::in);

    if (file.is_open())
    {
        std::string line;
        int i = 0;
        int cache;
        while(std::getline(file, line))
        {
            cache = line.find(" ");
            std::cout << stold(line.substr(0, cache)) << "    " << stold(line.substr(cache, sizeof(line))) << std::endl;
            pointVector[i] = {stod(line.substr(0, cache)), stod(line.substr(cache, sizeof(line)))};
            i++;
        }
        file.close();
    }

    return pointVector;
}

int main()
{
    read_point_from_file("convex-hull-points.txt");

    return 0;
}