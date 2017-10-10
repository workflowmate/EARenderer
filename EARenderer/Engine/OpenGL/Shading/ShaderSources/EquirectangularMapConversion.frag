#version 400 core

// Constants

const vec2 kInvAtan = vec2(0.1591, 0.3183);

// Uniforms

uniform sampler2D uEquirectangularMap;

// Input

in vec4 vFragPosition;

// Output

out vec4 oFragColor;

// Functions

vec3 SampleSphericalMap(vec3 v) {
    vec2 uv = vec2(atan(v.z, v.x), asin(v.y));
    uv *= kInvAtan;
    uv += 0.5;
    return texture(uEquirectangularMap, uv).rgb;
}

void main() {
    vec3 sampledColor = SampleSphericalMap(normalize(vFragPosition.xyz)); // Don't forget to normalize!
//    oFragColor = vec4(sampledColor, 1.0);
    oFragColor = vec4(0.2, 0.5, 0.7, 1.0);
}
