
#include "line.h"

Line::Line()
{

}
double Line::set_x(double lon){
    double x=120.40,t;
    t=lon-x;
    return t*4000;
}

double Line::set_y(double lat){
    double y=36.12,t;
    t=y-lat;
    return t*4000;
}
