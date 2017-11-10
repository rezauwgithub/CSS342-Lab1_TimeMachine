// TimeMachine.cpp : Defines the entry point for the console application.
//

// Reza Naeemi

#include "stdafx.h"
#include "TimeSpan.h"
#include "VendingBank.h"

#include <iostream>

using namespace std;


int main()
{

	TimeSpan duration(3, 4, 5);
	TimeSpan durationCopy(1.5, 4, -10);
	TimeSpan duration2(1, 2, 3);
	TimeSpan durationN(-3, -2, -4);


	TimeSpan durationOverSixty(64, 62, 67);
	TimeSpan durationOverSixty2(334, 423, 234);
	TimeSpan durationOverSixtyN(63, -66, -65);
	TimeSpan durationOverSixtyN2(64, -66, 264);

	cout << durationOverSixty << endl;
	cout << durationOverSixty2 << endl;
	cout << durationOverSixtyN << endl;
	cout << durationOverSixtyN2 << endl;

	// Handling Negative Minutes or Seconds
	cout << endl << endl << "- Handling Negative Minutes or Seconds - " << endl;
	cout << durationCopy << endl;

	// Addition Operator
	cout << endl << endl  << "- Addition - " << endl;
	TimeSpan durationAdditionResult = duration + duration2;
	cout << durationAdditionResult << endl;

	TimeSpan durationAdditionResultN = duration + durationN;
	cout << durationAdditionResultN << endl;



	// Subtraction Operator
	cout << endl << endl << "- Subtraction - " << endl;
	TimeSpan durationSubtractionResult = duration - duration2;
	cout << durationSubtractionResult << endl;

	TimeSpan durationSubtractionResultN = duration - durationN;
	cout << durationSubtractionResultN << endl;


	
	// == Operator
	cout << endl << endl << "- == Operator - " << endl;
	cout << (duration == durationCopy) << endl;
	cout << (duration == duration2) << endl;



	// != Operator
	cout << endl << endl << "- != Operator - " << endl;
	cout << (duration != durationCopy) << endl;
	cout << (duration != duration2) << endl;


	
	// += Operator
	cout << endl << endl << "- += Operator - " << endl;
	durationCopy += duration;
	cout << durationCopy << endl;

	// -= Operator
	cout << endl << endl << "- -= Operator - " << endl;
	durationCopy -= duration2;
	cout << durationCopy << endl;



	// istream Operator
	cout << endl << endl << "- istream Operator - " << endl;
	cout << "(e.g  53 4 34) - Integers ONLY!" << endl;
	TimeSpan istreamTest;
	cin >> istreamTest;
	cout << istreamTest << endl;



	// Unary Negation Operator
	cout << endl << endl << "- Unary Negation Operator - " << endl;
	TimeSpan unaryNegationOperatorTest;
	unaryNegationOperatorTest = -duration;
	cout << unaryNegationOperatorTest << endl;



	system("pause");
    return 0;
}

