#include "include/IterationResult.hh"
#include "include/canvas.hh"
#include <cmath>
#include <iostream>

IterationResult iterateMandel(Point z, Point c, double threshold, int maxIt, bool smooth=false)
{
    IterationResult iterationResult;
    double distance;
    double norm;
    Point p = z;
    iterationResult.setPoint(p);
    iterationResult.setIterations(0);
    for(int i=0; i<maxIt; i++)
    {
        Point p((std::pow(iterationResult.getPoint().getX(), 2)-std::pow(iterationResult.getPoint().getY(), 2) + c.getX()), (2*iterationResult.getPoint().getX()*iterationResult.getPoint().getY() + c.getY()));
        
        iterationResult.setPoint(p);
        iterationResult.setIterations(i+1);
        distance = sqrt(std::pow(p.getX()-c.getX(), 2) + std::pow(p.getY()-c.getY(), 2));

        
        if(smooth)
        {
            norm = sqrt(std::pow(p.getX(), 2) + std::pow(p.getY(), 2));
            float k = i - log2(log1p(norm)/log1p(threshold));
            iterationResult.setIterations(k);
        }
        
        if(distance >= threshold)
        { 
            return iterationResult;
        }
            
    }
    return iterationResult;
}

IterationResult iterate(Point z, Point c, double threshold, int maxIt, bool smooth=false)
{
    IterationResult iterationResult;
    double distance;
    double norm;
    Point p = z;
    iterationResult.setPoint(p);
    iterationResult.setIterations(0);
    for(int i=0; i<maxIt; i++)
    {
        Point p((std::pow(iterationResult.getPoint().getX(), 2)-std::pow(iterationResult.getPoint().getY(), 2) + c.getX()), (2*iterationResult.getPoint().getX()*iterationResult.getPoint().getY() + c.getY()));
        
        iterationResult.setPoint(p);
        iterationResult.setIterations(i+1);
        distance = sqrt(std::pow(p.getX()-c.getX(), 2) + std::pow(p.getY()-c.getY(), 2));

        
        if(smooth)
        {
            norm = sqrt(std::pow(p.getX(), 2) + std::pow(p.getY(), 2));
            float k = i - log2(log1p(norm)/log1p(threshold));
            iterationResult.setIterations(k);
        }

        if(distance >= threshold)
            return iterationResult;
    }
    return iterationResult;
}

void mandelbrot(Canvas& canvas, double threshold, int maxIt, std::string filename)
{
    for(int i=0; i<canvas.getHor(); ++i)
    { 
        for(int j=0; j<canvas.getVert(); ++j)
        {
            IterationResult iterationResult = iterateMandel(Point(0.0, 0.0), canvas.coord(i, j), threshold, maxIt, true);
            if(iterationResult.getIterations() == maxIt)
            {
                canvas.setBrightness(i, j, 0);
            }
            else
            {
                canvas.setBrightness(i, j, std::log(iterationResult.getIterations()) * 100);
                
            }
            std::cout << canvas.brightness(i, j) << std::endl;

            if(i*j+1 == 60151 || i*j+1 == 90151)
                canvas.setBrightness(i, j, 691);
        }
    }

    canvas.write(filename);
    
}

void julia (Point c, Canvas& canvas, double threshold, int maxIt, std::string filename)
{
    for(int i=0; i<canvas.getHor(); ++i)
    { 
        for(int j=0; j<canvas.getVert(); ++j)
        {
            IterationResult iterationResult = iterate(canvas.Coord(i, j), c, threshold, maxIt, true);
            if(iterationResult.getIterations() == maxIt)
            {
                canvas.setBrightness(i, j, 0);
            }
            else
            { 
                canvas.setBrightness(i, j, std::log(iterationResult.getIterations()) * 100);
            }


            
        }
    }

    canvas.write(filename);
}

int main()
{
    Canvas canvas(Point(-1, 0), 4, 3, 400, 300);
    mandelbrot(canvas, 1000, 1000, "../mandelbrotImage");
    Point c(-0.8, 0.156);
    Canvas canvas2(c, 4, 3, 400, 300);
    julia(c, canvas2, 1000, 1000, "../juliaImage");
}