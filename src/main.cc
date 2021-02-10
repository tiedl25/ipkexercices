#include <vector>

#include "include/sdlwrapper.hh"
#include "include/point.hh"
#include "include/body.hh"

Point coord(int i, int j, Point mid, double width, double height, double horPixels, double vertPixels)
{
    double x = mid.getX() - width/2 + width/horPixels * i;
    double y = mid.getY() - height/2 + height/vertPixels * j;
    return Point(x, y);
}

template<typename Mass>
void displayBodies(SDLCanvas& canvas, Mass& bodies)
{
    while(!canvas.windowClosed())
    { 
        //eulerStep(Force, bodies, 0, 0.1);
        for(std::size_t i=0; i<bodies.size(); ++i)
        {
            Point p = {bodies[i].getPosition().getX() + 1280/2, bodies[i].getPosition().getY() + 720/2};
            canvas.drawPixel(p.getX(), p.getY(), bodies[i].getColour());
        }
        canvas.display();
    }
}



int main()
{
    SDLCanvas canvas("Title", 1280, 720);
    std::vector<Body> bodies = {
        {{0, 0}, {0, 0}, 1e3, {255, 0, 0}},
        {{100, 0}, {0, 0.3}, 10, {0, 255, 0}},
        {{-200, 0}, {0, 0.2}, 10, {0, 0, 255}},
        {{0, 250}, {-0.25, 0}, 10, {255, 255, 0}},
    };

    std::vector<Body> bodies2 = {
        {{150, 0}, {0,-0.2}, 1e3, {255, 0, 0}},
        {{-150, 0}, {0, 0.2}, 1e3, {0, 255, 0}},
        {{0, 150}, {0.2, 0}, 1e3, {0, 0, 255}},
        {{0, -150}, {-0.2, 0}, 1e3, {255, 255, 0}},
    };

    displayBodies(canvas, bodies);
}