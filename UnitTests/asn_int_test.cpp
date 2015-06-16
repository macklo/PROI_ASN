#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include "asn_int.h"

TEST(testASN_int, CostructorTest){
	int val = 5;
	asn_int x(5);
	EXPECT_EQ(val,x.getValue());
}

TEST(testASN_int, DefaultCostructorTest){
	asn_int x;
	EXPECT_EQ(-1,x.getValue());
}

TEST(testASN_int, SetValueTest){
	int val = 9;
	asn_int x;
	x.setValue(val);
	EXPECT_EQ(val,x.getValue());
}

TEST(testASN_int, InvertTest){
	int val = 5;
	asn_int x(5);
	EXPECT_EQ((1/val),x.invert());
}

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

TEST(testASN_int, WriteTest){
	asn_int x;
	std::stringstream ssi;
	std::string str= "020101";
	ssi<<str;
	int y = x.readAll(ssi);
	std::stringstream sso;
	x.writeAll(sso);
	EXPECT_EQ(str,sso.str());
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