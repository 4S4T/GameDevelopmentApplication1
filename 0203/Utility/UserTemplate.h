#pragma once

//絶対値求める
template <typename T>
T Abs(T value)
{
	T result;

	if (value > 0)
	{
		result = value;
	}
	else
	{
		result = -value;
	}
	return result;
}

//最大値求める
template <typename T>
T Max(T a, T b)
{
	T result;

	if (a < b)
	{
		result = b;
	}
	else
	{
		result = a;
	}

	return result;
}

//最小値求める
template <typename T>
T Min(T a,T b) 
{

	T result;

	if (a > b)
	{
		result = b;
	}
	else
	{
		result = a;
	}

	return result;
}