# My3DViewer

Цей проєкт реалізує 3D-в'ювер, який може завантажувати та відображати файли STL.

Автор: Іванський Володимир, група 41-IT

## Залежності

Усі залежності встановлюються через пакетний менеджер vcpkg (manifest-режим, файл `vcpkg.json`):

- [GLM](https://github.com/g-truc/glm) — векторна та матрична математика (header-only)
- [GLFW](https://www.glfw.org/) — вікна, введення, контекст OpenGL
- [Glad](https://github.com/Dav1dde/glad) — завантажувач функцій OpenGL

## Збірка

```
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=<шлях до vcpkg>/scripts/buildsystems/vcpkg.cmake ..
cmake --build .
```

У Visual Studio: **Файл → Відкрити → Папка** з проєктом; пресет `Default (vcpkg)` з `CMakePresets.json` підключає vcpkg автоматично.

## Запуск

Програма виводить у консоль вектор GLM та версію OpenGL і відкриває вікно. Вихід — клавіша Esc або закриття вікна.

## Структура

```
My3DViewer/
├── CMakeLists.txt
├── CMakePresets.json
├── vcpkg.json
├── README.md
├── .gitignore
└── src/
    └── main.cpp
```
