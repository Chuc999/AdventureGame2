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