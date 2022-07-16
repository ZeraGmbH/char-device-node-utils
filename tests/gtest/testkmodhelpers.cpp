#include "fixtures.h"
#include <gtest/gtest.h>

TEST_F(KmodTest, LoadModule) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
}

TEST_F(KmodTest, LoadModuleWithCheck) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
}

TEST_F(KmodTest, LoadRemoveModuleWithCheck) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
}

TEST_F(KmodTest, LoadRemoveModuleSequence) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());

    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());
}
