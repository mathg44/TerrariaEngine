#include "engpch.h"
#include "Window.h"

namespace Engine {

    static bool s_SDLInitialized = false;

    Window* Window::Create(const WindowProps& props)
    {
        return new Window(props);
    }

    Window::Window(const WindowProps& props)
    {
        Init(props);
    }

    Window::~Window()
    {
        ShutDown();
    }

    void Window::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        ENG_CORE_INFO("Creating Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_SDLInitialized)
        {
            int success = SDL_Init(SDL_INIT_VIDEO);
            ENG_CORE_ASSERT(success, "Could not initialize SDL!");

            s_SDLInitialized = true;
        }
        m_SDLWindow = SDL_CreateWindow(m_Data.Title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Data.Width, m_Data.Height, 0);
        SetVSync(true);
    }

    void Window::OnUpdate()
    {
    }

    void Window::SetVSync(bool enabled)
    {
        if (enabled)
        {
            SDL_GL_SetSwapInterval(1);
        }
        else
        {
            SDL_GL_SetSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }

    bool Window::IsVSync() const
    {
        return m_Data.VSync;
    }

    void Window::ShutDown()
    {
        SDL_DestroyWindow(m_SDLWindow);
    }
}