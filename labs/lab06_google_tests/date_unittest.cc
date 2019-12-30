#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}


/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */


TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

TEST_F(DateTest, GetUsDateTests) {
  Date utc_start(1970,1,2);
  Date before_utc_start(1000,1,2);//if date is before utc, shouldn't convert (according to date.correct.cc)
  Date leading_zero_years(888,1,2);
  Date future_(3000,12,12);
  EXPECT_EQ(utc_start.GetUsDate(), "01-02-1970") << "UTC start date to US time done incorrectly";
  EXPECT_EQ(before_utc_start.GetUsDate(), "01-02-1000") << "before UTC start date to US time done incorrectly";
  EXPECT_EQ(leading_zero_years.GetUsDate(), "01-02-888") << "leading 0's year date to US done incorrectly";
  EXPECT_EQ(future_.GetUsDate(), "12-12-3000") << "future date incorrect";
}

TEST_F(DateTest, GetDateTests) {
  Date utc_start(1970,1,2);
  Date before_utc_start(1000,1,2);//if date is before utc, shouldn't convert (according to date.correct.cc)
  Date leading_zero_years(888,1,2);
  Date future_(3000,12,12);
  EXPECT_EQ(utc_start.GetDate(), "1970-01-02") << "UTC start date to time done incorrectly";
  EXPECT_EQ(before_utc_start.GetDate(), "1000-01-02") << "before UTC start date to time done incorrectly";
  EXPECT_EQ(leading_zero_years.GetDate(), "888-01-02") << "leading 0's year date to time done incorrectly";
  EXPECT_EQ(future_.GetDate(), "3000-12-12") << "future date incorrect";
}

TEST_F(DateTest,TodaysDateTests) {
  Date today;
  //from date.correct.cc
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  //tm year's value is years since 1900
  int yyyy = now->tm_year + 1900;
  //tm month's value is zero-indexed
  int mm = now->tm_mon + 1;
  //tm day's value is one-indexed
  int dd = now->tm_mday;
  Date correct_today(yyyy,mm,dd);
  testing::internal::CaptureStdout();
  today.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output1,correct_today.GetDate()) << " testing Todays Date Test";
}

TEST_F(DateTest, DaysBetweenTestsLeapYear) {
  Date leap_month_test_a(2016,1,1);
  Date leap_month_test_b(2016,3,1);
  Date leap_400_year_test_a(2000,1,1);
  Date leap_400_year_test_b(2000,3,1);
  Date leap_400_year_test_c(1900,1,1);
  Date leap_400_year_test_d(1900,3,1);
  EXPECT_EQ(leap_month_test_a.DaysBetween(leap_month_test_b), 60) << "4 year leap not done properly";
  EXPECT_EQ(leap_400_year_test_a.DaysBetween(leap_400_year_test_b), 60) << "400 year anti-leap not done properly";
  EXPECT_EQ(leap_400_year_test_c.DaysBetween(leap_400_year_test_d), 59) << "400 year leap not done properly";
}

TEST_F(DateTest, SubtractOperation) {
  Date day_after_leap_day(2016,3,1);
  Date test1(2000,1,2);
  Date ans_test1(2000,1,1);
  Date leap_day_2016(2016,2,29);
  day_after_leap_day = day_after_leap_day - 1;
  test1 = test1 - 1;
  EXPECT_EQ(test1.GetDate(),ans_test1.GetDate()) << "Subtract Operation doesn't work";
  EXPECT_EQ(day_after_leap_day.GetDate(), leap_day_2016.GetDate()) << " Subtract Operation doesn't work on leap day";
}

TEST_F(DateTest, AdditionOperation) {
  Date day_before_leap_day(2016,2,28);
  Date test1(2000,1,1);
  Date ans_test1(2000,1,2);
  Date leap_day_2016(2016,2,29);
  test1 = test1 + 1;
  day_before_leap_day = day_before_leap_day + 1;
  EXPECT_EQ(test1.GetDate(),ans_test1.GetDate()) << "Addition Operation doesn't work";
  EXPECT_EQ(day_before_leap_day.GetDate(), leap_day_2016.GetDate()) <<" Addition Operation doesn't work on leap day";
}

TEST_F(DateTest, TestZeroIndexWrapAround) {
  Date last_day_of_the_year(2018,12,31);
  last_day_of_the_year = last_day_of_the_year + 2;
  EXPECT_EQ(last_day_of_the_year.GetDate(), "2019-01-02") << "Zero index month wrap around test";
}

TEST_F(DateTest, EpochTests) {
  Date utc_start(1970,1,1);
  Date epoch_1(0);
  Date y2k(1999,12,31);
  Date epoch_2(946663201);
  Date epoch_3(-100000000);
  Date large_negative_epoch(1966,10,31);
  Date epoch_4(-1);
  Date small_negative_epoch(1969,12,31);
  EXPECT_EQ(large_negative_epoch.GetDate(),epoch_3.GetDate()) << "large negative epoch time doesn't have correct Epoch Value";
  EXPECT_EQ(small_negative_epoch.GetDate(),epoch_4.GetDate()) << "small negative epoch time doesn't have correct Epoch Value";
  EXPECT_EQ(y2k.GetDate(),epoch_2.GetDate()) << "Y2K doesn't have correct Epoch Value";
  EXPECT_EQ(utc_start.GetDate(),epoch_1.GetDate()) << "UTC Start Time doesn't have correct Epoch Value";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
