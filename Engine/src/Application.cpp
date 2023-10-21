#include "PCH.hpp"

#include "Amethyst/Application.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <implot.h>

using namespace Amethyst;

Application::Application(ApplicationSettings applicationSettings) : mApplicationSettings(std::move(applicationSettings)) {}

void Application::PushLayer(std::unique_ptr<Layer> layer) {
    mLayerStack.Push(std::move(layer));
}

void Application::PopLayer() {
    mLayerStack.Pop();
}

void Application::Run() {
    if (!glfwInit()) {
        std::exit(EXIT_FAILURE);
    }

#if defined(__APPLE__)
    const char *glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    GLFWwindow *window = glfwCreateWindow(mApplicationSettings.width, mApplicationSettings.height, mApplicationSettings.title.c_str(), nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();

    ImGuiStyle &style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    const double fixedDeltaTime = mApplicationSettings.fixedDeltaTime;
    const double maxDeltaTime = mApplicationSettings.maxDeltaTime;
    const double timeScale = mApplicationSettings.timeScale;

    double prevTime = 0.0;
    double accumulator = 0.0;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        const double currTime = glfwGetTime();
        const double deltaTime = currTime - prevTime;
        prevTime = currTime;
        accumulator += timeScale * glm::min(deltaTime, maxDeltaTime);
        while (accumulator > fixedDeltaTime) {
            mLayerStack.FixedUpdate(fixedDeltaTime);
            accumulator -= fixedDeltaTime;
        }

        int display_w;
        int display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        mLayerStack.Update(deltaTime);
        mLayerStack.LateUpdate(deltaTime);

        ImGui::Begin("Engine");
        ImGui::Text("deltaTime      : %.5lf", deltaTime);
        ImGui::Text("fixedDeltaTime : %.5lf", fixedDeltaTime);
        ImGui::Text("maxDeltaTime   : %.5lf", maxDeltaTime);
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(window);
    }

    mLayerStack.Clear();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImPlot::DestroyContext();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
