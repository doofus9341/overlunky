#pragma once

#include <memory>      // for shared_ptr
#include <mutex>       // for mutex
#include <sol/sol.hpp> // for environment, protected_function_result
#include <string_view> // for string_view

extern std::recursive_mutex global_lua_lock;

std::shared_ptr<sol::state> acquire_lua_vm(std::weak_ptr<class SoundManager> sound_manager = {});
sol::state& get_lua_vm(std::weak_ptr<class SoundManager> sound_manager = {});

sol::protected_function_result execute_lua(sol::environment& env, std::string_view code, bool pass = false);

void populate_lua_env(sol::environment& env);
void hide_unsafe_libraries(sol::environment& env);
void expose_unsafe_libraries(sol::environment& env);
void add_partial_safe_libraries(sol::environment& env);
bool check_safe_io_path(const std::string& filepath, const std::string& basepath);
