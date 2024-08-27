#include <raylib.h>
#include <iostream>

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;

class Food{
    public:
    Vector2 position = {5, 6};
    Texture2D texture;
    

    Food(){
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
    }

    ~Food(){
        UnloadTexture(texture);
    }

    void Draw(){
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    }
};

Food food = Food();

int main(){
    cout << "Starting Game!" << endl;
    //Init
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Snake Lol");
    SetTargetFPS(60);

    //Init Objects

    //Game Loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(green);
        food.Draw();

        EndDrawing();
    }
    


    //Close
    CloseWindow();
    return 0;
}

