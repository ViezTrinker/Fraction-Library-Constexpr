#include "fraction.h"

#include <cstdint>

using FractionU32 = Fraction<uint32_t>;
using FractionS32 = Fraction<int32_t>;

constexpr FractionU32 OneFourth{ 1, 4 };
static_assert(OneFourth.GetNumerator() == 1);
static_assert(OneFourth.GetDenominator() == 4);

constexpr FractionU32 ZeroHalf{ 0, 2 };
static_assert(ZeroHalf.GetNumerator() == 0);
static_assert(ZeroHalf.GetDenominator() == 1);

constexpr FractionU32 SixTenth{ 6, 10 };
static_assert(SixTenth.GetNumerator() == 3);
static_assert(SixTenth.GetDenominator() == 5);

constexpr FractionU32 Nine{ 9 };
static_assert(Nine.GetNumerator() == 9);
static_assert(Nine.GetDenominator() == 1);

constexpr FractionS32 MinusThreeHalf{ -3 , 2 };
static_assert(MinusThreeHalf.GetNumerator() == -3);
static_assert(MinusThreeHalf.GetDenominator() == 2);

constexpr FractionS32 ThreeHalfMinus{ 3 , -2 };
static_assert(ThreeHalfMinus.GetNumerator() == -3);
static_assert(ThreeHalfMinus.GetDenominator() == 2);

constexpr FractionS32 MinusThreeHalfMinus{ -3 , -2 };
static_assert(MinusThreeHalfMinus.GetNumerator() == 3);
static_assert(MinusThreeHalfMinus.GetDenominator() == 2);

constexpr FractionU32 OneThird{ 1, 3 };
constexpr FractionU32 SevenNineth{ 7, 9 };
constexpr FractionU32 Result = OneThird + SevenNineth;
static_assert(Result.GetNumerator() == 10);
static_assert(Result.GetDenominator() == 9);

constexpr FractionS32 OneMinusThird{ 1, -3 };
constexpr FractionS32 SevenSixth{ 7, 6 };
constexpr FractionS32 Result2 = OneMinusThird + SevenSixth;
static_assert(Result2.GetNumerator() == 5);
static_assert(Result2.GetDenominator() == 6);

constexpr FractionU32 OneFifth{ 1, 5 };
constexpr FractionU32 OneEleventh{ 1, 11 };
constexpr FractionU32 Result3 = OneFifth - OneEleventh;
static_assert(Result3.GetNumerator() == 6);
static_assert(Result3.GetDenominator() == 55);

constexpr FractionS32 Frac1{ 3, 33 };
constexpr FractionS32 Frac2{ 8, -23 };
constexpr FractionS32 Result4 = Frac1 * Frac2;
static_assert(Result4.GetNumerator() == -8);
static_assert(Result4.GetDenominator() == 253);

constexpr FractionS32 Frac3{ 44, 12 };
constexpr FractionS32 Frac4{ -3, 100 };
constexpr FractionS32 Result5 = Frac3 / Frac4;
static_assert(Result5.GetNumerator() == -1100);
static_assert(Result5.GetDenominator() == 9);

constexpr FractionS32 Frac5{ -1, -9 };
constexpr FractionS32 Frac6{ 11, 99 };
static_assert(Frac5 == Frac6);
static_assert(Frac5 >= Frac6);
static_assert(Frac5 <= Frac6);

constexpr FractionS32 Frac7{ -1, -9 };
constexpr FractionS32 Frac8{ 11, 100 };
static_assert(Frac7 != Frac8);

constexpr FractionU32 Frac9{ 12, 5 };
constexpr FractionU32 Frac10{ 50, 2 };
static_assert(Frac10 > Frac9);
static_assert(Frac10 >= Frac9);

constexpr FractionU32 Frac11{ 1, 99 };
constexpr FractionU32 Frac12{ 8, 13 };
static_assert(Frac11 < Frac12);
static_assert(Frac11 <= Frac12);

constexpr FractionS32 Frac13{ -3, 10 };
static_assert(Frac13.ToDouble() == -0.3);
static_assert(Frac13.ToFloat() == -0.3f);

constexpr FractionU32 Frac14{ 1, 101 };
constexpr FractionU32 Frac15 = Frac14;
static_assert(Frac14 == Frac15);