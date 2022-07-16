#ifndef FIXTURES_H
#define FIXTURES_H

#include <kmodulehelpers.h>
#include <gtest/gtest.h>

class KmodTest : public ::testing::Test
{
protected:
    void SetUp() override {
        KModuleHelpers::removeKernelModule();
    }
    void TearDown() override {
        KModuleHelpers::removeKernelModule();
    }
};

class KmodTestModuleLoaded : public KmodTest
{
protected:
    void SetUp() override {
        KModuleHelpers::removeKernelModule();
        KModuleHelpers::loadKernelModule();
    }
};

#endif // FIXTURES_H
