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

    void Draw(){
        DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
    }


};



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

        EndDrawing();
    }
    


    //Close
    CloseWindow();
    return 0;
}