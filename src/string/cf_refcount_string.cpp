#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

#define stub() fprintf(stderr, "%s:%d\n", __FILE__, __LINE__)

namespace cf {
    typedef struct m_manager {
        char* m_data;
        size_t size;
        int ref_count;
    } m_manager;
    class string {
    public:
        string():m_mem(NULL){};
        string(const char* c_s) {
            fprintf(stderr, "mt::string(const char* c_s)\n" );
            assert(c_s != NULL);
            int len = strlen(c_s);
            if(len > 0) {            
                if(this->m_mem) {
                    m_mem = new m_manager;
                    m_mem->size = len + 1;
                    m_mem->m_data = new char[len + 1];
                    strcpy(m_mem->m_data, c_s);
                    m_mem->ref_count = 1;
                } else {
                    m_mem->ref_count --;
                    if(m_mem->ref_count == 0) {
                        delete [] m_mem->m_data;
                    }
                    m_mem->size = len + 1;
                    m_mem->m_data = new char[len + 1];
                    strcpy(m_mem->m_data, c_s);               
                    m_mem->ref_count = 1;
                }
            }
        }
        string(const string& s) {
            fprintf(stderr, "mt::string(const string& s)\n");
            m_mem = s.m_mem;
            m_mem->ref_count++;
        }
        string& operator=(const string& s) {
            fprintf(stderr, "mt::string assign operator\n");
            if(this == &s) return *this;
            m_mem->ref_count--;
            if(m_mem->ref_count == 0) {            
                delete[] m_mem->m_data;
                delete m_mem;
            }
            m_mem = s.m_mem;
            m_mem->ref_count++;
            return *this;
        }
        ~string() {
            m_mem->ref_count--;
            if(m_mem->ref_count == 0) {
                delete [] m_mem->m_data;
                delete m_mem;
            }
        }
        void println() const {
            fprintf(stderr, "%s %d\n", m_mem->m_data, m_mem->ref_count);
        }
     private:
        m_manager* m_mem;
    };
}



int main() {
    cf::string str("abc");
    cf::string str1=str;
    str1.println();
    cf::string a="abc";
    cf::string b=a;
    cf::string c=b;
    cf::string d="edf";
    cf::string e=d;
    {
        const char* test="1111";
        b = test;
        c = b;
    }
    b.println();
    return 0;
}