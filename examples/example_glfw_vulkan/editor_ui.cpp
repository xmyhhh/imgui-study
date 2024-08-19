#include "editor_ui.h"
#include "imgui.h"
#include <imgui_internal.h>

void editor_ui::draw()
{
    ImVec2 size = ImGui::GetIO().DisplaySize;

    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiWindowFlags   window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus;

    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(main_viewport->WorkPos, ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(size.x, size.y - status_bar_height), ImGuiCond_Always);

    auto ctx = ImGui::GetCurrentContext()->NextWindowData;
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; // 禁用 ImGui 的 .ini 文件保存

    ImGui::Begin("Main", nullptr, window_flags);

    ImGuiID dockspace_id = ImGui::GetID("DockSpace");
    // Set up initial docking layout
    if (ImGui::DockBuilderGetNode(dockspace_id) == nullptr) // Ensure only build once
    {
        ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
        ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetIO().DisplaySize);

        ImGuiID dock_main_id = dockspace_id;
        ImGuiID dock_id_left = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Left, 0.2f, nullptr, &dock_main_id);
        ImGuiID dock_id_right = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Right, 0.2f, nullptr, &dock_main_id);
        ImGuiID dock_id_bottom = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Down, 0.3f, nullptr, &dock_main_id);

        ImGui::DockBuilderDockWindow("Hierarchy", dock_id_left);
        ImGui::DockBuilderDockWindow("Details", dock_id_right);
        ImGui::DockBuilderDockWindow("Content", dock_id_bottom);
        ImGui::DockBuilderDockWindow("Scene", dock_main_id);

        ImGui::DockBuilderFinish(dockspace_id);

        //ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        //ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);


        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    draw_main_menu();
    draw_content_manager();
    draw_hierarchy();
    draw_scene_view();
    draw_detail_panel();
    draw_status();

    if (ShowMetrics) { ImGui::ShowMetricsWindow(&ShowMetrics); }
    if (ShowDebugLog) { ImGui::ShowDebugLogWindow(&ShowDebugLog); }

    ImGui::End();

}

void editor_ui::draw_main_menu()
{
    // Create a menu bar
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New")) {}
            if (ImGui::MenuItem("Open")) {}
            if (ImGui::MenuItem("Save")) {}
            ImGui::Separator();
            if (ImGui::MenuItem("Exit")) {}
            ImGui::EndMenu();
        }


        if (ImGui::BeginMenu("Tools"))
        {

            const bool has_debug_tools = true;

            ImGui::MenuItem("Metrics/Debugger", NULL, &ShowMetrics, has_debug_tools);
            ImGui::MenuItem("Debug Log", NULL, &ShowDebugLog, has_debug_tools);

            ImGui::EndMenu();
        }

        ImGuiWindow* window = ImGui::GetCurrentWindow();
        ImRect bar_rect = window->MenuBarRect();
        main_menu_height = bar_rect.Max.y - bar_rect.Min.y;

        ImGui::EndMenuBar();
    }
}

void editor_ui::draw_hierarchy()
{
    ImGuiWindowFlags  window_flags = ImGuiWindowFlags_NoCollapse | ImGuiConfigFlags_NoMouseCursorChange;
    //static ImGuiWindowClass hierarchyWindowClass;
    //hierarchyWindowClass.ClassId = ImGui::GetID("HierarchyClass");
    //ImGui::SetNextWindowClass(&hierarchyWindowClass);

    ImGui::Begin("Hierarchy", nullptr, window_flags);                          // Create a window called "Hello, world!" and append into it.
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::End();
}

void editor_ui::draw_content_manager()
{
    ImGuiWindowFlags  window_flags = ImGuiWindowFlags_NoCollapse | ImGuiConfigFlags_NoMouseCursorChange;

    ImGui::Begin("Content", nullptr, window_flags);                          // Create a window called "Hello, world!" and append into it.
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::End();
}

void editor_ui::draw_scene_view()
{
    ImGuiWindowFlags  window_flags = ImGuiWindowFlags_NoCollapse | ImGuiConfigFlags_NoMouseCursorChange;

    //static ImGuiWindowClass sceneWindowClass;
    //sceneWindowClass.ClassId = ImGui::GetID("SceneClass");
    //ImGui::SetNextWindowClass(&sceneWindowClass);
    ImGui::Begin("Scene", nullptr, window_flags);                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)

    ImGui::End();
}

void editor_ui::draw_detail_panel()
{
    ImGuiWindowFlags  window_flags = ImGuiWindowFlags_NoCollapse | ImGuiConfigFlags_NoMouseCursorChange;

    ImGui::Begin("Details", nullptr, window_flags);                          // Create a window called "Hello, world!" and append into it.
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::End();
}

void editor_ui::draw_status()
{
    auto size = ImGui::GetIO().DisplaySize;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize;

    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowSize(ImVec2(size.x, status_bar_height), ImGuiCond_Always);
    ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + size.y - status_bar_height), ImGuiCond_Always);
    ImGui::SetNextWindowViewport(main_viewport->ID);
    ImGui::Begin("statusbar", nullptr, window_flags);

    ImGui::Text("Frame: %.5f ms", 1000.0f / (float)ImGui::GetIO().Framerate);
    ImGui::End();

}
