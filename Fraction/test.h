#ifndef TEST_H
#define TEST_H

#include "fraction.h"

#include <cstdint>

using FractionU32 = Fraction<uint32_t>;
using FractionS32 = Fraction<int32_t>;

inline constexpr FractionU32 OneFourth{ 1, 4 };
static_assert(OneFourth.GetNumerator() == 1);
static_assert(OneFourth.GetDenominator() == 4);

inline constexpr FractionU32 ZeroHalf{ 0, 2 };
static_assert(ZeroHalf.GetNumerator() == 0);
static_assert(ZeroHalf.GetDenominator() == 1);

inline constexpr FractionU32 SixTenth{ 6, 10 };
static_assert(SixTenth.GetNumerator() == 3);
static_assert(SixTenth.GetDenominator() == 5);

inline constexpr FractionU32 Nine{ 9 };
static_assert(Nine.GetNumerator() == 9);
static_assert(Nine.GetDenominator() == 1);

inline constexpr FractionS32 MinusThreeHalf{ -3 , 2 };
static_assert(MinusThreeHalf.GetNumerator() == -3);
static_assert(MinusThreeHalf.GetDenominator() == 2);

inline constexpr FractionS32 ThreeHalfMinus{ 3 , -2 };
static_assert(ThreeHalfMinus.GetNumerator() == -3);
static_assert(ThreeHalfMinus.GetDenominator() == 2);

inline constexpr FractionS32 MinusThreeHalfMinus{ -3 , -2 };
static_assert(MinusThreeHalfMinus.GetNumerator() == 3);
static_assert(MinusThreeHalfMinus.GetDenominator() == 2);

inline constexpr FractionU32 OneThird{ 1, 3 };
inline constexpr FractionU32 SevenNineth{ 7, 9 };
inline constexpr FractionU32 Result = OneThird + SevenNineth;
static_assert(Result.GetNumerator() == 10);
static_assert(Result.GetDenominator() == 9);

inline constexpr FractionS32 OneMinusThird{ 1, -3 };
inline constexpr FractionS32 SevenSixth{ 7, 6 };
inline constexpr FractionS32 Result2 = OneMinusThird + SevenSixth;
static_assert(Result2.GetNumerator() == 5);
static_assert(Result2.GetDenominator() == 6);

inline constexpr FractionU32 OneFifth{ 1, 5 };
inline constexpr FractionU32 OneEleventh{ 1, 11 };
inline constexpr FractionU32 Result3 = OneFifth - OneEleventh;
static_assert(Result3.GetNumerator() == 6);
static_assert(Result3.GetDenominator() == 55);

inline constexpr FractionS32 Frac1{ 3, 33 };
inline constexpr FractionS32 Frac2{ 8, -23 };
inline constexpr FractionS32 Result4 = Frac1 * Frac2;
static_assert(Result4.GetNumerator() == -8);
static_assert(Result4.GetDenominator() == 253);

inline constexpr FractionS32 Frac3{ 44, 12 };
inline constexpr FractionS32 Frac4{ -3, 100 };
inline constexpr FractionS32 Result5 = Frac3 / Frac4;
static_assert(Result5.GetNumerator() == -1100);
static_assert(Result5.GetDenominator() == 9);

inline constexpr FractionS32 Frac5{ -1, -9 };
inline constexpr FractionS32 Frac6{ 11, 99 };
static_assert(Frac5 == Frac6);
static_assert(Frac5 >= Frac6);
static_assert(Frac5 <= Frac6);

inline constexpr FractionS32 Frac7{ -1, -9 };
inline constexpr FractionS32 Frac8{ 11, 100 };
static_assert(Frac7 != Frac8);

inline constexpr FractionU32 Frac9{ 12, 5 };
inline constexpr FractionU32 Frac10{ 50, 2 };
static_assert(Frac10 > Frac9);
static_assert(Frac10 >= Frac9);

inline constexpr FractionU32 Frac11{ 1, 99 };
inline constexpr FractionU32 Frac12{ 8, 13 };
static_assert(Frac11 < Frac12);
static_assert(Frac11 <= Frac12);

inline constexpr FractionS32 Frac13{ -3, 10 };
static_assert(Frac13.ToDouble() == -0.3);
static_assert(Frac13.ToFloat() == -0.3f);

inline constexpr FractionS32 Frac14{ 1, 101 };
inline constexpr FractionS32 Frac15 = Frac14;
static_assert(Frac14 == Frac15);

inline void RuntimeTests(void)
{
	Fraction frac1{ 4,5 };
	Fraction frac2{ 9,5 };
	frac1++;

	if (frac1 != frac2)
	{
		throw std::runtime_error("Test 1 Fail");
	}


	/////////////////////////////////////////////////////////

	Fraction frac3{ 1,4 };
	Fraction frac4{ -3,4 };
	frac3--;

	if (frac3 != frac4)
	{
		throw std::runtime_error("Test 2 Fail");
	}

	constexpr Fraction frac5{ -3, 45 };
	if (frac5.ToString() != "-1/15")
	{
		throw std::runtime_error("Test 3 Fail");
	}

	constexpr Fraction frac6{ 0, 7 };
	if (frac6.ToString() != "0/1")
	{
		throw std::runtime_error("Test 4 Fail");
	}
}

#endif // TEST_H