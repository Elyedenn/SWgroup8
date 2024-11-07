#pragma once
#include <cmath>

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;


struct Vector
{
	Vector() {}
	Vector(float x, float y) : x(x), y(y) { }
	Vector(POINT pt) : x((float)pt.x), y((float)pt.y) {}

	Vector operator+(const Vector& other)
	{
		Vector ret;
		ret.x = x + other.x;
		ret.y = y + other.y;

		return ret;
	}

	Vector operator-(const Vector& other)
	{
		Vector ret;
		ret.x = x - other.x;
		ret.y = y - other.y;

		return ret;
	}

	Vector operator*(float value)
	{
		Vector ret;
		ret.x = x * value;
		ret.y = y * value;

		return ret;
	}

	void operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const Vector& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*=(float value)
	{
		x *= value;
		y *= value;
	}

	void operator/=(float value)
	{
		x /= value;
		y /= value;
	}

	bool operator==(const Vector& other)
	{
		return x == other.x && y == other.y;
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	void Nomalize()
	{
		float length = Length();
		if (length < 0.000000000000001f)
			return;

		x /= length;
		y /= length;
	}

	float Dot(Vector other)
	{
		return x * other.x + y * other.y;
	}

	float Cross(Vector other)
	{
		return x * other.y - y * other.x;
	}


	float x = 0;
	float y = 0;
};

struct VectorInt
{
	VectorInt() {}
	VectorInt(int32 x, int32 y) : x(x), y(y) { }
	VectorInt(POINT pt) : x((int32)pt.x), y((int32)pt.y) {}

	VectorInt operator+(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x + other.x;
		ret.y = y + other.y;

		return ret;
	}

	VectorInt operator-(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x - other.x;
		ret.y = y - other.y;

		return ret;
	}

	VectorInt operator*(float value)
	{
		VectorInt ret;
		ret.x = x * value;
		ret.y = y * value;

		return ret;
	}

	void operator+=(const VectorInt& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-=(const VectorInt& other)
	{
		x -= other.x;
		y -= other.y;
	}

	bool operator<(const VectorInt& other) const // const 가 꼭 필요하다.
	{
		if (x != other.x)
			return x < other.x;

		return y < other.y;
	}

	bool operator>(const VectorInt& other) const // const 가 꼭 필요하다.
	{
		if (x != other.x)
			return x > other.x;

		return y > other.y;
	}

	bool operator==(const VectorInt& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const VectorInt& other)
	{
		return !(*this == other);
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return (float)::sqrt(LengthSquared());
	}

	float Dot(VectorInt other)
	{
		return x * other.x + y * other.y;
	}

	float Cross(VectorInt other)
	{
		return x * other.y - y * other.x;
	}


	int32 x = 0;
	int32 y = 0;
};

using Pos = Vector;