#include "CppUnitTest.h"
#include "../MaxArrayLib/MaxArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MaxUnitTest
{
	TEST_CLASS(MaxUnitTest)
	{
	public:
		
		TEST_METHOD(odd_number_of_digits_in_numbers)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {110, 123}, {29315, 6789} } };
			Assert::AreEqual(max(tab, 2, 2), 29315);
		}
		TEST_METHOD(even_number_of_digits_in_numbers)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {11, 1650}, {23, 7000} } };
			Assert::AreEqual(max(tab, 2, 2), 1650);
		}
		TEST_METHOD(low_values)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {44, 15}, {23, 75} } };
			Assert::AreEqual(max(tab, 2, 2), 44);
		}
		TEST_METHOD(high_values)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {2234913, 1752311}, {121343745, 31294254} } };
			Assert::AreEqual(max(tab, 2, 2), 1752311);
		}
		TEST_METHOD(incorrect_numbers)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {123, 7}, {25, 757} } };
			Assert::AreEqual(max(tab, 2, 2), 0);
		}
		TEST_METHOD(one_number)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {7} } };
			Assert::AreEqual(max(tab, 1, 1), 0);
		}
		TEST_METHOD(empty_array)
		{
			std::array<std::array<int, maxColumns>, maxRows> tab = { { {} } };
			Assert::AreEqual(max(tab, 0, 0), 0);
		}
	};
}
