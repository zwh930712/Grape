#include <algorithm>
#include <random>
#include "javernn/util/random.h"

namespace javernn{
    
    Random Random::GetInstance()
    {
        static Random random;
        return random;
    }

    Random::Random()
    {
        
    }

    Random::~Random()
    {

    }

    int Random::GetUniformInt(int from, int to)
    {
        std::uniform_int_distribution<int> distribution(from, to);
        return distribution(generator_);
    }

    float Random::GetUniformFloat(float from, float to)
    {
        std::uniform_real_distribution<float> distribution(from, to);
        return distribution(generator_);
    }

    float Random::GetNormalFloat(float mean, float stddev)
    {
        std::normal_distribution<float> distribution(mean,stddev);
        return distribution(generator_);
    }

    void Random::SetUniformInt(int* data, int size, int from, int to)
    {
        std::uniform_int_distribution<int> distribution(from, to);
        for(int i=0;i<size;i++){
            data[i] = distribution(generator_);
        }
    }

    void Random::SetUniformFloat(float* data, int size, float from, float to)
    {
        std::uniform_real_distribution<float> distribution(from, to);
        for(int i=0;i<size;i++){
            data[i] = distribution(generator_);
        }
    }

    void Random::SetNormalFloat(float* data, int size, float mean, float stddev)
    {
        std::normal_distribution<float> distribution(mean,stddev);
        for(int i=0;i<size;i++){
            data[i] = distribution(generator_);
        }
    }
}