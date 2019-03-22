#include "doctest.h"
#include <sstream>

TEST_CASE("Timestamp_ClassKeepsAssignedData")
{
    const Timestamp ts(10000);
    CHECK(ts.GetValue() ==  10000);
}

TEST_CASE("Timestamp_SetChangesData")
{
    Timestamp ts(10000);
    CHECK(ts.GetValue() ==  10000);

    ts.SetValue(20000);
    CHECK(ts.GetValue() ==  20000);
}


TEST_CASE("Timestamp_DefatTimestampIsZero")
{
  const Timestamp ts;
  CHECK(ts.GetValue() ==  0);
}

TEST_CASE("Timestamp_OutputStreamPrintsData")
{
  const Timestamp ts1(10000);
  const Timestamp ts2(20000);
  std::ostringstream oss1;
  std::ostringstream oss2;

  oss1 << ts1;
  CHECK(oss1.str() ==  std::string("10000"));

  oss2 << ts1 << ' ' << ts2;
  CHECK(oss2.str() ==  std::string("10000 20000"));
}

TEST_CASE("Timestamp_InputStreamSetsData")
{
  Timestamp ts1;
  Timestamp ts2(10000);
  std::istringstream iss1("20000");
  std::istringstream iss2("30000 40000");

  iss1 >> ts1;
  CHECK(ts1.GetValue() ==  20000);

  iss2 >> ts1 >> ts2;
  CHECK(ts1.GetValue() ==  30000);
  CHECK(ts2.GetValue() ==  40000);
}

TEST_CASE("Timestamp_AdditionAssignmentChangesData")
{
  Timestamp ts1(10000);

  ts1 += 20000;
  CHECK(ts1.GetValue() ==  30000);

  (ts1 += 20000) += 30000;
  CHECK(ts1.GetValue() ==  80000);

}

TEST_CASE("Timestamp_AdditionCalcatesCorrectly")
{
  const Timestamp ts1(10000);
  const Timestamp ts2(20000);

  Timestamp ts3 = ts1 + ts2;
  CHECK(ts3.GetValue() ==  30000);
}
