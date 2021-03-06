//
// Created by roundedglint585 on 3/11/19.
//

#ifndef TGV_TOTALGENERALIZEDVARATION_HPP
#define TGV_TOTALGENERALIZEDVARATION_HPP

#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include "MathRoutine.hpp"


constexpr float eps = 0.00001;

class TotalGeneralizedVariation {
public:

    using Image = std::vector<std::vector<float>>;
    using Gradient = std::vector<std::vector<std::array<float, 2>>>;
    using Epsilon = std::vector<std::vector<std::array<float, 4>>>;

    explicit TotalGeneralizedVariation(const std::vector<Image> &);

    explicit TotalGeneralizedVariation(std::vector<Image> &&);

    void iteration(float tau, float lambda_tv, float lambda_tgv,
                   float lambda_data);

    Image getImage() const;
private:
    //math routine

    void calculateHist();

    Image prox(const Image &image, float tau, float lambda_data);



    //
    void init();

    void initWs();

    void initStacked();

    std::vector<Image> m_images;
    std::vector<Image> Ws; //histogram fot images
    std::vector<std::vector<std::vector<float>>> stacked;
    Image m_result;
    size_t m_width;
    size_t m_height;
    Gradient p,v;
    Epsilon q;


};


#endif //TGV_TOTALGENERALIZEDVARATION_HPP
