#include <gtest/gtest.h>
#include <dl/datablob.h>
#include <test_api.h>
#include <limits> // numeric_limits
#include <random>  // uniform_int_distribution

namespace test {
template <class T>
void fill_uniform_int(dl::DataBlob<T> &mat)
{
    std::mt19937 engine;
    std::uniform_int_distribution<int> dist(0, 100);
    for (size_t r = 0; r < mat.height(); ++r) {
        for (size_t c = 0; c < mat.width(); ++c) {
            for (size_t ch = 0; ch < mat.channels(); ++ch) {
                T &target = mat.at(r, c, ch);
                target = static_cast<T>(dist(engine));
            }
        }
    }
}
}
dl::DataBlob<dl::uchar> get_matrix(dl::uchar *&p)
{
    dl::DataBlob<dl::uchar> A(3, 4, 3);
    p = &A.at(0, 0, 0);
    return A;
}

TEST(DL, DataBlob)
{
    dl::DataBlob<dl::uchar> A(3, 4, 3);
    test::fill_uniform_int(A);
    A.at(0, 0, 0) = 1;

    auto B = A;
    B.at(0, 0, 0) = 0;
    ASSERT_EQ(A.at(0, 0, 0), B.at(0, 0, 0));

    auto C(A);
    C.at(0, 0, 0) = 2;
    ASSERT_EQ(C.at(0, 0, 0), A.at(0, 0, 0));
    ASSERT_EQ(C.at(0, 0, 0), B.at(0, 0, 0));

    dl::uchar *p;
    auto D = get_matrix(p);
    ASSERT_EQ(p, &D.at(0, 0, 0));
    {
        dl::DataBlob<dl::uchar> A(3, 4, 3);
        for (int i = 0; i < 36; ++i) A.ptr()[i] = i;
        dl::DataBlob<dl::uchar> B(A, 0, 2, 1, 2);
        std::cout << A << std::endl;
        std::cout << B << std::endl;
    }
}
