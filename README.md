# Лабораторная работа 4 — «ВУЗ»

Для сборки нужны CMake 3.16 или новее и компилятор с поддержкой C++17. Команды выполняются в папке с `CMakeLists.txt`.

```powershell
cmake -S . -B build
cmake --build build --config Debug
Push-Location build
ctest -C Debug --output-on-failure
Pop-Location
```

Для MinGW/Ninja запуск `.\build\Lab4.Console.exe`.

За один запуск программа выполняет один выбранный пункт меню. Для следующего запроса запусти её снова.
