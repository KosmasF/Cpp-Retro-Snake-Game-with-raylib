#include <raylib.h>
#include <deque>

extern const int cellSize;
extern const int cellCount;
extern const int offset;


extern bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);

class Food
{
public:
    Vector2 position;
    static Image image;
    static Texture2D texture;
    static bool initialized;

    Food(std::deque<Vector2> snakeBody);

    void Draw();

    Vector2 GenerateRandomCell();

    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);


};