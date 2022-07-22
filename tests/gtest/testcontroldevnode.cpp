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

TEST_F(DevNodeControl, CncControlExist) {
    EXPECT_TRUE(fs::exists(CNC_CONTROL_DEV_FILE_NAME));
}
