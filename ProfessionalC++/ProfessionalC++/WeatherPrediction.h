#pragma once
#pragma once

#include <string>

class WeatherPrediction
{
	public:
		virtual ~WeatherPrediction ();
		virtual void setCurrentTempFahrenheit (int inTemp);
		virtual void setPositionOfJupiter (int inDistanceFromMars);
		virtual int getTomorrowTempFahrenheit () const;
		virtual double getChanceOfRain () const;
		virtual void showResult () const;
		virtual std::string getTemperature () const;

	private:
		int mCurrentTempFahrenheit;
		int mDistanceFromMars;
};
