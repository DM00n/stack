// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header1.hpp>
#include <header2.hpp>

class for_test2{
public:
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
unsigned a = 516;

stack1<unsigned> mystk;
mystk.push(a);
mystk.push(2314);

EXPECT_EQ(mystk.head(), 2314);
mystk.pop();
EXPECT_EQ(mystk.head(), 516);
}

TEST(task1, EmptyTest) {
stack2<for_test2> mytest;
mytest.push(for_test2(3, 4));
mytest.push_emplace(3, 4, 7);
EXPECT_EQ(mytest.head().volume, 84);
mytest.pop();
EXPECT_EQ(mytest.head().square, 12);
}
