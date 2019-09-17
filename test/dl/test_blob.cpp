#include <dl/datablob.h>
#include <gtest/gtest.h>
#include <test_api.h>

namespace test {
template <typename T>
void fill_uniform_int(dl::DataBlob<T> &mat)
{
    std::mt19937 engine;
    std::uniform_int_distribution<T> dist(
            std::numeric_limits<T>::min(),
            std::numeric_limits<T>::max());
    for (size_t r = 0; r < mat.height(); ++r) {
        for (size_t c = 0; c < mat.width(); ++c) {
            for (size_t ch = 0; ch < mat.channels(); ++ch) {
                T &target = mat.at(r, c, ch);
                target = dist(engine);
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
        dl::DataBlob<dl::uchar> A(3, 4, 1);
        for (int i = 0; i < 12; ++i) A.ptr()[i] = i;
        dl::DataBlob<dl::uchar> B(A, 0, 2, 1, 2);
        std::cout << A << std::endl;
        std::cout << B << std::endl;
    }
}
