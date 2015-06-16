#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include "asn_sequence.h"

TEST(testASN_sequence, getSizeTest){
	asn_sequence x;
	std::stringstream ss;
	std::string str= "300C13044B75626113044172656B";//301F13064D616369656A13044B6C6F73020113300C13044B75626113044172656B
	ss<<str;
	int y = x.readAll(ss);
	EXPECT_EQ((str.size()-4)/2,x.getSize());
}

TEST(testASN_sequence, GoodDataFromStream){
	asn_sequence x;
	std::stringstream ss;
	std::string str= "300C13044B75626113044172656B";//301F13064D616369656A13044B6C6F73020113300C13044B75626113044172656B
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(14,y);
	EXPECT_EQ("", tmp);
}

TEST(testASN_sequence, ShortDataFromStream){
	asn_sequence x;
	std::stringstream ss;
	std::string str= "3011";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str, tmp);
}

TEST(testASN_sequence, WrongTagFromStream){
	asn_sequence x;
	std::stringstream ss;
	std::string str= "3112";
	ss<<str;
	int y = x.readAll(ss);
	std::string tmp;
	ss>>tmp;
	EXPECT_EQ(-1,y);
	EXPECT_EQ(str,tmp);
}

TEST(testASN_sequence, WriteTest){
	asn_sequence x;
	std::stringstream ssi;
	std::string str= "300C13044B75626113044172656B";
	ssi<<str;
	int y = x.readAll(ssi);
	std::stringstream sso;
	x.writeAll(sso);
	EXPECT_EQ(str,sso.str()) ;
}
