
#include "Vec3.h"

namespace Esm {

	Vec3::Vec3() 
		:x(0.0f), y(0.0f), z(0.0f) {}

	Vec3::Vec3(float xc, float yc, float zc) 
		: x(xc), y(yc), z(zc) {}

	Vec3::Vec3(const Vec3& u) 
		: x(u.x), y(u.y), z(u.z) {}

	Vec3& Vec3::operator=(const Vec3 &u)
	{
		this->x = u.x;
		this->y = u.y;
		this->z = u.z;

		return *this;
	}

	Vec3& Vec3::operator+=(const Vec3 &u)
	{
		x += u.x;
		y += u.y;
		z += u.z;

		return *this;
	}

	Vec3& Vec3::operator-=(const Vec3 &u)
	{
		x -= u.x;
		y -= u.y;
		z -= u.z;

		return *this;
	}

	Vec3& Vec3::operator*=(const Vec3& u)
	{
		x *= u.x;
		y *= u.y;
		z *= u.z;

		return *this;
	}

	Vec3 Vec3::operator*(const float& Scale)
	{
		return Vec3(x*Scale, y*Scale, z*Scale);
	}

	Vec3& Vec3::operator*=(const float& Scale)
	{
		x += Scale;
		y += Scale;
		z += Scale;

		return *this;
	}

	Vec3& Vec3::operator/=(const float& Scale)
	{
		x /= Scale;
		y /= Scale;
		z /= Scale;

		return *this;
	}

	Vec3 Vec3::operator+(const Vec3 &u)
	{
		return Vec3(x + u.x, y + u.y, z + u.z);
	}

	Vec3 Vec3::operator-(const Vec3 &u)
	{
		return Vec3(x - u.x, y - u.y, z - u.z);
	}

	Vec3 Vec3::operator*(const Vec3 &u)
	{
		return Vec3(x*u.x, y*u.y, z*u.z);
	}

	Vec3 Vec3::operator/(const float& Scale)
	{
		return Vec3(x / Scale, y / Scale, z / Scale);
	}

	Vec3 Vec3::operator-()
	{
		return Vec3(-x, -y, -z);
	}

	void Vec3::Normalize()
	{
		float mag = x * x + y * y + z * z;
		if (mag == 0.0f)
			return;

		else if (mag > 0.0f)
		{
			this->x *= 1.0f / sqrt(mag);
			this->y *= 1.0f / sqrt(mag);
			this->z *= 1.0f / sqrt(mag);
		}

		else
		{
			std::cout << "Invalid Magnitude" << std::endl; assert(false);
		}
	}

	bool Vec3::operator==(Vec3& u)
	{
		return (x == u.x && y == u.y && z == u.z);
	}

	bool Vec3::operator!=(Vec3& u)
	{
		return (x != u.x || y != u.y || z != u.z);
	}

    Vec3 CrossProduct(const Vec3& lhs, const Vec3& rhs)
	{
		 
		return Vec3
		(
			lhs.y*rhs.z - lhs.z*rhs.y,
			lhs.z*rhs.x - lhs.x*rhs.z,
			lhs.x*rhs.y - lhs.y*rhs.x
		);
		
    }

    Vec3 Scale(const float Scaler, const Vec3& rhs)
	{
	
		return Vec3(Scaler*rhs.x, Scaler*rhs.y, Scaler*rhs.z);
	
	}

    float Distance(const Vec3& lhs, const Vec3& rhs)
	{
		return
			(   sqrt(
			            ( (lhs.x - rhs.x)*(lhs.x - rhs.x) ) + 
			            ( (lhs.y - rhs.y)*(lhs.y - rhs.y) ) + 
				        ( (lhs.z - rhs.z)*(lhs.z - rhs.z) )
			        )
			);
	}

}
