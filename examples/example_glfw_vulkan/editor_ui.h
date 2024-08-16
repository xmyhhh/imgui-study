#pragma once
class editor_ui
{


public:
    void draw();


private:
    void draw_main_menu();

    void draw_hierarchy();

    void draw_content_manager();

    void draw_scene_view();

    void draw_detail_panel();

    void draw_status();
private:
    bool ShowMetrics = false;
    bool ShowDebugLog = false;

    int main_menu_height;
    int status_bar_height = 25;
};

