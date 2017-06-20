//
//  GLBlinnPhongProgram.hpp
//  EARenderer
//
//  Created by Pavlo Muratov on 11.04.17.
//  Copyright © 2017 MPO. All rights reserved.
//

#ifndef GLBlinnPhongProgram_hpp
#define GLBlinnPhongProgram_hpp

#include "GLProgram.hpp"
#include "Material.hpp"
#include "GLDepthTexture2D.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace EARenderer {
    
    class GLBlinnPhongProgram: public GLProgram {
    public:
        using GLProgram::GLProgram;
        
        void setCameraPosition(const glm::vec3& position);
        void setLightPosition(const glm::vec3& position);
        void setCameraSpaceMatrix(const glm::mat4& matrix);
        void setLightSpaceMatrix(const glm::mat4& matrix);
        void setModelMatrix(const glm::mat4& matrix);
        void setNormalMatrix(const glm::mat4& matrix);
        void setLightColor(const glm::vec3& color);
        void setMaterial(const Material& material);
        void setShadowMap(const GLDepthTexture2D& shadowMap);
        void setHighlighted(bool isHighlighted);
    };
    
}

#endif /* GLBlinnPhongProgram_hpp */