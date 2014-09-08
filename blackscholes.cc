#include "blackscholes.h"

//still in progress

// double Normal(double x){
	
// 	double l,k,w;

// 	double a1 = 0.31938153;
// 	double a2 = -0.356563782; 
// 	double a3 = 1.781477937;
// 	double a4 = -1.821255978;
// 	double a5 = 1.330274429;


// 	l = fabs(x);
// 	k = 1.0 / (1.0+0.2)
// }

double d1(double s, double x, double r, double t, double sigma){
	double days = t/365.0;
	double v = sigma/100.0;
	double rate = r/100.0;

	return (log(s/x) + (rate + v*v/2)*days) / (v * sqrt(days));
}

double d2(double s, double x, double r, double t, double sigma){
	double days = t/365.0;
	double v = sigma/100.0;
	double rate = r/100.0;

	return ((log(s/x) + (rate + v*v/2)*days) / (v * sqrt(days))) - (v * sqrt(days));
}

int main(int argc, char **argv){
	double stock_price = 210.59;
	double excersise_price = 205;
	double risk_free_interest = 0.2175; // also entered in percentage
	double days = 4;
	double sigma = 14.05; //entered in percetage

	//d1 = 1.838098
	//d2 = 1.823390

	printf("%f\n", d1(stock_price, excersise_price, risk_free_interest, days, sigma));
	printf("%f\n", d2(stock_price, excersise_price, risk_free_interest, days, sigma));
}