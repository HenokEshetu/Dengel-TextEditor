#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <string>
#include <mutex>

namespace dengel_ui
{

struct WindowInfo
{
    std::string Title;
    int Width;
    int Height;

    WindowInfo(std::string title, int w, int h)
        : Title(std::move(title)), Width(w), Height(h) {}

    WindowInfo(WindowInfo&&) = default;
    WindowInfo& operator=(WindowInfo&&) = default;

    WindowInfo(const WindowInfo&) = delete;
    WindowInfo& operator=(const WindowInfo&) = delete;
};

class Window
{
public:
    explicit Window(const WindowInfo& winInfo);
    ~Window();

    void Show();
    void Hide();
    void SetWinInfo(WindowInfo&& winInfo);
    std::shared_ptr<WindowInfo> GetWinInfo() const;

private:
    void Init();

    std::shared_ptr<WindowInfo> m_WinInfo;
    SDL_Window* m_Window = nullptr;
    mutable std::mutex m_WinInfoMutex;
};

} // namespace dengel_ui
