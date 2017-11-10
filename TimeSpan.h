#pragma once

#include <iostream>

using namespace std;

class TimeSpan
{

private:
	int hours;
	int minutes;
	int seconds;

	void handleDecimalsInMinutes(double &minutes, double &seconds);
	void handleDecimalsInHours(double &hours, double &minutes);
	
	void handleNegativeMinutesOrSeconds(int &hours, int &minutes, int &seconds);

public:
	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);
	TimeSpan(double hours, double minutes, double seconds);
	~TimeSpan();

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	bool setTime(int hours, int minutes, int seconds);

	TimeSpan &TimeSpan::operator +(const TimeSpan &rightObj);
	TimeSpan &TimeSpan::operator -(const TimeSpan &rightObj);
	
	//Unary Negation
	TimeSpan operator-() const;

	bool TimeSpan::operator ==(const TimeSpan &rightObj);
	bool TimeSpan::operator !=(const TimeSpan &rightObj);

	TimeSpan &TimeSpan::operator +=(const TimeSpan &rightObj);
	TimeSpan &TimeSpan::operator -=(const TimeSpan &rightObj);



	// Overload ostream/istream operators
	friend ostream &operator <<(ostream &output, const TimeSpan &rightObj);
	friend istream &operator >>(istream &input, TimeSpan &rightObj);

};

