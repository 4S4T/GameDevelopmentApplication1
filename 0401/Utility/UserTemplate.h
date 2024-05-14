#pragma once

// â‘Î’l‹‚ß‚é
template <typename T>
T Abs(T value) {
	T result;

	if (value > 0) {
		result = value;
	}
	else {
		result = -value;
	}
	return result;
}

// Å‘å’l‹‚ß‚é
template <typename T>
T Max(T a, T b) {
	T result;

	if (a < b) {
		result = b;
	}
	else {
		result = a;
	}

	return result;
}

// Å¬’l‹‚ß‚é
template <typename T>
T Min(T a, T b) {

	T result;

	if (a > b) {
		result = b;
	}
	else {
		result = a;
	}

	return result;
}