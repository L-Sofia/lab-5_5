#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1depth/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			t = Bin(2, 5);
			Assert::AreEqual(t, 10);
		}
	};
}
