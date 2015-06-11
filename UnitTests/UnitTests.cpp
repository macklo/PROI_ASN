// UnitTests.cpp : Defines the entry point for the console application.
//
#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "asn_object.h"
#include "asn_int.h"
//#include "asn_int.cpp"


TEST(testASN_int, simpletest){
	asn_int x;
	std::stringstream ss;
	std::string str= "0301";
	ss<<str;
	x.readAll(ss);
	//EXPECT_EQ(x.readAll(ss), -1);
	/*std::stringstream so;
	x.writeAll(so);*/
	EXPECT_EQ(ss.str(),str);
}


/*
TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}*/

int main(int argc, char** argv) 
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
}