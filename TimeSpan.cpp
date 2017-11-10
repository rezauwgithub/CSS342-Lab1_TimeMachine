// Reza Naeemi

#include "stdafx.h"
#include "TimeSpan.h"
#include "math.h"

TimeSpan::TimeSpan()
{
	setTime(0, 0, 0);
}

TimeSpan::TimeSpan(double seconds)
{
	setTime(0, 0, round(seconds));
}

void TimeSpan::handleDecimalsInMinutes(double &minutes, double &seconds)
{
	if (minutes > round(minutes))
	{
		int temp = minutes - round(minutes);
		seconds += 60 * temp;
		minutes -= temp;
	}
}

void TimeSpan::handleDecimalsInHours(double &hours, double &minutes)
{
	if (hours > round(hours))
	{
		int temp = hours - round(hours);
		minutes += 60 * temp;
		hours -= temp;
	}
}

void TimeSpan::handleNegativeMinutesOrSeconds(int &hours, int &minutes, int &seconds)
{
	if (seconds < 0)
	{
		seconds += 60;
		minutes--;
	}

	if (minutes < 0)
	{
		minutes += 60;
		hours--;
	}
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	handleDecimalsInMinutes(minutes, seconds);

	setTime(0, minutes, round(seconds));
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	handleDecimalsInHours(hours, minutes);
	handleDecimalsInMinutes(minutes, seconds);

	setTime(hours, minutes, seconds);
}

TimeSpan::~TimeSpan()
{
}

int TimeSpan::getHours() const
{
	return hours;
}

int TimeSpan::getMinutes() const
{
	return minutes;
}

int TimeSpan::getSeconds() const
{
	return seconds;
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
	if (seconds > 60 || seconds < -60)
	{
		minutes += (seconds / 60);
		seconds %= 60;
	}

	if (minutes > 60 || minutes < -60)
	{
		hours += (minutes / 60);
		minutes %= 60;
	}

	handleNegativeMinutesOrSeconds(hours, minutes, seconds);


	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;

	return true;
}


TimeSpan &TimeSpan::operator +(const TimeSpan &rightObj)
{
	TimeSpan result;

	result.setTime(
		hours + rightObj.getHours(),
		minutes + rightObj.getMinutes(),
		seconds + rightObj.getSeconds());

	return result;
}

TimeSpan &TimeSpan::operator -(const TimeSpan &rightObj)
{
	TimeSpan result;

	result.setTime(
		hours - rightObj.getHours(),
		minutes - rightObj.getMinutes(),
		seconds - rightObj.getSeconds());

	return result;
}


TimeSpan TimeSpan::operator-() const
{
	TimeSpan result;

	result.setTime(-hours, -minutes, -seconds);

	return result;
}


bool TimeSpan::operator ==(const TimeSpan &rightObj)
{
	return
		hours == rightObj.getHours() &&
		minutes == rightObj.getMinutes() &&
		seconds == rightObj.getSeconds();
}

bool TimeSpan::operator !=(const TimeSpan &rightObj)
{
	return !
		(hours == rightObj.getHours() &&
		minutes == rightObj.getMinutes() &&
		seconds == rightObj.getSeconds());

}

TimeSpan &TimeSpan::operator +=(const TimeSpan &rightObj)
{
	TimeSpan result;

	hours += rightObj.getHours();
	minutes += rightObj.getMinutes();
	seconds += rightObj.getSeconds();

	result.setTime(hours, minutes, seconds);

	return result;
}

TimeSpan &TimeSpan::operator -=(const TimeSpan &rightObj)
{
	TimeSpan result;

	hours -= rightObj.getHours();
	minutes -= rightObj.getMinutes();
	seconds -= rightObj.getSeconds();

	result.setTime(hours, minutes, seconds);

	return result;
}


ostream &operator <<(ostream &output, const TimeSpan &rightObj)
{
	output << "Hours: " << rightObj.getHours() << " "
		<< "Minutes: " << rightObj.getMinutes() << " "
		<< "Seconds: " << rightObj.getSeconds();

	return output;
}

istream &operator >>(istream &input, TimeSpan &rightObj)
{
	/*Take as input three values: hour, minutes, seconds 
	and create appropriate class. Assume that these will 
	be integers.

	I could also easily handle decimals (doubles), but I will assume integers
	are always used, per the instructions.
	*/
	int hours, minutes, seconds;

	input >> hours;
	input >> minutes;
	input >> seconds;

	rightObj.setTime(hours, minutes, seconds);

	return input;


}











