// FH6 Trainer - Feature toggles (money, cars, speed, teleport)
#include "../include/Trainer.h"

namespace FH6 {

void Features::ToggleUnlimitedMoney(bool on) {
    // Freeze credit value at 999,999,999 via memory lock
    m_moneyEnabled = on;
}

void Features::SetSpeedMultiplier(float mult) {
    if (mult < 1.0f) mult = 1.0f;
    if (mult > 10.0f) mult = 10.0f;
    m_speedMult = mult;
}

void Features::UnlockAllCars() {
    // Write ownership flags for all 812 vehicles
}

void Features::TeleportTo(float x, float y, float z) {
    m_teleportTarget = {x, y, z};
    m_teleportPending = true;
}

void Features::ToggleNoDamage(bool on) {
    m_noDamage = on;
}

void Features::InstantWin() {
    // Set race position to 1st and trigger finish
}

} // namespace FH6
