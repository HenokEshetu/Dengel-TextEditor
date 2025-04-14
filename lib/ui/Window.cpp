#include "Window.hpp"

#include <stdexcept>
#include <print>

namespace dengel_ui
{

Window::Window(const WindowInfo& winInfo)
    : m_WinInfo(std::make_shared<WindowInfo>(winInfo.Title, winInfo.Width, winInfo.Height))
{
    Init();
}

Window::~Window()
{
    if (m_Window)
        SDL_DestroyWindow(m_Window);
}

void Window::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
        throw std::runtime_error("Failed to initialize SDL");

    if (m_Window)
    {
        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;
    }

    m_Window = SDL_CreateWindow(
        m_WinInfo->Title.c_str(),
        m_WinInfo->Width,
        m_WinInfo->Height,
        // NULL
        SDL_WINDOW_RESIZABLE
    );

    if (!m_Window)
        std::println("Error while creating window: {}", SDL_GetError());

    // Show();
}

void Window::Show()
{
    if (m_Window)
    {
        auto renderer = SDL_CreateRenderer(m_Window, NULL);
        auto running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_EVENT_QUIT)
                    running = false;
                if (event.key.key == SDLK_ESCAPE)
                    running = false;
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

void Window::Hide()
{
    if (m_Window)
        SDL_HideWindow(m_Window);
}

void Window::SetWinInfo(WindowInfo&& winInfo)
{
    std::lock_guard<std::mutex> lock(m_WinInfoMutex);
    m_WinInfo = std::make_shared<WindowInfo>(std::move(winInfo));

    if (m_Window)
    {
        SDL_SetWindowTitle(m_Window, m_WinInfo->Title.c_str());
        SDL_SetWindowSize(m_Window, m_WinInfo->Width, m_WinInfo->Height);
    }
}

std::shared_ptr<WindowInfo> Window::GetWinInfo() const
{
    std::lock_guard<std::mutex> lock(m_WinInfoMutex);
    return m_WinInfo;
}

} // namespace dengel_ui
