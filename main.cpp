#include "include/raylib.h"
#include "Menu.h"
#include "Quit.h"

int main2(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    Menu* menu = new Menu();
    Quit* quit = new Quit();
    menu->mainMenu();
    bool mainMenuOpen = true;
    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {      
        menu->update();
    
        BeginDrawing();

        ClearBackground(GRAY);

        menu->draw();

        EndDrawing();
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    menu->DeInitialization();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

#define MAX_BUILDINGS 100
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    Menu* menu = new Menu();
    Quit* quit = new Quit();
    menu->mainMenu();
    bool mainMenuOpen = true;
    SetTargetFPS(120);

    Rectangle player = { 400, 280, 40, 40 };
    Rectangle buildings[MAX_BUILDINGS] = { 0 };
    Color buildColors[MAX_BUILDINGS] = { 0 };

    int spacing = 0;
    bool right = true;

    for (int i = 0; i < MAX_BUILDINGS; i++)
    {
        buildings[i].width = (float)GetRandomValue(50, 200);
        buildings[i].height = (float)GetRandomValue(100, 800);
        buildings[i].y = screenHeight - (buildings[i].height - 200);
        buildings[i].x = -6000.0f + spacing;

        spacing += (int)buildings[i].width;

        buildColors[i] = Color{ (unsigned char)GetRandomValue(200, 240), (unsigned char)GetRandomValue(200, 240), (unsigned char)GetRandomValue(200, 250), 255 };
    }

    Camera2D camera = { 0 };
    camera.target = Vector2{ player.x + 20.0f, player.y + 20.0f };
    camera.offset = Vector2{ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 0.25f;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        menu->update();
        // Player movement
       
        if (right)
        {
            player.x += 2;
            if (camera.target.x == 5200)
            {
                right = false;
            }
        }
        if (!right)
        {
            player.x -= 2;
            if (camera.target.x == -4200)
            {
                right = true;
            }
        }
        // Camera target follows player
        camera.target = Vector2{ player.x + 20, player.y + 20 };
  
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(SKYBLUE);
        BeginMode2D(camera);

        DrawRectangle(-6000, 600, 13000, 8000, DARKGREEN);

        for (int i = 0; i < MAX_BUILDINGS; i++) DrawRectangleRec(buildings[i], buildColors[i]);

        EndMode2D();
        menu->draw();
     
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}