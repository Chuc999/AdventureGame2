#include "include/raylib.h"
#include "Menu.h"
#include "Quit.h"

int main(void)
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
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        while (menu->mainMenuOpen || mainMenuOpen)
        {
            menu->update();
            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            ClearBackground(GRAY);

            menu->draw();

            EndDrawing();
        }       
        
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    menu->DeInitialization();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}