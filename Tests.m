
#import <XCTest/XCTest.h>
#import "TernaryVectorClass.h"

using namespace TernaryVectorClass;

@interface tests : XCTestCase

@end

@implementation tests


- (void)testEmptyConstructor {
    TernaryVectorClass::TernaryVector v;
    XCTAssertEqual(0, v.GetCurrentSize());
}


- (void)testDefaultConstructor1 {
    TernaryVectorClass::TernaryVector v(10);
    XCTAssertEqual(10, v.GetCurrentSize());
    for (int i = 0; i < v.GetCurrentSize(); ++i)
    XCTAssertEqual('X', v.GetValue(i));
}


- (void)testDefaultConstructor2 {
    std::string str = "211wkd0a  rewjn2";
    TernaryVectorClass::TernaryVector v(str);
    XCTAssertEqual('X', v.GetValue(0));
    XCTAssertEqual('1', v.GetValue(1));
    XCTAssertEqual('1', v.GetValue(2));
    XCTAssertEqual('X', v.GetValue(3));
    XCTAssertEqual('X', v.GetValue(4));
    XCTAssertEqual('X', v.GetValue(5));
    XCTAssertEqual('0', v.GetValue(6));
    XCTAssertEqual('X', v.GetValue(7));
}


- (void)testDisjunction {
    std::string str1 = "000111XX";
    TernaryVectorClass::TernaryVector v1(str1);
    std::string str2 = "01X01X01";
    TernaryVectorClass::TernaryVector v2(str2);
    TernaryVectorClass::TernaryVector v3 =  v1 | v2;
    TernaryVectorClass::TernaryVector v4 =  v2 | v1;
    XCTAssertEqual(true, v3 == v4);
    XCTAssertEqual('0', v3.GetValue(0));
    XCTAssertEqual('1', v3.GetValue(1));
    XCTAssertEqual('X', v3.GetValue(2));
    XCTAssertEqual('1', v3.GetValue(3));
    XCTAssertEqual('1', v3.GetValue(4));
    XCTAssertEqual('1', v3.GetValue(5));
    XCTAssertEqual('X', v3.GetValue(6));
    XCTAssertEqual('1', v3.GetValue(7));
}


- (void)testConjunction {
    std::string str1 = "000111XX";
    TernaryVectorClass::TernaryVector v1(str1);
    std::string str2 = "01X01X01";
    TernaryVectorClass::TernaryVector v2(str2);
    XCTAssertNoThrow(v1 &= v2);
    XCTAssertEqual('0', v1.GetValue(0));
    XCTAssertEqual('0', v1.GetValue(1));
    XCTAssertEqual('0', v1.GetValue(2));
    XCTAssertEqual('0', v1.GetValue(3));
    XCTAssertEqual('1', v1.GetValue(4));
    XCTAssertEqual('X', v1.GetValue(5));
    XCTAssertEqual('0', v1.GetValue(6));
    XCTAssertEqual('X', v1.GetValue(7));
}


- (void)testInvertion {
    std::string str = "000111XX";
    TernaryVectorClass::TernaryVector v(str);
    ~v;
    XCTAssertEqual('1', v.GetValue(0));
    XCTAssertEqual('1', v.GetValue(1));
    XCTAssertEqual('1', v.GetValue(2));
    XCTAssertEqual('0', v.GetValue(3));
    XCTAssertEqual('0', v.GetValue(4));
    XCTAssertEqual('0', v.GetValue(5));
    XCTAssertEqual('X', v.GetValue(6));
    XCTAssertEqual('X', v.GetValue(7));
}


- (void)testCompare {
    std::string str1 = "000111XX";
    TernaryVectorClass::TernaryVector v1(str1);
    std::string str2 = "01X01X01";
    TernaryVectorClass::TernaryVector v2(str2);
    XCTAssertEqual(false, v1 == v2);
    std::string str3 = "01X01X01";
    TernaryVectorClass::TernaryVector v3(str3);
    XCTAssertEqual(false,v1 == v3);
    XCTAssertEqual(true, v2 == v3);
}


- (void)testAnalysis {
    std::string str1 = "000111XX";
    TernaryVectorClass::TernaryVector v1(str1);
    std::string str2 = "011010010";
    TernaryVectorClass::TernaryVector v2(str2);
    XCTAssertEqual(6, v1.Analysis());
    XCTAssertEqual(-1, v2.Analysis());
}

@end
