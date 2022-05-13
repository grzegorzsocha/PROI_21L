#include "CppUnitTest.h"
#include "../QueueLib/QueueLib.cpp"
#include "../Stack/Stack.cpp"
#include "../Person/Person.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(constructor_without_N)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.getQuantity());
			Assert::AreEqual(10, q.getCapacity());
		}
		TEST_METHOD(constructor_with_N)
		{
			Queue<Person, 4> q;
			Assert::AreEqual(0, q.getQuantity());
			Assert::AreEqual(4, q.getCapacity());
		}
		TEST_METHOD(get_quantity_zero)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.getQuantity());
		}
		TEST_METHOD(get_quantity)
		{
			Queue<int> q;
			q.addBegin(7);
			q.addBegin(1532);
			Assert::AreEqual(2, q.getQuantity());
		}
		TEST_METHOD(get_capacity)
		{
			Queue<int, 1342> q;
			Assert::AreEqual(1342, q.getCapacity());
		}
		TEST_METHOD(get_begin_exception)
		{
			Queue<int> q;
			Assert::ExpectException<std::invalid_argument>([&q] {q.getBegin(); });
		}
		TEST_METHOD(get_begin_int)
		{
			Queue<int> q;
			q.addBegin(27);
			q.addEnd(13);
			q.addBegin(55);
			q.addEnd(74);
			Assert::AreEqual(55, q.getBegin());
		}
		TEST_METHOD(get_begin_person)
		{
			Queue<Person> q;
			Person maciek("maciek"), jacek("jacek");
			q.addBegin(maciek);
			q.addBegin(jacek);
			Assert::IsTrue(jacek == q.getBegin());
		}
		TEST_METHOD(get_begin_string)
		{
			Queue<std::string> q;
			std::string a = "abc", b = "def", c="ghi";
			q.addBegin(a);
			q.addEnd(c);
			q.addBegin(b);
			Assert::IsTrue(b == q.getBegin());
		}
		TEST_METHOD(get_end_exception)
		{
			Queue<int> q;
			Assert::ExpectException<std::invalid_argument>([&q] {q.getEnd(); });
		}
		TEST_METHOD(get_end_int)
		{
			Queue<int> q;
			q.addBegin(27);
			q.addEnd(13);
			q.addBegin(55);
			q.addEnd(74);
			Assert::AreEqual(74, q.getEnd());
		}
		TEST_METHOD(get_end_person)
		{
			Queue<Person> q;
			Person maciek("maciek"), jacek("jacek");
			q.addBegin(maciek);
			q.addBegin(jacek);
			Assert::IsTrue(maciek == q.getEnd());
		}
		TEST_METHOD(get_end_string)
		{
			Queue<std::string> q;
			std::string a = "abc", b = "def", c = "ghi";
			q.addBegin(a);
			q.addEnd(c);
			q.addBegin(b);
			Assert::IsTrue(c == q.getEnd());
		}
		TEST_METHOD(get_tab)
		{
			Queue<int> q;
			q.addBegin(27);
			q.addEnd(13);
			q.addBegin(55);
			q.addEnd(74);
			auto a = q.getTab();
			Assert::AreEqual(55, a[0]);
			Assert::AreEqual(27, a[1]);
			Assert::AreEqual(13, a[2]);
			Assert::AreEqual(74, a[3]);
		}
		TEST_METHOD(add_begin_int)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.getQuantity());
			q.addBegin(27);
			q.addBegin(13);
			q.addBegin(55);
			q.addBegin(74);
			Assert::AreEqual(4, q.getQuantity());
			Assert::AreEqual(74, q.getBegin());
		}
		TEST_METHOD(add_begin_person)
		{
			Queue<Person> q;
			Person maciek("maciek"), jacek("jacek");
			Assert::AreEqual(0, q.getQuantity());
			q.addBegin(maciek);
			q.addBegin(jacek);
			Assert::AreEqual(2, q.getQuantity());
			Assert::IsTrue(jacek == q.getBegin());
		}
		TEST_METHOD(add_begin_string)
		{
			Queue<std::string> q;
			std::string a = "abc", b = "def", c = "ghi";
			Assert::AreEqual(0, q.getQuantity());
			q.addBegin(a);
			q.addBegin(c);
			q.addBegin(b);
			Assert::AreEqual(3, q.getQuantity());
			Assert::IsTrue(b == q.getBegin());
		}
		TEST_METHOD(add_end_int)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.getQuantity());
			q.addEnd(27);
			q.addEnd(13);
			q.addEnd(55);
			q.addEnd(74);
			Assert::AreEqual(4, q.getQuantity());
			Assert::AreEqual(74, q.getEnd());
		}
		TEST_METHOD(add_end_person)
		{
			Queue<Person> q;
			Person maciek("maciek"), jacek("jacek");
			Assert::AreEqual(0, q.getQuantity());
			q.addEnd(maciek);
			q.addEnd(jacek);
			Assert::AreEqual(2, q.getQuantity());
			Assert::IsTrue(jacek == q.getEnd());
		}
		TEST_METHOD(add_end_string)
		{
			Queue<std::string> q;
			std::string a = "abc", b = "def", c = "ghi";
			Assert::AreEqual(0, q.getQuantity());
			q.addEnd(a);
			q.addEnd(c);
			q.addEnd(b);
			Assert::AreEqual(3, q.getQuantity());
			Assert::IsTrue(b == q.getEnd());
		}
		TEST_METHOD(delete_begin_empty)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.getQuantity());
			q.deleteBegin();
			Assert::AreEqual(0, q.getQuantity());
		}
		TEST_METHOD(delete_begin_int)
		{
			Queue<int> q;
			q.addBegin(27);
			q.addBegin(13);
			q.addBegin(55);
			q.addBegin(74);
			Assert::AreEqual(4, q.getQuantity());
			Assert::AreEqual(74, q.getBegin());
			q.deleteBegin();
			Assert::AreEqual(3, q.getQuantity());
			Assert::AreEqual(55, q.getBegin());
		}
		TEST_METHOD(delete_begin_person)
		{
			Queue<Person> q;
			Person maciek("maciek"), jacek("jacek");
			q.addBegin(maciek);
			q.addBegin(jacek);
			Assert::AreEqual(2, q.getQuantity());
			Assert::IsTrue(jacek == q.getBegin());
			q.deleteBegin();
			Assert::AreEqual(1, q.getQuantity());
			Assert::IsTrue(maciek == q.getBegin());
		}
		TEST_METHOD(delete_begin_string)
		{
			Queue<std::string> q;
			std::string a = "abc", b = "def", c = "ghi";
			q.addBegin(a);
			q.addBegin(c);
			q.addBegin(b);
			Assert::AreEqual(3, q.getQuantity());
			Assert::IsTrue(b == q.getBegin());
			q.deleteBegin();
			Assert::AreEqual(2, q.getQuantity());
			Assert::AreEqual(c, q.getBegin());
		}
		TEST_METHOD(delete_end_empty)
		{
			Queue<int> q;
			Assert::AreEqual(0, q.getQuantity());
			q.deleteEnd();
			Assert::AreEqual(0, q.getQuantity());
		}
		TEST_METHOD(delete_end_int)
		{
			Queue<int> q;
			q.addEnd(27);
			q.addEnd(13);
			q.addEnd(55);
			q.addEnd(74);
			Assert::AreEqual(4, q.getQuantity());
			Assert::AreEqual(74, q.getEnd());
			q.deleteEnd();
			Assert::AreEqual(3, q.getQuantity());
			Assert::AreEqual(55, q.getEnd());
		}
		TEST_METHOD(delete_end_person)
		{
			Queue<Person> q;
			Person maciek("maciek"), jacek("jacek");
			q.addEnd(maciek);
			q.addEnd(jacek);
			Assert::AreEqual(2, q.getQuantity());
			Assert::IsTrue(jacek == q.getEnd());
			q.deleteEnd();
			Assert::AreEqual(1, q.getQuantity());
			Assert::IsTrue(maciek == q.getEnd());
		}
		TEST_METHOD(delete_end_string)
		{
			Queue<std::string> q;
			std::string a = "abc", b = "def", c = "ghi";
			q.addEnd(a);
			q.addEnd(c);
			q.addEnd(b);
			Assert::AreEqual(3, q.getQuantity());
			Assert::IsTrue(b == q.getEnd());
			q.deleteEnd();
			Assert::AreEqual(2, q.getQuantity());
			Assert::AreEqual(c, q.getEnd());
		}
		TEST_METHOD(clear)
		{
			Queue<int> q;
			q.addEnd(27);
			q.addEnd(13);
			q.addEnd(55);
			q.addEnd(74);
			Assert::AreEqual(4, q.getQuantity());
			q.clear();
			Assert::AreEqual(0, q.getQuantity());
		}
		TEST_METHOD(reverse_int)
		{
			Stack<int> s;
			s.addEnd(1);
			s.addEnd(2);
			s.addEnd(3);
			s.addEnd(4);
			s.reverse();
			auto t = s.getTab();
			for (int i = 1; i <= 4; i++)
			{
				Assert::AreEqual(i, t[4-i]);
			}
		}
		TEST_METHOD(reverse_person)
		{
			Stack<Person> s;
			Person maciek("maciek"), jacek("jacek");
			s.addEnd(maciek);
			s.addEnd(jacek);
			s.reverse();
			auto t = s.getTab();
			Assert::IsTrue(jacek == t[0]);
			Assert::IsTrue(maciek == t[1]);
		}
		TEST_METHOD(reverse_string)
		{
			Stack<std::string> s;
			std::string a = "abc", b = "def", c = "ghi";
			s.addEnd(a);
			s.addEnd(b);
			s.addEnd(c);
			s.reverse();
			auto t = s.getTab();
			Assert::AreEqual(c, t[0]);
			Assert::AreEqual(b, t[1]);
			Assert::AreEqual(a, t[2]);
		}
	};
}
