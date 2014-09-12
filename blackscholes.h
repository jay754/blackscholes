#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define Pi 3.141592653589793238462643

double Norm(double z);
double NormalDis(double x);
double d1(double s, double x, double r, double t, double sigma);
double d2(double s, double x, double r, double t, double sigma);
void call(double s, double x, double r, double t, double sigma);