#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "asn_string.h"


TEST(testASN_string, DeafultCostructorTest){
	asn_string x;
	EXPECT_EQ("", x.getString());
}

TEST(testASN_string, CostructorTest){
	std::string str = "TestowyString";
	asn_string x(str);
	EXPECT_EQ(str, x.getString());
}

TEST(testASN_string, getSizeTest){
	std::string str = "TestowyString";
	asn_string x(str);
	EXPECT_EQ(str.size(), x.getSize());
}

TEST(testASN_string, GoodDataFromStream){
	asn_string x;
	std::stringstream ss;
	std::string str= "13044B756261";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(6,y);
	EXPECT_EQ("", tmp);
}

TEST(testASN_string, ShortDataFromStream){
	asn_string x;
	std::stringstream ss;
	std::string str= "1304";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str, tmp);
}

TEST(testASN_string, WrongTagFromStream){
	asn_string x;
	std::stringstream ss;
	std::string str= "14044B756261";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str,tmp);
}
