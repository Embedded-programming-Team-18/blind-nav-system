#define BOOST_TEST_MODULE SqrTests
#include <boost/test/unit_test.hpp

#include "pwm.h"
BOOST_AUTO_TEST_CASE(FailTest)
{
 BOOST_CHECK_EQUAL(5, sqr(3));
}
BOOST_AUTO_TEST_CASE(PassTest)
{
 BOOST_CHECK_EQUAL(4, sqr(2));
}