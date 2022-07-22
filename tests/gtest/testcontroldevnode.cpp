#include "fixtures.h"
#include "globals.h"
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

class DevNodeControl : public KModuleLoaded {};

TEST_F(DevNodeControl, CncModuleLoaded) {
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
}

/*TEST_F(DevNodeControl, CncControlExist) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    EXPECT_TRUE(fs::exists(CNC_CONTROL_DEV_NAME));
}*/
