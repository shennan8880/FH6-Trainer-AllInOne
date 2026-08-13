// FH6 Trainer - ImGui overlay renderer
#include "../include/Trainer.h"

namespace FH6 {

void Overlay::Render(Features& f) {
    // ImGui window: feature toggles, sliders, teleport coords
    // F1 Unlimited Money | F2 Speed | F3 No Damage | F4 Cars
    // F5 Teleport | F6 Instant Win | F7 Skip Checkpoint | F8 XP
}

void Overlay::Toggle() {
    m_visible = !m_visible;
}

} // namespace FH6
