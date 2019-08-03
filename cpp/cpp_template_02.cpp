// 实现模板特化
// 所谓模板特例化即对于通例中的某种或某些情况做单独专门实现，最简单的情况是对
// 每个模板参数指定一个具体值，这成为完全特例化（full specialization），另外，
// 可以限制模板参数在一个范围取值或满足一定关系等，这称为
// 部分特例化（partial specialization），用数学上集合的概念，通例模板参数所
// 有可取的值组合构成全集U，完全特例化对U中某个元素进行专门定义，部分特例化
// 对U的某个真子集进行专门定义。

// 实现一个向量类
template<typename T, int N>
class Vec{
    T _v[N];
    // ... // 模板通例（primary template），具体实现
};

template<>
class Vec<float, 4>{
    float _v[4];
    // ... // 对 Vec<float, 4> 进行专门实现，如利用向量指令进行加速
};

template<int N>
class Vec<bool, N>{
    char _v[(N+sizeof(char)-1)/sizeof(char)];
    // ... // 对 Vec<bool, N> 进行专门实现，如用一个比特位表示一个bool
};