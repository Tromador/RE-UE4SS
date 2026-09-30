#include <Input/PlatformInputSource.hpp>
#if defined(_WIN32)
#include <Input/Platform/Win32AsyncInputSource.hpp>
#elif defined(__linux__)
#else
#error "Input initialization is not supported on this platform"
#endif
#include <Input/Platform/GLFW3InputSource.hpp>

namespace RC::Input
{
    auto Handler::init() -> void
    {
#if defined(_WIN32)
        register_input_source(std::make_shared<Win32AsyncInputSource>(L"ConsoleWindowClass", L"UnrealWindow"));
#elif defined(__linux__)
#else
#error "Input initialization is not supported on this platform"
#endif
        register_input_source(std::make_shared<GLFW3InputSource>());
    }
} // namespace RC::Input