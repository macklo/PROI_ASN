#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include "asn_int.h"

TEST(testASN_int, GoodDataFromStream){
	asn_int x;
	std::stringstream ss;
	std::string str= "020101";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(3,y);
	EXPECT_EQ("", tmp);
}

TEST(testASN_int, ShortDataFromStream){
	asn_int x;
	std::stringstream ss;
	std::string str= "0201";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str, tmp);
}

TEST(testASN_int, WrongTagFromStream){
	asn_int x;
	std::stringstream ss;
	std::string str= "030101";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str,tmp);
}

TEST(testASN_int, TooBigDataStream){
	asn_int x;
	std::stringstream ss;
	std::string str= "03FF01";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str,tmp);
}