#include <raylib.h>
#include <iostream>

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

class Food{
    public:
    Vector2 position;
    Texture2D texture;

    Food(){
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);

        if (texture.id == 0) {
            cout << "Failed to load texture!" << endl;
        }
        
        position = GenerateRandomPos();
    }

    ~Food(){
        UnloadTexture(texture);
    }

    void Draw(){
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomPos(){
        Vector2 pos;
        pos.x = static_cast<float>(GetRandomValue(0, cellCount - 1));
        pos.y = static_cast<float>(GetRandomValue(0, cellCount - 1));
        return pos;
    }
};

Food food = Food();

int main(){
    cout << "Starting Game!" << endl;

    // Initialize Window
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake Game");
    SetTargetFPS(60);

    if (!IsWindowReady()) {
    cout << "Failed to initialize window!" << endl;
    return -1;
}


    // Main Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(green);
        food.Draw();

        EndDrawing();
    }

    // Close Window and Unload Resources
    cout << "Closing Game" << endl;
    CloseWindow();
    
    return 0;
}
