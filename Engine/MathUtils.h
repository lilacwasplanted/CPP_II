#pragma once
#include <cmath>
using namespace std;

namespace Math
{

	constexpr float Pi = 3.141592653589793f; // 180
	constexpr float twoPi = 6.283185307179586f; // 360
	constexpr float halfPi = 1.5707963267948966; // 90

	float RadToDeg(float radians) { return radians * (180.0f / Pi); }
	float DegToRad(float degrees) { return degrees * (Pi / 180.0f); }



	float Sin(float radians) {
		return sinf(radians);

	}

	float Cos(float radians) {
		return cosf(radians);

	}
	/// <summary>
	/// Returns the Maximum Value of a and b
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a">value</param>
	/// <param name="b">value</param>
	/// <returns> The maximum value between a and b. </returns>
	template<typename T>
	T Max(T a, T b) {
		if (a > b) ? a : b;
		// ? = if : = else
	}
	template<typename T>
	T Min(T a, T b) {
		if (a < b) ? a : b;
		// ? = if : = else
	}

	template <typename T>
	T Abs(T value) {
		return (value < 0) ? -value : value;
	}

};
