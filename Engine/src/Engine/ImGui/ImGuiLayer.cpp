#include "engpch.h"
#include "ImGuiLayer.h"

#include <imgui.h>
#include <SDL.h>

#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_sdlrenderer2.h"

#include "Engine/Application.h"


namespace Engine {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		// Setup ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		// Setup ImGui flags
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		// Setup ImGui style
		ImGui::StyleColorsDark();

		// When viewports are enables we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}
		// Setup Platform/Renderer backends
		Application& app = Application::Get();
		SDL_Window* sdlWindow = static_cast<SDL_Window*>(app.GetWindow().GetNativeWindow());
		SDL_Renderer* sdlRenderer = static_cast<SDL_Renderer*>(app.GetWindow().GetRenderer().GetNativeRenderer());

		ImGui_ImplSDL2_InitForSDLRenderer(sdlWindow, sdlRenderer);
		ImGui_ImplSDLRenderer2_Init(sdlRenderer);
	}

	void ImGuiLayer::OnDetatch()
	{
		ImGui_ImplSDLRenderer2_Shutdown();
		ImGui_ImplSDL2_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void ImGuiLayer::Begin()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)SDL_GetTicks64();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) / 1000.0f : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplSDLRenderer2_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		//io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());
		SDL_Renderer* sdlRenderer = static_cast<SDL_Renderer*>(app.GetWindow().GetRenderer().GetNativeRenderer());

		//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		// Rendering
		ImGui::Render();
		//SDL_RenderSetScale(sdlRenderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
		//SDL_SetRenderDrawColor(sdlRenderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
		//SDL_RenderClear(sdlRenderer);
		ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), sdlRenderer);
		//SDL_RenderPresent(sdlRenderer);
	}

}