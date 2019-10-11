#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <func.hpp>

TEST_CASE("func") {
    CHECK(func(0,0) == 0);
	CHECK(func(1,0) == 1);
	CHECK(func(0,1) == 1);
	CHECK(func(1,1) == 2);
	CHECK(func(1,2) == 3);
	CHECK(func(2,3) == 5);
	CHECK(func(3,2) == 5);
	CHECK(func(3,3) != 5);
	CHECK(func(1,-1) == 0);
	CHECK(func(-1,-1) == -2);
}