#pragma once
#define _USE_MATH_DEFINES 
#include <cmath>	 // for std::sqrt
#include <algorithm> // for std::max
#include <math.h>
#include "../MATHS AND ALGORITHMS/Maths.h"

namespace MathUtils
{

	static float toRad(float Deg)
	{
		float Rad = 0;
		Rad = Deg * M_PI / 180;

		return Rad;
	}
	static float toDeg(float Rad)
	{
		float Deg = 90;
		Deg = Rad * 180 / M_PI;

		return Deg;
	}

	static float Pythagoras(float A, float B)
	{
		float C = 0;
		C = pow(A, 2) + pow(B, 2);
		C = sqrt(C);

		return C;
	}


	// Calculates the sine of the angle opposite to the 'opposite' side
	// in a right triangle using the sine definition: sin(theta) = opposite / hypotenuse
	static float FindSinTheta(float opposite, float hypotenuse)
	{
		// Validate input to avoid division by zero or invalid triangle
		if (hypotenuse <= 0.0f || opposite < 0.0f || opposite > hypotenuse)
			return 0.0f;

		return opposite / hypotenuse;
	}


	// Calculates the cosine of the angle opposite to the 'opposite' side
	// in a right triangle using the adjacent and hypotenuse relationship.
	static float FindCosTheta(float opposite, float hypotenuse)
	{
		// Ensure the hypotenuse is greater than or equal to the opposite side
		if (hypotenuse <= 0.0f || opposite < 0.0f || opposite > hypotenuse)
			return 0.0f;

		// Calculate the adjacent side using the Pythagoras theorem
		float adjacent = std::sqrt(std::max(0.0f, hypotenuse * hypotenuse - opposite * opposite));

		// Return the cosine of the angle: adjacent / hypotenuse
		return adjacent / hypotenuse;
	}


	// Calculates the tangent of the angle opposite to the 'opposite' side
	// in a right triangle using the tangent definition: tan(theta) = opposite / adjacent
	static float FindTanTheta(float opposite, float hypotenuse)
	{
		// Validate input to ensure a valid right triangle
		if (hypotenuse <= 0.0f || opposite < 0.0f || opposite > hypotenuse)
			return 0.0f;

		// Calculate the adjacent side using the Pythagoras theorem
		float adjacent = std::sqrt(std::max(0.0f, hypotenuse * hypotenuse - opposite * opposite));

		// Return the tangent of the angle: opposite / adjacent
		return opposite / adjacent;
	}


	// Calculates the hypotenuse of a right triangle given an angle (in degrees)
	// and the length of the adjacent side using: hypotenuse = adjacent / cos(theta)
	static float FindHypotenuseFromDegrees(float angleDegrees, float adjacent)
	{
		float angleRadians = MathUtils::toRad(angleDegrees);	// convert to radians
		float cosTheta = std::cos(angleRadians);

		// Validate input: cosine of angle should not be zero to avoid division by zero
		if (cosTheta == 0.0f)
			return 0.0f;

		return adjacent / cosTheta;
	}


	// Calculates the opposite side length of a right triangle given an angle (in degrees)
	// and the length of the adjacent side using: hypotenuse = adjacent / cos(theta)
	static float FindOppositeFromDegrees(float angleDegrees, float hypotenuse)
	{

		// Validate input: cosine of angle should not be zero to avoid division by zero
		if (hypotenuse < 0.0f)
			return 0.0f;

		float angleRadians = MathUtils::toRad(angleDegrees);	// convert to radians
		float sinTheta = std::sin(angleRadians);
		return sinTheta * hypotenuse;
	}


	// Normalize the input angle so that it falls between 0 and 360 degrees
	static float NormalizeDegrees(float angleDegrees)
	{
		angleDegrees = std::fmod(angleDegrees, 360.0f);
		return (angleDegrees < 0.0f) ? angleDegrees + 360.0f : angleDegrees;
	}


	// calculate the length of the adjacent side using: adjacent = cos(theta) * hypotenuse
	static float FindAdjacentFromDegrees(float angleDegrees, float hypotenuse)
	{

		const float angleRadians = MathUtils::toRad(NormalizeDegrees(angleDegrees));	// convert to radians

		return std::cos(angleRadians) * hypotenuse;
	}

}