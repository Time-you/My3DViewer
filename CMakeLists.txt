cmake_minimum_required(VERSION 3.10)

project(My3DViewer LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пошук бібліотек (встановлюються через vcpkg, див. vcpkg.json)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Glad: завантажувач функцій OpenGL 3.3, профіль compatibility
# (потрібен для glBegin/glEnd, glLightfv та інших функцій фіксованого конвеєра)
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# Додавання виконуваного файлу
add_executable(My3DViewer
    src/main.cpp
    src/Vertex.h
    src/ViewerWindow.h
    src/ViewerWindow.cpp
    src/OpenglRenderSystem.h
    src/OpenglRenderSystem.cpp
    src/GeometryPrimitives.h
    src/GeometryPrimitives.cpp
)

# Шлях до власних заголовкових файлів
target_include_directories(My3DViewer PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Підключення бібліотек
target_link_libraries(My3DViewer PRIVATE glfw glm::glm glad OpenGL::GL)

# GLFW_INCLUDE_NONE: заголовок GLFW не підключає системний gl.h,
# бо функції OpenGL у нас надає glad
target_compile_definitions(My3DViewer PRIVATE GLFW_INCLUDE_NONE)

# У Visual Studio робимо My3DViewer стартовим проєктом рішення
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT My3DViewer)
