#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <cmath>
#include <algorithm>

namespace py = pybind11;

int match(py::array_t<double> keypoints1, py::array_t<double> keypoints2, double position_thresh, double theta_thresh){
    auto keypoints1_ptr = keypoints1.unchecked<2>();
    auto keypoints2_ptr = keypoints2.unchecked<2>();

    int num_1 = keypoints1.shape(0);
    int num_2 = keypoints2.shape(0);
    int max_score = 0;

    for (int i = 0; i < num_1; ++i) {
        for (int j = 0; j < num_2; ++j) {
            double dx = keypoints1_ptr(i, 0) - keypoints2_ptr(j, 0);
            double dy = keypoints1_ptr(i, 1) - keypoints2_ptr(j, 1);
            double dtheta = keypoints1_ptr(i, 2) - keypoints2_ptr(j, 2);
            double distance = std::sqrt(dx * dx + dy * dy);
            if (distance <= position_thresh && std::abs(dtheta) <= theta_thresh) {
                max_score++;
            }
        }
    }

    return max_score;
}

PYBIND11_MODULE(match, m) {
    m.def("match", &match, "Matches keypoints between two sets");
}
