#include <pybind11/pybind11.h>
#include <cmath>
#include <stdint.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

//Function to be exposed to Python
double invSqrt_fast(double number) {
    double y = number;
    double x2 = number * 0.5;
    int64_t i = *(int64_t*)&y;
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    y = *(double*)&i;
    y = y * (1.5 - (x2 * y * y));   // 1st iteration
    // y  = y * ( 1.5 - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

double invSqrt(double number) {
    return 1./sqrt(number);
    // return pow(number, -0.5);
}

namespace py = pybind11;

PYBIND11_MODULE(fastmath, m) {
    m.doc() = R"pbdoc(
        fastmath
        --------
        .. currentmodule:: fastmath
        .. autosummary::
           :toctree: _generate

           invSqrt
           invSqrt_fast
    )pbdoc";
    
    m.def("invSqrt_fast", &invSqrt_fast, R"pbdoc(fast inverse sqrt)pbdoc");

    m.def("invSqrt", &invSqrt, R"pbdoc(inverse sqrt)pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}

// https://github.com/pybind/python_example/blob/master/src/main.cpp
// https://learn.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2022