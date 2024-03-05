#include "utest.h"
#include <iostream>

namespace ft {

void UTest::run()const
{
	_run();
}


void UTest::_run() const
{
	std::cout << "Running " << m_name << "..." << std::endl;
	m_f();
	std::cout << "Done." << std::endl;
}

std::vector<UTest> & UTests::tests()
{
	static std::vector<UTest> all_tests;
	return all_tests;
}

DECLSPEC int UTests::runAll()
{
	auto& testsCpy = tests();
	bool failed = false;
	for(auto const & test: testsCpy)
	{
		try {
			test.run();
		} catch (std::exception const & e) {
			std::cerr << "Test " << test.m_name<< " failed: " << e.what() << std::endl;
			failed += true;
		}
	}
	return failed;
}

};