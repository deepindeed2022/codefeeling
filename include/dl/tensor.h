#ifndef _INCLUDE_DL_TENSOR_H_
#define _INCLUDE_DL_TENSOR_H_
#include <utility>
namespace dl {
class Size {
public:
	Size(size_t rows, size_t cols):
		m_rows(rows), m_cols(cols)
	{}
	Size():
		m_rows(0), m_cols(0)
	{}

	size_t rows() const { return m_rows; }
	size_t &rows() { return m_rows; }
	size_t cols() const { return m_cols; }
	size_t &cols() { return m_cols; }
	size_t height() const { return rows(); }
	size_t &height() { return rows(); }
	size_t width() const { return cols(); }
	size_t &width() { return cols(); }

	bool operator == (const Size &rhs) const {
		return rows() == rhs.rows() && cols() == rhs.cols();
	}
private:
	size_t m_rows, m_cols;
};

class TensorShape: public Size {
public:
	TensorShape(size_t rows, size_t cols, size_t channels):
		Size(rows, cols), m_channels(channels){ }
	size_t channels() const { return m_channels; }
	bool operator == (const TensorShape &rhs) const {
		return Size::operator==(rhs) && channels() == rhs.channels();
	}
private:
	size_t m_channels;
};

template <typename T>
class Tensor {
private:
	size_t m_rows, m_cols;
	size_t m_channels;
	size_t m_step;
	std::shared_ptr<T> m_data;
	size_t m_offset;
	T *raw_ptr() { return m_data.get() + m_offset; }
	const T *raw_ptr() const { return m_data.get() + m_offset; }
public:
	Tensor();
	Tensor(size_t rows, size_t cols, size_t channels, size_t step);
	Tensor(size_t rows, size_t cols, size_t channels);
	// do not try to manage data by shared_ptr
	Tensor(size_t rows, size_t cols, size_t channels, T *data);
	Tensor(size_t rows, size_t cols, size_t channels, size_t step, T *data);
	// shallow-copy constructor
	Tensor(const Tensor<T> &rhs);
	Tensor(const Tensor<T> &rhs, size_t row_offset, size_t row_count,
			size_t col_offset, size_t col_count);
	Tensor<T> &operator=(const Tensor<T> &rhs);

	T &at(size_t r, size_t c, size_t ch);
	const T &at(size_t r, size_t c, size_t ch) const;

	Tensor<T> clone() const;

	// read data from src
	void read(const T *src);
	// write data to dst
	void write(T *dst) const;

	const T *ptr(size_t r = 0) const {
		return raw_ptr() + r * m_step;
	}
	T *ptr(size_t r = 0) {
		return raw_ptr() + r * m_step;
	}
	size_t height() const { return rows(); }
	size_t width() const { return cols();}
	size_t rows() const {return m_rows;}
	size_t cols() const { return m_cols;}
	size_t channels() const { return m_channels; }
	size_t step() const { return m_step; }
	size_t total_nr_elem() const {return rows() * cols() * channels();}
	size_t total_span_elem() const { return rows() * step(); }
	bool equals(const Tensor<T> &rhs) const;
	bool is_continuous() const;
	Size size() const { return {rows(), cols()}; }
	TensorShape shape() const { return {rows(), cols(), channels()}; }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Tensor<T> &m);

// type aliases
using uchar = unsigned char;
using ushort = unsigned short;
using Tensor8u = Tensor<uchar>;
using Tensor32f = Tensor<float>;
}

#endif