#include "fixtures.h"
#include <gtest/gtest.h>

class Helpers : public KModuleNotLoaded {};

TEST_F(Helpers, LoadModule) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
}

TEST_F(Helpers, LoadModuleWithCheck) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
}

TEST_F(Helpers, LoadRemoveModuleWithCheck) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
}

TEST_F(Helpers, LoadRemoveModuleSequence) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());

    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());
}
