// WalterSchaltung.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <math.h>
#include <iostream>

double isPositive(double U_e);
double isNegative(double U_e);
double biggerThan(double U_e, double otherValue);
double smallerThan(double U_e, double otherValue);
double calculateValue(double U_e, double R_1, double R_2, double R_3, double U_f, double U_gPlus,
	double U_gMinus, double U_saetiggungPlus, double U_saetiggungMinus);

int main()
{
	double U_e = -15;
	double R_1 = 10000;
	double R_2 = 20000;
	double R_3 = 10e3;
	double U_f = 0.6;
	double U_saetiggungPlus = 12;
	double U_saetiggungMinus = 12;
	double U_gPlus = U_saetiggungPlus;
	double U_gMinus = U_saetiggungMinus;


	while (U_e <= 15 ) {


		double value = calculateValue(U_e, R_1, R_2, R_3, U_f, U_saetiggungPlus, U_saetiggungMinus, U_gPlus, U_gMinus);

		printf("Fuer U_e = %d V => U_a =%d V \n",U_e,value);

		U_e += 0.5;

	}

	return 0;
}

double calculateValue(double U_e , double R_1 , double R_2 , double R_3, double U_f , double U_gPlus ,
	double U_gMinus , double U_saetiggungPlus , double U_saetiggungMinus)
{

	double value;

	value = (fabs(U_e)/U_e);

	value *= fabs(
	
					(U_saetiggungPlus * isPositive(U_e)  * biggerThan(U_e, U_gPlus))+
					(U_saetiggungMinus * isNegative(U_e) * biggerThan(U_e,U_gMinus))+
					(((R_2 * U_e)/(R_1)-U_f)*isPositive(U_e)*biggerThan(U_e,U_f)*smallerThan(U_e, U_gPlus))+
					(((R_3 * U_e)/(R_1)-U_f)*isNegative(U_e)*biggerThan(U_e,U_f)*smallerThan(U_e, U_gMinus))

					);



	return value;

}

double isPositive(double U_e)
{

	return (fabs(U_e) - U_e) / (2 * U_e);

}

double isNegative(double U_e)
{

	return (fabs(U_e) + U_e) / (2 * U_e);

}

double smallerThan(double U_e, double otherValue) 
{

	double value = fabs(log10(fabs(otherValue/U_e))) - (log10(fabs(otherValue / U_e)));

	value /= 2 * log10(fabs(otherValue / U_e));

	return value;
}

double biggerThan(double U_e, double otherValue) 
{

	double value = fabs(log10(fabs(otherValue / U_e))) + (log10(fabs(otherValue / U_e)));

	value /= 2 * log10(fabs(otherValue / U_e));

	return value;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
