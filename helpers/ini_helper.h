#pragma once
#include <charconv>
#include "simpleini/SimpleIni.h"

template <class T>
inline bool ini_read_numeric(CSimpleIniA& ini, const char* section, const char* key, T& out)
{
    static_assert(std::is_integral<T>() || std::is_floating_point<T>(), "Invalid type");

    auto value = ini.GetValue(section, key);
    if (value)
    {
        T num;
        auto res = std::from_chars(value, value + strlen(value), num);
        if (res.ec == std::errc())
        {
            out = num;
            char debug_buf[128] = { 0 };
            sprintf_s(debug_buf, FSR_COMMON_LOG_PREFIX "%s: %f", key, static_cast<float>(num));
            OutputDebugStringA(debug_buf);
            return true;
        }
    }
    return false;
}

inline bool ini_read_bool(CSimpleIniA& ini, const char* section, const char* key, bool& out)
{
    auto result = false;
    auto value = ini.GetValue(section, key);
    if (value)
    {
        if (_stricmp(value, "true") == 0)
        {
            out = true;
            result = true;
        }
        else if (_stricmp(value, "false") == 0)
        {
            out = false;
            result = true;
        }

        if (result)
        {
            char debug_buf[128] = { 0 };
            sprintf_s(debug_buf, FSR_COMMON_LOG_PREFIX "%s is %d", key, out);
            OutputDebugStringA(debug_buf);
        }
    }
    return result;
}
