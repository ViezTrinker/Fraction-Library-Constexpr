#ifndef FRACTION_H
#define FRACTION_H

#include <array>
#include <numeric>
#include <stdexcept>
#include <string>
#include <type_traits>

template<typename T>
class Fraction
{
public:
	constexpr Fraction(const T numerator, const T denominator = 1) : _numerator(numerator), _denominator(denominator)
	{	
		if constexpr(std::is_signed<T>::value)
		{
			if (denominator < 0)
			{
				_numerator = -_numerator;
				_denominator = -_denominator;
			}
		}

		if (_numerator == 0)
		{
			_denominator = 1;
		}

		if (_denominator == 0)
		{
			throw std::invalid_argument("Denominator cannot be zero");
		}

		T greatestCommonDivisor = std::gcd(_numerator, _denominator);
		_numerator = _numerator / greatestCommonDivisor;
		_denominator = _denominator / greatestCommonDivisor;
	}

	constexpr Fraction operator+(const Fraction& other) const
	{
		T numerator = _numerator * other._denominator + _denominator * other._numerator;
		T denominator = _denominator * other._denominator;
		return Fraction{ numerator, denominator };
	}

	constexpr Fraction operator-(const Fraction& other) const
	{
		T numerator = _numerator * other._denominator - _denominator * other._numerator;
		T denominator = _denominator * other._denominator;
		return Fraction{ numerator, denominator };
	}

	constexpr Fraction operator*(const Fraction& other) const
	{
		T numerator = _numerator * other._numerator;
		T denominator = _denominator * other._denominator;
		return Fraction{ numerator, denominator };
	}

	constexpr Fraction operator/(const Fraction& other) const
	{
		T numerator = _numerator * other._denominator;
		T denominator = _denominator * other._numerator;
		return Fraction{ numerator, denominator };
	}

	constexpr bool operator==(const Fraction& other) const
	{
		return ((_numerator == other._numerator) && (_denominator == other._denominator));
	}

	constexpr bool operator!=(const Fraction& other) const
	{
		return !(*this == other);
	}

	constexpr bool operator>(const Fraction& other) const
	{
		return _numerator * other._denominator > other._numerator * _denominator;
	}

	constexpr bool operator>=(const Fraction& other) const
	{
		return _numerator * other._denominator >= other._numerator * _denominator;
	}

	constexpr bool operator<(const Fraction& other) const
	{
		return _numerator * other._denominator < other._numerator * _denominator;
	}

	constexpr bool operator<=(const Fraction& other) const
	{
		return _numerator * other._denominator <= other._numerator * _denominator;
	}

	constexpr Fraction& operator++(void)
	{
		_numerator += _denominator;
		return *this;
	}

	constexpr Fraction operator++(int32_t)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	constexpr Fraction& operator--(void)
	{
		_numerator -= _denominator;
		return *this;
	}

	constexpr Fraction operator--(int32_t)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}

	constexpr double ToDouble(void) const
	{
		return static_cast<double>(_numerator) / static_cast<double>(_denominator);
	}

	constexpr float ToFloat(void) const
	{
		return static_cast<float>(_numerator) / static_cast<float>(_denominator);
	}
	
	constexpr T GetNumerator(void) const
	{
		return _numerator;
	}

	constexpr T GetDenominator(void) const
	{
		return _denominator;
	}

private:
	T _numerator;
	T _denominator;
};

#endif // FRACTION_H