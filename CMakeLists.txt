cmake_minimum_required(VERSION 3.10)

project(My3DViewer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пошук бібліотек (встановлюються через vcpkg, див. vcpkg.json)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

# Додавання виконуваного файлу
add_executable(My3DViewer src/main.cpp)

# Підключення бібліотек.
# GLM є header-only, тому окремо лінкувати її не потрібно.
target_link_libraries(My3DViewer PRIVATE glfw glad::glad)
