#include "button.hpp"
#include "game.h"

TextureButton::TextureButton(const char *imagePath, Vector2 imagePosition, float scale)
{
    Image image = LoadImage(imagePath);

    int originalWidth = image.width;
    int originalHeight = image.height;

    int newWidth = static_cast<int>(originalWidth * scale);
    int newHeight = static_cast<int>(originalHeight * scale);

    ImageResize(&image, newWidth, newHeight);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = imagePosition;
}

TextureButton::~TextureButton()
{
    UnloadTexture(texture);
}

void TextureButton::Draw()
{
    DrawTextureV(texture, position, WHITE);
}

bool TextureButton::isPressed(Vector2 mousePos, bool mousePressed)
{   
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};

    if(CheckCollisionPointRec(mousePos,rect) && mousePressed)
    {
        return true;
    }
    return false;
}

TextButton::TextButton(const char* inp_text, int x, int y, int width, int height, int fontSize)
{
    text = inp_text;
    rec = {x, y, width, height};
    size = fontSize;
}

void TextButton::Draw()
{
    DrawRectangleRoundedLines(rec, 10, 1, LINE_THICKNESS, BLACK);
    Vector2 length = MeasureTextEx(GetFontDefault(), text, size, size/ 10);
    DrawText(text,rec.x + (rec.w / 2) - (length.x / 2),rec.y + (rec.h / 2) - (length.y / 2), size, BLACK);
}

void TextButton::IsPressed(void (*func)(void*), void* arg)
{
    Vector2 mousePos = GetMousePosition();
    if(
        mousePos.x > rec.x && mousePos.x < rec.x + rec.w &&
        mousePos.y > rec.y && mousePos.y < rec.y + rec.h &&
        IsMouseButtonPressed(LEFT_CLICK)
    )
    {
    func(arg);
    }
}
