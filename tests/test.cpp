// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header1.hpp>
#include <header2.hpp>
#include <string>
class for_test2{
public:
    for_test2(){
        square = 0;
        volume = 0;
    }
    for_test2(double a, double b, double c){
        square = a * b;
        volume = a * b * c;
    }
    for_test2(double a, double b){
        square = a * b;
        volume = 0;
    }
    double square;
    double volume;
};

TEST(task1, EmptyTest) {
std::string a = "privetstvuyu";

stack1<unsigned> mystk;
mystk.push(a);
mystk.push("2314");

EXPECT_EQ(mystk.head(), "2314");
mystk.pop();
EXPECT_EQ(mystk.head(), "privetstvuyu");

EXPECT_EQ(std::is_move_constructible<stack1<double>>::value, true);
EXPECT_EQ(std::is_move_assignable<stack1<double>>::value, true);
}

TEST(task2, EmptyTest) {
stack2<for_test2> mytest;
double a = 3, b = 4;
mytest.push(for_test2(a, b));
mytest.push_emplace(3, 4, 7);
EXPECT_EQ(mytest.head().volume, 84);
mytest.pop();
EXPECT_EQ(mytest.head().square, 12);

EXPECT_EQ(std::is_move_constructible<stack2<double>>::value, true);
EXPECT_EQ(std::is_move_assignable<stack2<double>>::value, true);
}
