# My3DViewer

Цей проєкт реалізує 3D-в'ювер, який може завантажувати та відображати файли STL.

Автор: Іванський Володимир, група 41-IT

## Залежності

GLM та GLFW встановлюються через пакетний менеджер vcpkg (manifest-режим, файл `vcpkg.json`), Glad лежить у репозиторії:

- [GLM](https://github.com/g-truc/glm) — векторна та матрична математика (header-only)
- [GLFW](https://www.glfw.org/) — вікна, введення, контекст OpenGL
- [Glad](https://github.com/Dav1dde/glad) — завантажувач функцій OpenGL 3.3 (профіль compatibility, файли в `external/glad`)

## Збірка

```
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=<шлях до vcpkg>/scripts/buildsystems/vcpkg.cmake ..
cmake --build .
```

У Visual Studio: **Файл → Відкрити → Папка** з проєктом; пресет `Default (vcpkg)` з `CMakePresets.json` підключає vcpkg автоматично.

## Керування

| Клавіша | Дія |
|---|---|
| ↑ / ↓ | зсунути фігуру вгору / вниз |
| ← / → | зсунути фігуру вліво / вправо |
| Space | перемкнути куб / піраміду |

## Структура

```
My3DViewer/
├── CMakeLists.txt
├── CMakePresets.json
├── vcpkg.json
├── README.md
├── .gitignore
├── external/glad/          # завантажувач OpenGL
│   ├── include/glad/glad.h
│   ├── include/KHR/khrplatform.h
│   └── src/glad.c
└── src/
    ├── main.cpp                # головний цикл, камера, світло, керування
    ├── ViewerWindow.h/.cpp     # вікно GLFW та обробка подій
    ├── OpenglRenderSystem.h/.cpp # рендеринг OpenGL
    ├── GeometryPrimitives.h/.cpp # вершини куба та піраміди
    └── Vertex.h                # структура вершини
```
