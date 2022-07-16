#include "fixtures.h"
#include <filesystem>

namespace fs = std::filesystem;

class DevNodeControl : public KModuleLoaded {};

/*TEST_F(DevNodeControl, CncControlExist) {
    EXPECT_TRUE(fs::exists("/dev/cnc-control"));
}*/
