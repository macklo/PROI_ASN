#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "asn_string.h"


TEST(tetsASN_string, GoodDataFromStream){
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

TEST(tetsASN_string, ShortDataFromStream){
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

TEST(tetsASN_string, WrongTagFromStream){
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
