#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <array>
#include <numeric>
#include <string>
#include <vector>

SCENARIO("All ten frames are missed") {
    GIVEN("Game result are -|-|-|-|-|-|-|-|-|-|") {
        std::string result = "-|-|-|-|-|-|-|-|-|-|";
        
        WHEN("points are counted") {
            int point = 0;

            THEN("Expected result is 0") {
                int expected = 0;
                REQUIRE(point == expected);
            }
        }
    }
}

SCENARIO("Frames without bonus points") {
    GIVEN("Game result from single frame are 1 - 9") {
        auto v = GENERATE(std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 1},
                          std::vector{3, 3, 4, 5, 6, 7, 2, 1, 4, 6},
                          std::vector{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          std::vector{9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
                          std::vector{5, 6, 3, 5, 7, 8, 9, 3, 2, 6});

            WHEN("Points are counted") {
                std::array<int, 5> results{0, 0, 0, 0, 0};                                  #PRZEMYSL TO 
                std::reduce(v.begin(), v.end(), 0);

                THEN("Expected results are 46, 41, 10, 90, 54") {
                    std::array<int, 5> expected {45, 41, 10, 90, 54};
                    REQUIRE(results == expected);
                }
            }
    }
}

SCENARIO("Perfect game") {
    GIVEN("Game results are X|X|X|X|X|X|X|X|X|X|XX") {

        WHEN("Points are calculated") {
            std::string points = "X|X|X|X|X|X|X|X|X|X|XX";

            THEN("Expected result is 300") {
                int expected = 300;
                REQUIRE("result == expected");
            }
        }
    }
}

SCENARIO("Spare in every frame") {
    GIVEN("Result from a single frame in 1-9/") {
        auto s = GENERATE(std::string{1/|1/|1/|1/|1/|1/|1/|1/|1/|1/|1},
                          std::string{9/|9/|9/|9/|9/|9/|9/|9/|9/|9/|9},
                          std::string{5/|5/|5/|5/|5/|5/|5/|5/|5/|5/|5},
                          std::string{1/|2/|3/|4/|5/|6/|7/|8/|9/|1/|2});

        WHEN("Points are calculated") {

            THEN("Expected results are") {
                REQUIRE(0 == 1);
            }
        }
    }
}

SCENARIO("Strike in the 10th frame") {
    GIVEN("Result from extra balls -, 1-9, X") {
        auto s = GENERATE(std::string{1|1|1|1|1|1|1|1|1|X|--},
                          std::string{1|1|1|1|1|1|1|1|1|X|-3},
                          std::string{1|1|1|1|1|1|1|1|1|X|X-},
                          std::string{1|1|1|1|1|1|1|1|1|X|XX},
                          std::string{1|1|1|1|1|1|1|1|1|X|5X});
        
        WHEN("results are calculated") {

            THEN("Expected results are") {
                REQUIRE(1 == 2);
            }
        }

    }
}

SCENARIO("Spare in the 10th frame") {
    GIVEN("Result from extra balls -, 1-9, X") {
        auto s = GENERATE(std::string{1|1|1|1|1|1|1|1|1|X|-},
                          std::string{1|1|1|1|1|1|1|1|1|X|3},
                          std::string{1|1|1|1|1|1|1|1|1|X|X},
                          std::string{1|1|1|1|1|1|1|1|1|X|7},
                          std::string{1|1|1|1|1|1|1|1|1|X|5});
        
        WHEN("results are calculated") {

            THEN("Expected results are") {
                REQUIRE(1 == 2);
            }
        }

    }
}

SCENARIO("Strike mixed with bonusfree balls") {
     GIVEN("Result from extra balls -, 1-9, X") {
        auto s = GENERATE(std::string{X|-|1|X|-|-|1|1|1|1|},
                          std::string{1|1|1|1|1|1|1|1|1|X|3},
                          std::string{1|1|1|1|1|1|1|1|1|X|X},
                          std::string{1|1|1|1|1|1|1|1|1|X|7},
                          std::string{1|1|1|1|1|1|1|1|1|X|5});
        
        WHEN("results are calculated") {

            THEN("Expected results are") {
                REQUIRE(1 == 2);
            }
        }
    }
}