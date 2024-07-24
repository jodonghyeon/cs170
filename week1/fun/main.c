#include<stdio.h>
#include<math.h>

int main()
{
    const double px =0,py=0;
    const double qx=3,qy=4;
    const double w=qx-px, h =qy-py;
    const double dist =sqrt(w*w+h*h);

    printf("Distance is %g",dist);

    return 0;
}