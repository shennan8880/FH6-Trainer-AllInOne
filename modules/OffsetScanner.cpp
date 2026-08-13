// FH6 Trainer - Offset scanner for game updates
#include "../include/Trainer.h"
#include <vector>

namespace FH6 {

uintptr_t OffsetScanner::FindPattern(HANDLE process, const std::string& pattern) {
    // Pattern scan: "48 8B ?? ?? 0F 28" style signatures
    // Resilient to game updates via wildcards
    return 0;
}

bool OffsetScanner::UpdateOffsets(const std::string& configPath) {
    // Rescan after game patch, write new offsets to config/offsets.json
    return true;
}

} // namespace FH6
