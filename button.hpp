#pragma once
#include <raylib.h>

#define LINE_THICKNESS 7
#define LEFT_CLICK 0


struct Rect
{
    int x, y, w, h;
    operator Rectangle()
    {
        return {(float)x,(float)y,(float)w,(float)h};
    }
};

class TextureButton
{
    public:
        TextureButton(const char* imagePath, Vector2 imagePosition, float scale);
        ~TextureButton();
        void Draw();
        bool isPressed(Vector2 mousePos, bool mousePressed);
    private:
        bool textured;
        Texture2D texture;
        Vector2 position;
};

class TextButton
{
public:
    TextButton(const char* text, int x, int y, int width, int height, int fontSize);
    void Draw();
    void IsPressed(void (*func)(void*), void* arg);

private:
    Rect rec;
    const char* text;
    int size;
};