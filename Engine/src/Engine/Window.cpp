#include "engpch.h"
#include "Window.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

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
        m_SDLWindow = SDL_CreateWindow(
            m_Data.Title.c_str(), 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED, 
            m_Data.Width, 
            m_Data.Height, 
            SDL_WINDOW_RESIZABLE);

        m_Renderer = std::make_unique<Renderer>(m_SDLWindow);

        SetVSync(true);
    }

    void Window::OnUpdate()
    {
        //m_Renderer->Clear();

        //m_Renderer->Present();

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_QUIT:
            {
                WindowClosedEvent event;
                m_Data.EventCallback(event);
                break;
            }
            case SDL_WINDOWEVENT:
            {
                if (e.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                    auto newWidth = e.window.data1;
                    auto newHeight = e.window.data2;
                    if (newWidth != m_Data.Width || newHeight != m_Data.Height) 
                    { 
                    m_Data.Width = newWidth;
                    m_Data.Height = newHeight;

                    WindowResizeEvent event(newWidth, newHeight);
                    m_Data.EventCallback(event);
                    }
                }
                break;
            }
            case SDL_KEYDOWN:
            {
                int repeatCount = e.key.repeat;
                auto keyCode = e.key.keysym.scancode;

                KeyPressedEvent event(keyCode, repeatCount);
                m_Data.EventCallback(event);
                break;
            }
            case SDL_KEYUP:
            {
                auto keyCode = e.key.keysym.scancode;

                KeyReleasedEvent event(keyCode);
                m_Data.EventCallback(event);
                break;
            }
            case SDL_MOUSEMOTION:
            {
                float newX = (float)e.motion.x;
                float newY = (float)e.motion.y;

                MouseMovedEvent event(newX, newY);
                m_Data.EventCallback(event);
                break;
            }
            case SDL_MOUSEWHEEL:
            {
                float xOffset = (float)e.wheel.x;
                float yOffset = (float)e.wheel.y;

                MouseScrolledEvent event(xOffset, yOffset);
                m_Data.EventCallback(event);
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                int button = (int)e.button.button;
                MouseButtonPressedEvent event(button);
                m_Data.EventCallback(event);
                break;
            }
            case SDL_MOUSEBUTTONUP:
            {
                int button = (int)e.button.button;
                MouseButtonReleasedEvent event(button);
                m_Data.EventCallback(event);
                break;
            }
            default:
                break;
            }
        }
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
        SDL_Quit();
    }
}