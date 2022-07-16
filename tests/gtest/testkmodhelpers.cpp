#include "fixtures.h"
#include <gtest/gtest.h>

TEST_F(KModuleNotLoaded, LoadModule) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
}

TEST_F(KModuleNotLoaded, LoadModuleWithCheck) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
}

TEST_F(KModuleNotLoaded, LoadRemoveModuleWithCheck) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
}

TEST_F(KModuleNotLoaded, LoadRemoveModuleSequence) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());

    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());
}
