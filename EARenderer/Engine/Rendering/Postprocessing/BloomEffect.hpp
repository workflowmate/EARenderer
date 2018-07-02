//
//  BloomFilter.hpp
//  EARenderer
//
//  Created by Pavel Muratov on 6/26/18.
//  Copyright © 2018 MPO. All rights reserved.
//

#ifndef BloomFilter_hpp
#define BloomFilter_hpp

#include "PostprocessEffect.hpp"
#include "GLHDRTexture2D.hpp"
#include "GaussianBlurEffect.hpp"
#include "GLFramebuffer.hpp"
#include "GLSLBloom.hpp"
#include "BloomSettings.hpp"

#include <memory>

namespace EARenderer {

    class BloomEffect: public PostprocessEffect {
    private:
        std::shared_ptr<const GLHDRTexture2D> mBaseImage;
        std::shared_ptr<const GLHDRTexture2D> mThresholdFilteredImage;
        std::shared_ptr<GLHDRTexture2D> mSmallThresholdFilteredImage;
        std::shared_ptr<GLHDRTexture2D> mMediumThresholdFilteredImage;
        std::shared_ptr<GLHDRTexture2D> mLargeThresholdFilteredImage;
        std::shared_ptr<GLHDRTexture2D> mOutputImage;

        GaussianBlurEffect mSmallBlurEffect;
        GaussianBlurEffect mMediumBlurEffect;
        GaussianBlurEffect mLargeBlurEffect;

        GLSLBloom mBloomShader;

    public:
        BloomEffect(std::shared_ptr<const GLHDRTexture2D> baseImage,
                    std::shared_ptr<const GLHDRTexture2D> thresholdFilteredImage,
                    std::shared_ptr<GLFramebuffer> sharedFramebuffer);

        std::shared_ptr<GLHDRTexture2D> outputImage() const;
        std::shared_ptr<GLHDRTexture2D> bloom(const BloomSettings& settings);
    };

}

#endif /* BloomFilter_hpp */