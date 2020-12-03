#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>

//Liest Punkte aus Datei und speichert sie in Vector
std::vector<std::array<double, 2>> read_points_from_file(std::string filename)
{
    std::vector<std::array<double, 2>> pointVector;
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
            
            pointVector.push_back({stod(line.substr(0, cache)), stod(line.substr(cache, sizeof(line)))});
            i++;
        }
        file.close();
    }

    return pointVector;
}

void write_points_in_file(std::string filename, std::vector<std::array<double, 2>>& points)
{
    std::fstream file;
    file.open(filename, std::ios::out);

    for(int i=0; i<points.size(); i++)
    {
        file << points[i][0] << " " << points[i][1] << std::endl;
    }

    file.close();
}

bool sort_by_y(std::array<double, 2> a, std::array<double, 2> b)
{
    if(a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]))
        return 1;

    return 0;
}

bool sort_by_angle(std::array<double, 2> a, std::array<double, 2> b)
{
    if(a[0]*b[1]-a[1]*b[0] > 0  || (a[0]*b[1]-a[1]*b[0] == 0 && std::abs(a[0]) > std::abs(b[0])))
        return 1;

    return 0;
}

//Überprüft ob ein Punkt Rechts oder links eines Vectors liegt
double leftOrRight(std::vector<std::array<double, 2>>& grahamStack, std::array<double, 2>& point)
{
    return (grahamStack[grahamStack.size() - 1][0] - grahamStack[grahamStack.size() - 2][0])
         * (point[1] - grahamStack[grahamStack.size() - 2][1])
         - (point[0] - grahamStack[grahamStack.size() - 2][0])
         * (grahamStack[grahamStack.size() - 1][1] - grahamStack[grahamStack.size() - 2][1]);
}

//Graham-Scan Algorithmus
std::vector<std::array<double, 2>> grahamScan(std::vector<std::array<double, 2>>& points, std::vector<std::array<double, 2>>& grahamStack)
{
    int i = 0;

    while(i<points.size())
    {
        if(i<2 || leftOrRight(grahamStack, points[i]) >= 0 || grahamStack.size() == 2)
        {
            grahamStack.push_back(points[i]); 
            i++;
        }
        else
            grahamStack.erase(grahamStack.begin() + grahamStack.size() - 1);            
    }

    return grahamStack;
}

//Funktion berechnet die Konvexe Hülle einer gegebenen Menge von Punkten
void convex_hull(std::vector<std::array<double, 2>>& points)
{
    std::sort(points.begin(), points.end(), sort_by_y); //Punkte werden nach Y-Wert sortiert

    for(int i=1; i<points.size(); i++)
    {
        points[i][0] = {points[i][0] - points[0][0]};
        points[i][1] = {points[i][1] - points[0][1]};
    } 

    std::sort(points.begin()+1, points.end(), sort_by_angle); //Punkte werden nach Winkel sortiert

    for(int i=1; i<points.size(); i++)
    {
        points[i][0] = {points[i][0] + points[0][0]};
        points[i][1] = {points[i][1] + points[0][1]};
    }

    std::vector<std::array<double, 2>> grahamStack;


    grahamStack = grahamScan(points, grahamStack);
    
    write_points_in_file("hull.txt", grahamStack);
}

int main()
{
    std::vector<std::array<double, 2>> vec = read_points_from_file("points.txt");

    convex_hull(vec);

    return 0;
}