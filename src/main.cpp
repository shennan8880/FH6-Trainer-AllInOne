// FH6 Trainer - Entry point
// Version: 2.8
#include "../include/Trainer.h"
#include <windows.h>
#include <iostream>

int main(int argc, char* argv[]) {
    FH6::Trainer trainer;
    std::cout << "[FH6] Waiting for Forza Horizon 6...\n";
    if (!trainer.Attach()) {
        std::cerr << "[FH6] Game process not found. Launch FH6 first.\n";
        return 1;
    }
    std::cout << "[FH6] Attached. Press INSERT for menu, F1-F8 to toggle.\n";
    return trainer.Run();
}
