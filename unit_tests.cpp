//
// Created by jdiniso on 5/7/21.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch.hpp>
#include "median.hpp"

typedef std::vector<int> vec;

TEST_CASE("Calculating ordered medians", "[ordered]") {
	Median m;
	vec a = {2, 3, 4, 5, 6};
	REQUIRE(m.calc_median(a) == 4);
	vec b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	REQUIRE(m.calc_median(b) == 5.5f);
	vec c = {1, 2, 3};
	REQUIRE(m.calc_median(c) == 2);
	vec d = {1, 2, 3, 4};
	REQUIRE(m.calc_median(d) == 2.5f);
}

TEST_CASE("Calculating unordered medians", "[unordered]") {
	Median m;
	vec a = {5, 4, 3, 2, 1};
	REQUIRE(m.calc_median(a) == 3);
	vec b = {1, 3, 2, 5, 4};
	REQUIRE(m.calc_median(b) == 3);
	vec c = {1, 3, 5, 7, 2, 4, 6};
	REQUIRE(m.calc_median(c) == 4);
	vec d = {4, 3, 6};
	REQUIRE(m.calc_median(d) == 4);
	vec e = {4, 3, 6, 5};
	REQUIRE(m.calc_median(e) == 4.5f);
	vec f = {4, 3, 6, 7, 2, 35};
	REQUIRE(m.calc_median(f) == 5);
}

TEST_CASE("Larger medians", "[large]") {
	vec a;
	Median m;
	for (int i = 0; i < 100; i += 5) {
		a.push_back(i);
	}
	REQUIRE(m.calc_median(a) == 47.5f);
}