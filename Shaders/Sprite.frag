#version 330 core

// Input từ vertex shader
in vec2 fragTexCoord;

// Output màu cuối cùng
out vec4 outColor;

// Uniform sampler để lấy texture
uniform sampler2D uTexture;

void main()
{
    // Lấy màu từ texture tại tọa độ fragTexCoord
    outColor = texture(uTexture, fragTexCoord);
}
