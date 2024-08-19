#include "editor_ui.h"
#include "imgui.h"
#include <imgui_internal.h>

void editor_ui::set_style()
{
    ImGuiStyle& mStyle = ImGui::GetStyle();

    mStyle.WindowMinSize = ImVec2(160, 20);
    mStyle.FramePadding = ImVec2(4, 2);
    mStyle.ItemSpacing = ImVec2(6, 2);
    mStyle.ItemInnerSpacing = ImVec2(6, 4);
    mStyle.Alpha = 0.95f;
    mStyle.WindowRounding = 4.0f;
    mStyle.FrameRounding = 2.0f;
    mStyle.IndentSpacing = 6.0f;
    mStyle.ItemInnerSpacing = ImVec2(2, 4);
    mStyle.ColumnsMinSpacing = 50.0f;
    mStyle.GrabMinSize = 14.0f;
    mStyle.GrabRounding = 16.0f;
    mStyle.ScrollbarSize = 12.0f;
    mStyle.ScrollbarRounding = 16.0f;

    ImGuiStyle& style = mStyle;
    style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.92f, 0.18f, 0.29f, 0.43f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.9f);
    //style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 0.73f);


}

void editor_ui::draw()
{
    ImVec2 size = ImGui::GetIO().DisplaySize;

    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiWindowFlags   window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoDocking;

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
    }

    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);   //must define dockspace every time and before dcobuilder!

    draw_main_menu();
    draw_content_manager();
    draw_hierarchy();
    draw_scene_view();
    draw_detail_panel();
    draw_test();
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

void editor_ui::draw_test()
{

    // 创建一个窗口
    ImGui::Begin("Custom Draw Example");

    // 获取当前窗口的绘图列表
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    // 获取窗口内光标的屏幕位置
    ImVec2 p = ImGui::GetCursorScreenPos();

    // 在指定位置绘制一个红色的圆圈
    ImVec2 center = ImVec2(p.x + 50, p.y + 50);  // 圆心位置
    float radius = 30.0f;                        // 圆的半径
    ImU32 color = IM_COL32(255, 0, 0, 255);      // 红色

    draw_list->AddCircleFilled(center, radius, color);

    // 完成绘制，结束窗口
    ImGui::End();
}
