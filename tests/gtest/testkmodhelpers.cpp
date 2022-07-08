#include "kmodulehelpers.h"
#include <gtest/gtest.h>

TEST(TEST_KMODHELPERS, LOAD_MODULE) {
    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
}

TEST(TEST_KMODHELPERS, LOAD_MODULE_WITH_CHECK) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
}

TEST(TEST_KMODHELPERS, LOAD_REMOVE_MODULE_WITH_CHECK) {
    KModuleHelpers::loadKernelModule();
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
}

TEST(TEST_KMODHELPERS, LOAD_LOAD_REMOVE_MODULE_SEQUENCE) {
    KModuleHelpers::removeKernelModule();

    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());

    EXPECT_TRUE(KModuleHelpers::loadKernelModule());
    EXPECT_TRUE(KModuleHelpers::checkModuleLoaded());
    EXPECT_TRUE(KModuleHelpers::removeKernelModule());
    EXPECT_FALSE(KModuleHelpers::checkModuleLoaded());
}
