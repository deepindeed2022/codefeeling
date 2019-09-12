#ifndef INCLUDE_POLYGON_H_
#define INCLUDE_POLYGON_H_
template <typename scalar_t>
class Polygon {
public:
	typedef struct polygon_point_t {
		scalar_t x;
		scalar_t y;
	} polygon_point_t;
	Polygon(int n): v_num(n) {
		points.resize(v_num);
	}
	Polygon(const std::string& infile) {
		std::ifstream fin(infile);
		if(!fin) {
			std::cerr << "fail to open the file " << infile << std::endl;
		} else {
			bool result = this->create_(fin);
			if(!result) {
				std::cerr << "create Polygon from " << infile << " failed\n";
			}
		}
	}
	polygon_point_t GetPoint(uint32_t i) { return points[i];}

	double Area() {
		if (v_num < 3) return 0;
		double s = points[0].y * (points[v_num - 1].x - points[1].x);
		for (uint32_t i = 1; i < v_num; i++)
			s += points[i].y * (points[(i - 1)].x - points[(i + 1) % v_num].x);
		return std::fabs(s / 2.0f);
	}
private:
	uint32_t v_num;
	std::vector<polygon_point_t> points;
	bool create_(std::istream& in) {
		in >> v_num;
		if(v_num <= 2) {
			std::cerr << "Invalid: polygon point number <= 2 !!\n";
			return false;
		}
		points.resize(v_num);
		for(size_t i = 0; i < this->v_num; i++) {
			polygon_point_t p;
			in >> p.x >> p.y;
			points[i] = p;
		}
		return true;
	}
};

#endif