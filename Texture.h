//
// Created by Binh Nguyen Thanh on 19/4/26.
//

#ifndef ASTEROID_TEXTURE_H
#define ASTEROID_TEXTURE_H


class Texture {
public:
    Texture();
    ~Texture();
    bool Load(const char* fileName);
    void Unload();
    void SetActive();

    int GetWidth();
    int GetHeight();
private:
    unsigned int mTextureID;
    int mWidth;
    int mHeight;
};


#endif //ASTEROID_TEXTURE_H