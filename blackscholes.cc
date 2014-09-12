/*

Black Scholes formula

Only works with call currently

To Do:
Put option

Still being worked on

*/

#include "blackscholes.h"

double Norm(double z){
	double normaldis = 1 / sqrt(2 * Pi) * exp(-pow(z,2)/2);

	// 1 / (Math.Sqrt(2 * Math.PI)) * Math.Exp(-Math.Pow(z, 2) / 2)
	return normaldis;
}

double NormalDis(double x){
	double b[] = {0.2316419, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429};

	// double t = 1 / (1 + b0 * x);
 	// double sigma = 1 - Norm(x) * (b1 * t + b2 * Math.Pow(t, 2) + b3 * Math.Pow(t, 3 + b4 * Math.Pow(t, 4) + b5 * Math.Pow(t, 5));

	double l = abs(x);
	double t = 1.0 / (1.0 + b[0] * l);
	double sigma = 1.0 - Norm(l) * ((b[1] * t) + (b[2] * pow(t , 2)) + (b[3] * pow(t, 3)) + (b[4] * pow(t, 4)) + (b[5] * pow(t, 5)));

	return sigma;
}

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

void call(double s, double x, double r, double t ,double sigma){
	double days = t/365.0;
	double v = sigma/100.0;
	double rate = r/100.0;
	double D1 = d1(s, x, rate, days, v);
	double D2 = d2(s, x, rate, days, v);
	// AssetPrice * NormsDist(d1) - Strike * Math.Exp(-InterestRate * Expiry) * NormsDist(d2); call
	double call = s*NormalDis(D1) -  x*(exp(-r*t)) * NormalDis(D2);

	printf("%f\n", D1);
	printf("%f\n", D2);
	printf("%f\n", call);
}

int main(int argc, char **argv){
	double stock_price = 210.59;
	double excersise_price = 205;
	double risk_free_interest = 0.2175; // also entered in percentage
	double days = 4;
	double sigma = 14.05; //entered in percetage

	//d1 = 1.838098
	//d2 = 1.823390
	//call = 5.6381

	call(stock_price, excersise_price, risk_free_interest, days, sigma);
	printf("%f\n", d1(stock_price, excersise_price, risk_free_interest, days, sigma));
	printf("%f\n", d2(stock_price, excersise_price, risk_free_interest, days, sigma));
}