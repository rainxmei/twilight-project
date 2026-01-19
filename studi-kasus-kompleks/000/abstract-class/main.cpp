#include "Player.h"

int main() {
    // Character c("Hero"); ❌ ERROR (abstract)
    // karena character belum lengkap dan c++ melarang object yang bleum lengkap 
    Player p("Knight");     // ✅

    p.showStatus();
    p.attack();

    return 0;
}
