#pragma once
template<class T>
class Point
{
	T x;
	T y;
public:
	Point()
	{
		this->x = T{};
		this->y = T{};
	}
	Point(T y, T x)
	{
		this->x = x;
		this->y = y;
	}
	Point(const Point<T>& point)
	{
		this->x = point.getX();
		this->y = point.getY();
	}
	inline T getX() const
	{
		return x;
	}
	inline T getY() const
	{
		return y;
	}
	void setNewCoords(T newY, T newX)
	{
		x = newX;
		y = newY;
	}
	bool operator==(const Point<T>& point) const
	{
		return (x == point.x && y == point.y);
	}
	bool operator!=(const Point<T>& point) const
	{
		return !(*this == point);
	}
};

