// Vita3K emulator project
// Copyright (C) 2018 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <dialog/state.h>

#include <imgui.h>
#include <imgui_memory_editor.h>

namespace gui {

enum SelectorState {
    SELECT_APP
};

enum SortState {
    NOT_SORTED,
    ASCENDANT,
    DESCENDANT
};

struct Game {
    std::string app_ver;
    std::string title;
    std::string title_id;
};

struct GamesSelector {
    std::vector<Game> games;
    std::string selected_title_id;
    bool is_game_list_sorted{ false };
    SortState title_id_sort_state = NOT_SORTED;
    SortState app_ver_sort_state = NOT_SORTED;
    SortState title_sort_state = NOT_SORTED;
    SelectorState state = SELECT_APP;
};

struct DebugMenuState {
    bool threads_dialog = false;
    bool thread_details_dialog = false;
    bool semaphores_dialog = false;
    bool condvars_dialog = false;
    bool lwcondvars_dialog = false;
    bool mutexes_dialog = false;
    bool lwmutexes_dialog = false;
    bool eventflags_dialog = false;
    bool allocations_dialog = false;
    bool memory_editor_dialog = false;
    bool disassembly_dialog = false;
};

struct OptimisationMenuState {
    bool texture_cache = true;
};

struct HelpMenuState {
    bool controls_dialog = false;
    bool about_dialog = false;
};

struct State {
    bool renderer_focused = true;
    DebugMenuState debug_menu;
    OptimisationMenuState optimisation_menu;
    HelpMenuState help_menu;
    DialogState common_dialog;
    GamesSelector game_selector;

    MemoryEditor memory_editor;
    size_t memory_editor_start = 0;
    size_t memory_editor_count = 0;

    std::string disassembly_arch = "THUMB";
    char disassembly_address[9] = "00000000";
    char disassembly_count[5] = "100";
    std::vector<std::string> disassembly;

    SceUID thread_watch_index = -1;

    // imgui
    ImFont *normal_font{};
    ImFont *monospaced_font{};
    std::vector<char> font_data;
};

} // namespace gui
