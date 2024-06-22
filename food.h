#include <raylib.h>
#include <deque>

extern const int cellSize;
extern const int cellCount;
extern const int offset;


extern bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);

class Food
{
public:
    friend class constructor;

    Vector2 position;
    static Image image;
    static Texture2D texture;

    struct constructor
    {
        constructor() {
            image = LoadImage("Graphics/food.png");
            texture = LoadTextureFromImage(image);
        }
    };

    Food(std::deque<Vector2> snakeBody);

    void Draw();

    Vector2 GenerateRandomCell();

    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);

    
    static constructor cons;
};