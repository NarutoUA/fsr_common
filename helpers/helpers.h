#pragma once

#ifndef FSR_COMMON_LOG_PREFIX
#define FSR_COMMON_LOG_PREFIX "FSR_COMMON: "
#endif

#include "debug_helper.h"
#include "ini_helper.h"

#ifdef FSR_COMMON_API_D3D11
#include "d3d11_helper.h"
#endif

#ifdef FSR_COMMON_API_D3D12
#include "d3d12_helper.h"
#endif

#ifdef FSR_COMMON_API_VULKAN
#include "vulkan_helper.h"
#endif
